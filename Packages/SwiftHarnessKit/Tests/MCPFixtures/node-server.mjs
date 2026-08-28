import http from 'node:http';

const port = Number(process.argv[2]);
const token = process.argv[3];
const sessionID = 'node-session';

const send = (response, status, body, headers = {}) => {
  response.writeHead(status, { 'Content-Type': 'application/json', ...headers });
  response.end(body === undefined ? '' : JSON.stringify(body));
};

http.createServer((request, response) => {
  if (request.method === 'GET' && request.url === '/health') return send(response, 200, { ok: true });
  if (request.url !== '/mcp') return send(response, 404, { error: 'not found' });
  if (request.method === 'GET') return send(response, 405, { error: 'no server events' });
  if (request.method === 'DELETE') return send(response, 200, { ok: true });
  if (request.method !== 'POST') return send(response, 405, { error: 'method' });
  if (request.headers.authorization !== `Bearer ${token}` || request.headers['x-test-server'] !== 'node') {
    return send(response, 401, { error: 'unauthorized' });
  }
  let data = '';
  request.setEncoding('utf8');
  request.on('data', chunk => data += chunk);
  request.on('end', async () => {
    const message = JSON.parse(data);
    if (!Object.hasOwn(message, 'id')) return send(response, 202);
    let result;
    if (message.method === 'initialize') {
      result = {
        protocolVersion: '2025-11-25', capabilities: { tools: {} },
        serverInfo: { name: 'node-independent', version: '1' }
      };
    } else if (message.method === 'tools/list') {
      result = { tools: [
        { name: 'node_add', description: 'Add values in Node', inputSchema: {
          type: 'object', properties: { a: { type: 'integer' }, b: { type: 'integer' } }, required: ['a', 'b']
        }},
        { name: 'node_wait', description: 'Wait for cancellation', inputSchema: { type: 'object', properties: {} } }
      ] };
    } else if (message.method === 'tools/call') {
      if (message.params.name === 'node_wait') {
        await new Promise(resolve => setTimeout(resolve, 5000));
        result = { content: [{ type: 'text', text: 'late' }], isError: false };
      } else {
        const { a = 0, b = 0 } = message.params.arguments ?? {};
        result = { content: [{ type: 'text', text: String(a + b) }], isError: false };
      }
    } else {
      return send(response, 200, { jsonrpc: '2.0', id: message.id, error: { code: -32601, message: 'unknown' } });
    }
    send(response, 200, { jsonrpc: '2.0', id: message.id, result }, { 'MCP-Session-Id': sessionID });
  });
}).listen(port, '127.0.0.1', () => process.stdout.write('ready\n'));
