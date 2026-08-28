import json
import sys
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

port = int(sys.argv[1])
token = sys.argv[2]

class Handler(BaseHTTPRequestHandler):
    def log_message(self, *_):
        pass

    def reply(self, status, value=None, headers=None):
        body = b'' if value is None else json.dumps(value).encode()
        self.send_response(status)
        self.send_header('Content-Type', 'application/json')
        for name, item in (headers or {}).items():
            self.send_header(name, item)
        self.send_header('Content-Length', str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        self.reply(200, {'ok': True}) if self.path == '/health' else self.reply(405, {'error': 'no server events'})

    def do_DELETE(self):
        self.reply(200, {'ok': True})

    def do_POST(self):
        if self.path != '/mcp':
            return self.reply(404, {'error': 'not found'})
        if self.headers.get('Authorization') != f'Bearer {token}' or self.headers.get('X-Test-Server') != 'python':
            return self.reply(401, {'error': 'unauthorized'})
        message = json.loads(self.rfile.read(int(self.headers.get('Content-Length', '0'))))
        if 'id' not in message:
            return self.reply(202)
        method = message.get('method')
        if method == 'initialize':
            result = {'protocolVersion': '2025-11-25', 'capabilities': {'tools': {}},
                      'serverInfo': {'name': 'python-independent', 'version': '1'}}
        elif method == 'tools/list':
            result = {'tools': [{'name': 'python_echo', 'description': 'Echo text in Python',
                                 'inputSchema': {'type': 'object', 'properties': {'text': {'type': 'string'}}, 'required': ['text']}}]}
        elif method == 'tools/call':
            text = message.get('params', {}).get('arguments', {}).get('text', '')
            result = {'content': [{'type': 'text', 'text': f'python:{text}'}], 'isError': False}
        else:
            return self.reply(200, {'jsonrpc': '2.0', 'id': message['id'],
                                    'error': {'code': -32601, 'message': 'unknown'}})
        self.reply(200, {'jsonrpc': '2.0', 'id': message['id'], 'result': result}, {'MCP-Session-Id': 'python-session'})

ThreadingHTTPServer(('127.0.0.1', port), Handler).serve_forever()
