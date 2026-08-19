// Stand-in for the app's DSHHostBridge, so the guest-side plugin can be tested
// on macOS without a device. Same protocol as docs/host-bridge.md.
//   node tests/stub-bridge.mjs <port> <token>
import http from 'node:http';

const port = Number(process.argv[2] ?? 3197);
const token = process.argv[3] ?? 'stub-token';
const DEVICE = {
  model: 'iPad15,3', deviceClass: 'iPad', idiom: 'pad',
  systemName: 'iPadOS', systemVersion: '27.0', locale: 'en_US',
  timeZone: 'America/Los_Angeles', processorCount: 8, physicalMemoryMB: 8192,
  thermalState: 'nominal', lowPowerMode: false, appVersion: '1.0.0',
  batteryLevel: 100, batteryState: 'charging',
};

const server = http.createServer((req, res) => {
  const send = (status, body) => {
    const json = JSON.stringify(body);
    res.writeHead(status, { 'content-type': 'application/json', 'content-length': Buffer.byteLength(json) });
    res.end(json);
  };
  console.log(`[stub] ${req.method} ${req.url}`);
  const auth = req.headers.authorization ?? '';
  if (auth !== `Bearer ${token}`) {
    send(401, { error: { code: 'unauthorized', message: 'missing or wrong bridge token', recoverable: false } });
    return;
  }
  const path = req.url.split('?')[0];
  if (path === '/v1/capabilities') {
    send(200, { capabilities: [
      { id: 'device.info', title: 'Device information', details: '…', state: 'granted', gate: 'enabled-only' },
      { id: 'calendar.read', title: 'Calendar (read)', details: '…', state: 'granted', gate: 'system-permission' },
      { id: 'reminders.read', title: 'Reminders (read)', details: '…', state: 'granted', gate: 'system-permission' },
    ] });
  } else if (path === '/v1/device') {
    send(200, DEVICE);
  } else if (path === '/v1/calendar/events') {
    send(200, {
      events: [{ title: 'Standup', start: '2026-08-19T09:00:00Z', end: '2026-08-19T09:15:00Z',
                 allDay: false, calendar: 'Work', location: 'Zoom' }],
      from: '2026-08-19T00:00:00Z', to: '2026-08-26T00:00:00Z', truncated: false,
    });
  } else if (path === '/v1/reminders') {
    send(200, {
      reminders: [{ title: 'Buy milk', completed: false, list: 'Home', due: '2026-08-20T17:00:00Z' }],
      truncated: false,
    });
  } else {
    send(404, { error: { code: 'invalid_request', message: `no route for ${req.method} ${path}`, recoverable: false } });
  }
});
server.listen(port, '127.0.0.1', () => console.log(`stub-bridge on http://127.0.0.1:${port}`));
