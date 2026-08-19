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
      { id: 'health.read', title: 'Apple Health (read)', details: '…', state: 'granted', gate: 'system-permission' },
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
  } else if (path === '/v1/health/activity') {
    send(200, {
      metric: 'activity', unit: 'count', from: '2026-08-16T00:00:00Z', to: '2026-08-19T12:00:00Z',
      totalSteps: 21234,
      days: [{ date: '2026-08-17', steps: 9312, distanceKm: 6.71, activeEnergyKcal: 412 },
             { date: '2026-08-18', steps: 11922, distanceKm: 8.4, activeEnergyKcal: 505 }],
    });
  } else if (path === '/v1/health/heart_rate') {
    send(200, {
      metric: 'heart_rate', unit: 'count/min', from: '2026-08-16T00:00:00Z', to: '2026-08-19T12:00:00Z',
      days: [{ date: '2026-08-18', averageBpm: 71, minBpm: 48, maxBpm: 142, restingBpm: 52 }],
    });
  } else if (path === '/v1/health/sleep') {
    send(200, {
      metric: 'sleep', from: '2026-08-16T00:00:00Z', to: '2026-08-19T12:00:00Z',
      nights: [{ date: '2026-08-18', asleepMinutes: 445, inBedMinutes: 510, awakeMinutes: 15,
                 start: '2026-08-17T23:00:00Z', end: '2026-08-18T07:30:00Z' }],
    });
  } else if (path === '/v1/health/workouts') {
    send(200, {
      metric: 'workouts', from: '2026-07-20T00:00:00Z', to: '2026-08-19T12:00:00Z', truncated: false,
      workouts: [{ type: 'Running', start: '2026-08-18T06:30:00Z', end: '2026-08-18T07:10:00Z',
                   durationMinutes: 40, activeEnergyKcal: 388, distanceKm: 7.2, source: 'Apple Watch' }],
    });
  } else if (path === '/v1/health/empty') {
    // What a route answers when the user shared nothing — the note is the point.
    send(200, { metric: 'activity', days: [], note: 'No samples in this window. iOS does not let an app see whether read access was declined.' });
  } else {
    send(404, { error: { code: 'invalid_request', message: `no route for ${req.method} ${path}`, recoverable: false } });
  }
});
server.listen(port, '127.0.0.1', () => console.log(`stub-bridge on http://127.0.0.1:${port}`));
