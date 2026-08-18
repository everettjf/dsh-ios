"use strict";
// fetch() for --jitless Node.js on iSH ARM64.
//
// Node's built-in fetch is undici, whose HTTP parser is a WebAssembly module
// that cannot run without a JIT. This replaces globalThis.fetch with an
// implementation over node:http/https that returns *real* web `Response`
// objects (Node's Response/Headers/ReadableStream classes are plain JS and
// work fine), so consumers that stream `response.body` — server-sent events
// from LLM APIs, downloads — behave like they do on stock Node.
//
// Everything is required lazily: on iSH the eager import of http/https/zlib
// costs ~0.5s per node start (--no-lazy compiles every module up front).
//
// Supported: string/URL/Request input, method/headers/body (string, Buffer,
// ArrayBuffer(View), URLSearchParams, Blob, ReadableStream, async iterables),
// AbortSignal, redirects (max 20), gzip/deflate/br decoding, streaming body,
// `url`/`redirected` on the returned Response.
if (typeof globalThis.WebAssembly === "undefined" ||
    process.env.DSH_FORCE_FETCH_POLYFILL === "1") {
  let _impl = null;
  const MAX_REDIRECTS = 20;

  function _lazy() {
    if (_impl) return _impl;
    const http = require("http");
    const https = require("https");
    const zlib = require("zlib");
    const { Readable } = require("stream");
    const { URL: U } = require("url");
    const keepAliveHttp = new http.Agent({ keepAlive: true });
    const keepAliveHttps = new https.Agent({ keepAlive: true });

    function abortError(signal) {
      const reason = signal && signal.reason;
      if (reason instanceof Error) return reason;
      const e = new Error("This operation was aborted");
      e.name = "AbortError";
      e.code = 20;
      return e;
    }

    function fetchError(cause) {
      const e = new TypeError("fetch failed");
      e.cause = cause;
      return e;
    }

    // Normalise every accepted body shape into { stream, contentType, length }.
    async function normaliseBody(body) {
      if (body == null) return null;
      if (typeof body === "string") {
        const buf = Buffer.from(body, "utf8");
        return { stream: Readable.from([buf]), contentType: "text/plain;charset=UTF-8", length: buf.length };
      }
      if (body instanceof URLSearchParams) {
        const buf = Buffer.from(body.toString(), "utf8");
        return { stream: Readable.from([buf]), contentType: "application/x-www-form-urlencoded;charset=UTF-8", length: buf.length };
      }
      if (Buffer.isBuffer(body)) return { stream: Readable.from([body]), contentType: null, length: body.length };
      if (body instanceof ArrayBuffer) { const b = Buffer.from(body); return { stream: Readable.from([b]), contentType: null, length: b.length }; }
      if (ArrayBuffer.isView(body)) { const b = Buffer.from(body.buffer, body.byteOffset, body.byteLength); return { stream: Readable.from([b]), contentType: null, length: b.length }; }
      if (typeof Blob !== "undefined" && body instanceof Blob) {
        const b = Buffer.from(await body.arrayBuffer());
        return { stream: Readable.from([b]), contentType: body.type || null, length: b.length };
      }
      if (typeof ReadableStream !== "undefined" && body instanceof ReadableStream) {
        return { stream: Readable.fromWeb(body), contentType: null, length: null };
      }
      if (body instanceof Readable) return { stream: body, contentType: null, length: null };
      if (typeof body[Symbol.asyncIterator] === "function" || typeof body[Symbol.iterator] === "function") {
        return { stream: Readable.from(body), contentType: null, length: null };
      }
      if (typeof body.toString === "function") {
        const buf = Buffer.from(String(body), "utf8");
        return { stream: Readable.from([buf]), contentType: "text/plain;charset=UTF-8", length: buf.length };
      }
      throw new TypeError("Unsupported fetch body type");
    }

    function collectHeaders(input, init) {
      const h = new Headers();
      if (input && typeof input === "object" && input.headers && typeof input.headers.forEach === "function") {
        input.headers.forEach((v, k) => h.append(k, v));
      }
      if (init && init.headers) {
        const ih = init.headers instanceof Headers ? init.headers : new Headers(init.headers);
        // init headers replace input headers of the same name (spec: Request ctor)
        for (const [k] of ih) h.delete(k);
        ih.forEach((v, k) => h.append(k, v));
      }
      return h;
    }

    function toNodeHeaders(h) {
      const out = {};
      h.forEach((v, k) => {
        if (k === "set-cookie") { (out[k] = out[k] || []).push(v); return; }
        out[k] = out[k] === undefined ? v : out[k] + ", " + v;
      });
      return out;
    }

    function fromNodeHeaders(raw) {
      const h = new Headers();
      for (let i = 0; i < raw.length; i += 2) h.append(raw[i], raw[i + 1]);
      return h;
    }

    function decodeStream(res) {
      const enc = String(res.headers["content-encoding"] || "").trim().toLowerCase();
      if (!enc || enc === "identity") return res;
      const codes = enc.split(",").map(s => s.trim()).reverse();
      let s = res;
      for (const c of codes) {
        if (c === "gzip" || c === "x-gzip") s = s.pipe(zlib.createGunzip({ flush: zlib.constants.Z_SYNC_FLUSH, finishFlush: zlib.constants.Z_SYNC_FLUSH }));
        else if (c === "deflate") s = s.pipe(zlib.createInflate({ flush: zlib.constants.Z_SYNC_FLUSH, finishFlush: zlib.constants.Z_SYNC_FLUSH }));
        else if (c === "br") s = s.pipe(zlib.createBrotliDecompress());
        else return res; // unknown coding: hand back raw bytes
      }
      return s;
    }

    function once(url, method, headers, bodyInfo, signal, redirectCount, redirected) {
      return new Promise((resolve, reject) => {
        if (signal && signal.aborted) return reject(abortError(signal));
        const mod = url.protocol === "https:" ? https : http;
        const nodeHeaders = toNodeHeaders(headers);
        if (bodyInfo && bodyInfo.contentType && !headers.has("content-type")) nodeHeaders["content-type"] = bodyInfo.contentType;
        if (bodyInfo && bodyInfo.length != null && !headers.has("content-length")) nodeHeaders["content-length"] = String(bodyInfo.length);
        if (!headers.has("accept-encoding")) nodeHeaders["accept-encoding"] = "gzip, deflate, br";
        if (!headers.has("accept")) nodeHeaders["accept"] = "*/*";
        if (!headers.has("user-agent")) nodeHeaders["user-agent"] = "node";
        const req = mod.request({
          protocol: url.protocol,
          hostname: url.hostname.startsWith("[") ? url.hostname.slice(1, -1) : url.hostname,
          port: url.port || (url.protocol === "https:" ? 443 : 80),
          path: url.pathname + url.search,
          method,
          headers: nodeHeaders,
          agent: url.protocol === "https:" ? keepAliveHttps : keepAliveHttp,
        }, res => {
          const status = res.statusCode;
          const loc = res.headers.location;
          if ([301, 302, 303, 307, 308].includes(status) && loc) {
            res.resume();
            if (redirectCount >= MAX_REDIRECTS) return reject(fetchError(new Error("redirect count exceeded")));
            let nextMethod = method, nextBody = bodyInfo;
            if (status === 303 || ((status === 301 || status === 302) && method === "POST")) { nextMethod = "GET"; nextBody = null; }
            const nextUrl = new U(loc, url);
            const nextHeaders = new Headers(headers);
            if (nextUrl.origin !== url.origin) { nextHeaders.delete("authorization"); nextHeaders.delete("cookie"); }
            if (nextBody == null) { nextHeaders.delete("content-type"); nextHeaders.delete("content-length"); }
            once(nextUrl, nextMethod, nextHeaders, nextBody, signal, redirectCount + 1, true).then(resolve, reject);
            return;
          }
          const noBody = method === "HEAD" || status === 204 || status === 205 || status === 304;
          let webBody = null;
          if (!noBody) {
            const decoded = decodeStream(res);
            webBody = Readable.toWeb(decoded);
          } else {
            res.resume();
          }
          const response = new Response(webBody, {
            status,
            statusText: res.statusMessage || "",
            headers: fromNodeHeaders(res.rawHeaders),
          });
          Object.defineProperty(response, "url", { value: url.href, configurable: true });
          Object.defineProperty(response, "redirected", { value: redirected, configurable: true });
          if (signal) {
            const onAbort = () => res.destroy(abortError(signal));
            signal.addEventListener("abort", onAbort, { once: true });
            res.on("close", () => signal.removeEventListener("abort", onAbort));
          }
          resolve(response);
        });
        req.on("error", err => reject(signal && signal.aborted ? abortError(signal) : fetchError(err)));
        if (signal) {
          const onAbort = () => { req.destroy(abortError(signal)); reject(abortError(signal)); };
          signal.addEventListener("abort", onAbort, { once: true });
          req.on("close", () => signal.removeEventListener("abort", onAbort));
        }
        if (bodyInfo) {
          bodyInfo.stream.on("error", err => req.destroy(err));
          bodyInfo.stream.pipe(req);
        } else {
          req.end();
        }
      });
    }

    _impl = async function fetch(input, init) {
      init = init || {};
      const isRequest = input && typeof input === "object" && typeof input.url === "string" && typeof input.method === "string";
      const urlStr = isRequest ? input.url : (input instanceof U ? input.href : String(input));
      let url;
      try { url = new U(urlStr); } catch (e) { throw new TypeError("Failed to parse URL from " + urlStr); }
      if (url.protocol !== "http:" && url.protocol !== "https:") throw fetchError(new Error("unsupported protocol " + url.protocol));
      const method = String(init.method || (isRequest ? input.method : "GET")).toUpperCase();
      const headers = collectHeaders(isRequest ? input : null, init);
      const signal = init.signal || (isRequest ? input.signal : undefined);
      let rawBody = init.body;
      if (rawBody === undefined && isRequest && input.body) rawBody = input.body;
      const bodyInfo = await normaliseBody(rawBody);
      if (bodyInfo && (method === "GET" || method === "HEAD")) throw new TypeError("Request with GET/HEAD method cannot have body.");
      return once(url, method, headers, bodyInfo, signal, 0, false);
    };
    return _impl;
  }

  // Node's bootstrap installs undici's fetch on globalThis after --require
  // scripts run; re-install a lazy getter so ours wins.
  let _installed = false;
  const installLazy = () => {
    if (_installed) return;
    _installed = true;
    Object.defineProperty(globalThis, "fetch", {
      configurable: true,
      get() {
        const f = _lazy();
        Object.defineProperty(globalThis, "fetch", { value: f, writable: true, configurable: true });
        return f;
      },
      set(v) {
        Object.defineProperty(globalThis, "fetch", { value: v, writable: true, configurable: true });
      },
    });
  };
  installLazy();
  process.nextTick(installLazy);
  setImmediate(installLazy);
}
