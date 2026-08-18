// Exercises the fetch() polyfill against tests/mock-deepseek.mjs plus a
// throwaway local server for redirects/gzip. Run with:
//   DSH_FORCE_FETCH_POLYFILL=1 node --require <fetch-polyfill.js> tests/fetch-polyfill-test.mjs <mockPort>
import http from 'node:http';
import zlib from 'node:zlib';
import assert from 'node:assert/strict';

const mockPort = Number(process.argv[2] ?? 3198);
const failures = [];
const t = async (name, fn) => { try { await fn(); console.log(`ok   ${name}`); } catch (e) { failures.push(name); console.log(`FAIL ${name}: ${e.message}`); } };

// A helper server: /redir -> 302 -> /final ; /gzip -> gzip body ; /post echoes body ; /slow streams slowly
const helper = http.createServer((req, res) => {
  if (req.url === '/redir') { res.writeHead(302, { location: '/final' }); res.end(); return; }
  if (req.url === '/final') { res.writeHead(200, { 'content-type': 'text/plain' }); res.end('final'); return; }
  if (req.url === '/gzip') { res.writeHead(200, { 'content-encoding': 'gzip', 'content-type': 'text/plain' }); res.end(zlib.gzipSync('gzipped-body')); return; }
  if (req.url === '/post') { let b = ''; req.on('data', c => b += c); req.on('end', () => { res.writeHead(200, { 'content-type': req.headers['content-type'] || '' }); res.end(b); }); return; }
  if (req.url === '/slow') { res.writeHead(200); let n = 0; const iv = setInterval(() => { res.write('x'); if (++n > 50) { clearInterval(iv); res.end(); } }, 50); return; }
  if (req.url === '/nobody') { res.writeHead(204); res.end(); return; }
  res.writeHead(404); res.end();
});
await new Promise(r => helper.listen(0, '127.0.0.1', r));
const hp = helper.address().port;
const H = `http://127.0.0.1:${hp}`;

await t('polyfill is installed', () => {
  assert.equal(typeof fetch, 'function');
  assert.equal(fetch.name, 'fetch');
});
await t('SSE stream arrives in multiple chunks with a web ReadableStream body', async () => {
  const r = await fetch(`http://127.0.0.1:${mockPort}/chat/completions`, { method: 'POST', headers: { 'content-type': 'application/json' }, body: JSON.stringify({ stream: true, model: 'm' }) });
  assert.equal(r.status, 200);
  assert.ok(r instanceof Response);
  assert.equal(r.headers.get('content-type'), 'text/event-stream');
  assert.ok(r.body instanceof ReadableStream);
  const reader = r.body.getReader(); const dec = new TextDecoder(); let chunks = 0, text = '';
  for (;;) { const { done, value } = await reader.read(); if (done) break; chunks++; text += dec.decode(value, { stream: true }); }
  assert.ok(chunks >= 3, `expected streaming, got ${chunks} chunk(s)`);
  assert.ok(text.includes('MOCK-REPLY-7f3a') && text.includes('[DONE]'));
});
await t('json() and url/redirected on a plain GET', async () => {
  const r = await fetch(`http://127.0.0.1:${mockPort}/models`);
  assert.equal(r.url, `http://127.0.0.1:${mockPort}/models`);
  assert.equal(r.redirected, false);
  const j = await r.json();
  assert.equal(j.data[0].id, 'deepseek-chat');
});
await t('follows redirects and reports redirected/url', async () => {
  const r = await fetch(`${H}/redir`);
  assert.equal(r.status, 200);
  assert.equal(await r.text(), 'final');
  assert.equal(r.redirected, true);
  assert.equal(r.url, `${H}/final`);
});
await t('decodes gzip', async () => {
  const r = await fetch(`${H}/gzip`);
  assert.equal(await r.text(), 'gzipped-body');
});
await t('posts string / URLSearchParams / Uint8Array bodies', async () => {
  assert.equal(await (await fetch(`${H}/post`, { method: 'POST', body: 'hello' })).text(), 'hello');
  const r2 = await fetch(`${H}/post`, { method: 'POST', body: new URLSearchParams({ a: '1', b: 'x y' }) });
  assert.equal(await r2.text(), 'a=1&b=x+y');
  assert.ok(r2.headers.get('content-type').startsWith('application/x-www-form-urlencoded'));
  assert.equal(await (await fetch(`${H}/post`, { method: 'POST', body: new Uint8Array([104, 105]) })).text(), 'hi');
});
await t('accepts a Request object', async () => {
  const req = new Request(`${H}/post`, { method: 'POST', body: 'via-request', headers: { 'x-a': 'b' } });
  assert.equal(await (await fetch(req)).text(), 'via-request');
});
await t('AbortSignal aborts an in-flight response', async () => {
  const ac = new AbortController();
  const r = await fetch(`${H}/slow`, { signal: ac.signal });
  setTimeout(() => ac.abort(), 60);
  await assert.rejects(r.text(), e => e.name === 'AbortError');
});
await t('pre-aborted signal rejects immediately', async () => {
  const ac = new AbortController(); ac.abort();
  await assert.rejects(fetch(`${H}/final`, { signal: ac.signal }), e => e.name === 'AbortError');
});
await t('204 has null body', async () => {
  const r = await fetch(`${H}/nobody`);
  assert.equal(r.status, 204);
  assert.equal(r.body, null);
});
await t('connection refused -> TypeError("fetch failed")', async () => {
  await assert.rejects(fetch('http://127.0.0.1:1/'), e => e instanceof TypeError && e.message === 'fetch failed');
});

helper.close();
if (failures.length) { console.log(`FETCH POLYFILL FAILED: ${failures.join(', ')}`); process.exit(1); }
console.log('FETCH POLYFILL OK');
