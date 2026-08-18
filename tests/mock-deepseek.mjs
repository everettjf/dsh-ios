// Minimal OpenAI/DeepSeek-compatible chat completions server used by the
// rootfs tests: streams a fixed reply as SSE so the guest's undici fetch path
// (WebAssembly-less llhttp polyfill) is exercised end to end.
//
// Usage: node tests/mock-deepseek.mjs [port]   (default 3199)
import http from 'node:http';

const port = Number(process.argv[2] ?? 3199);
const REPLY = 'MOCK-REPLY-7f3a: hello from the mock DeepSeek server';

const server = http.createServer((req, res) => {
  let body = '';
  req.on('data', (c) => (body += c));
  req.on('end', () => {
    if (req.method === 'GET' && req.url.endsWith('/models')) {
      res.writeHead(200, { 'content-type': 'application/json' });
      res.end(JSON.stringify({ object: 'list', data: [{ id: 'deepseek-chat', object: 'model' }] }));
      return;
    }
    if (req.method !== 'POST' || !req.url.includes('/chat/completions')) {
      res.writeHead(404); res.end('not found'); return;
    }
    let payload = {};
    try { payload = JSON.parse(body || '{}'); } catch { /* ignore */ }
    const id = 'chatcmpl-mock';
    const model = payload.model ?? 'deepseek-chat';
    const chunk = (delta, finish = null) => `data: ${JSON.stringify({
      id, object: 'chat.completion.chunk', created: 1700000000, model,
      choices: [{ index: 0, delta, finish_reason: finish }],
    })}\n\n`;
    if (payload.stream === false) {
      res.writeHead(200, { 'content-type': 'application/json' });
      res.end(JSON.stringify({
        id, object: 'chat.completion', created: 1700000000, model,
        choices: [{ index: 0, message: { role: 'assistant', content: REPLY }, finish_reason: 'stop' }],
        usage: { prompt_tokens: 10, completion_tokens: 12, total_tokens: 22 },
      }));
      return;
    }
    res.writeHead(200, {
      'content-type': 'text/event-stream',
      'cache-control': 'no-cache',
      connection: 'keep-alive',
    });
    res.write(chunk({ role: 'assistant', content: '' }));
    const words = REPLY.split(' ');
    let i = 0;
    const timer = setInterval(() => {
      if (i < words.length) {
        res.write(chunk({ content: (i ? ' ' : '') + words[i++] }));
      } else {
        clearInterval(timer);
        res.write(chunk({}, 'stop'));
        res.write(`data: ${JSON.stringify({ id, object: 'chat.completion.chunk', created: 1700000000, model, choices: [], usage: { prompt_tokens: 10, completion_tokens: 12, total_tokens: 22 } })}\n\n`);
        res.write('data: [DONE]\n\n');
        res.end();
      }
    }, 20);
  });
});

server.listen(port, '127.0.0.1', () => {
  console.log(`mock-deepseek listening on http://127.0.0.1:${port}`);
});
