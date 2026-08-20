/**
 * dsh-host-bridge — exposes the DSH app's iOS capabilities to the agent.
 *
 * The app runs an HTTP listener on loopback (see docs/host-bridge.md) and hands
 * this plugin its URL and token through the environment of `dsh-serve`. Each
 * capability is one route there and one tool here.
 *
 * Without the environment (running the same image outside the app, e.g. in the
 * CLI emulator during tests) the plugin loads and registers nothing, so the
 * image stays usable everywhere.
 *
 * @module dsh-host-bridge
 */
import { defineTool } from "@deepseek-ai/dsh-tools";

export const name = "host-bridge";
export const inject = ["tools"];

const BASE = process.env.DSH_HOST_BRIDGE_URL;
const TOKEN = process.env.DSH_HOST_BRIDGE_TOKEN;
const TIMEOUT_MS = Number(process.env.DSH_HOST_BRIDGE_TIMEOUT_MS ?? 20000);

/** Calls one bridge route and turns its error envelope into a thrown Error. */
async function call(path, { method = "GET", body } = {}) {
  if (!BASE || !TOKEN) throw new Error("the host bridge is not available in this environment");
  const controller = new AbortController();
  const timer = setTimeout(() => controller.abort(), TIMEOUT_MS);
  let response;
  try {
    response = await fetch(`${BASE}${path}`, {
      method,
      headers: {
        authorization: `Bearer ${TOKEN}`,
        ...(body ? { "content-type": "application/json" } : {}),
      },
      body: body ? JSON.stringify(body) : undefined,
      signal: controller.signal,
    });
  } catch (error) {
    if (error?.name === "AbortError") throw new Error(`the app did not answer within ${TIMEOUT_MS / 1000}s (it may be in the background)`);
    throw new Error(`could not reach the DSH app: ${error?.message ?? error}`);
  } finally {
    clearTimeout(timer);
  }
  const text = await response.text();
  let payload;
  try {
    payload = text ? JSON.parse(text) : {};
  } catch {
    throw new Error(`the app returned a non-JSON response (${response.status})`);
  }
  if (!response.ok) {
    const { code = "internal", message = `HTTP ${response.status}` } = payload.error ?? {};
    throw new Error(`${message} [${code}]`);
  }
  return payload;
}

export function apply(ctx) {
  if (!BASE || !TOKEN) {
    // Same image runs outside the app (CLI emulator, tests): register nothing.
    return;
  }

  // Tools are registered synchronously — Cordis tracks registrations as
  // reversible effects of this plugin, and an async registration would both
  // escape that scope and miss the first request. Whether a capability is
  // usable is decided per call by the app, which is also what lets the user
  // flip a switch without restarting the harness.
  ctx.tools.register(defineTool({
    name: "device_info",
    description:
      "Read facts about the iOS device this agent runs on: model, iOS version, locale, time zone, CPU count, memory, battery level and state, thermal state, low power mode. " +
      "Use it to answer questions about the device, or to decide whether an expensive task is worth starting (low battery, hot device). " +
      "Fails with a clear message if the user has switched this capability off in DSH's settings.",
    parameters: {},
    // The property list must match DSHDeviceCapability.snapshot in the app —
    // the registry validates tool output against it (DSHDeviceCapabilityTests
    // asserts both sides agree).
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          model: { type: "string", description: "Hardware identifier, e.g. iPhone18,1." },
          deviceClass: { type: "string", description: "iPhone or iPad." },
          idiom: { type: "string", description: "phone | pad | other." },
          systemName: { type: "string" },
          systemVersion: { type: "string" },
          locale: { type: "string" },
          timeZone: { type: "string" },
          processorCount: { type: "number" },
          physicalMemoryMB: { type: "number" },
          batteryLevel: { type: "number", description: "Percent; absent when unknown." },
          batteryState: { type: "string", description: "charging | full | unplugged | unknown." },
          thermalState: { type: "string", description: "nominal | fair | serious | critical." },
          lowPowerMode: { type: "boolean" },
          appVersion: { type: "string" },
        },
      },
      // What the model reads: one `key: value` per line, which costs fewer
      // tokens than pretty-printed JSON and reads the same.
      render: (_args, value) => [{
        type: "text",
        text: Object.entries(value).map(([key, v]) => `${key}: ${v}`).join("\n"),
      }],
    },
    execute: () => call("/v1/device"),
    presentCall: () => ({ card: "generic", title: "Read device information", kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "calendar_query",
    description:
      "Read events from the user's calendars on this device. `days` looks forward (7 by default); a negative value looks back. " +
      "Results are capped and report whether they were truncated. " +
      "If the capability is off in DSH's settings, or iOS has not granted calendar access yet, the call fails with a message saying so — relay it to the user instead of retrying blindly.",
    parameters: {
      days: { type: "number", description: "Days ahead (negative for the past). Default 7, max 366." },
      limit: { type: "number", description: "Maximum events to return. Default 50, max 200." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          events: {
            type: "array",
            items: {
              type: "object",
              additionalProperties: false,
              properties: {
                title: { type: "string" },
                start: { type: "string", description: "ISO 8601." },
                end: { type: "string", description: "ISO 8601." },
                allDay: { type: "boolean" },
                calendar: { type: "string" },
                location: { type: "string" },
                notes: { type: "string", description: "Truncated to 500 characters." },
                attendeeCount: { type: "number" },
              },
            },
          },
          from: { type: "string" },
          to: { type: "string" },
          truncated: { type: "boolean", description: "True when more events matched than were returned." },
        },
      },
      render: (_args, value) => [{
        type: "text",
        text: value.events.length === 0
          ? `No events between ${value.from} and ${value.to}.`
          : [
              `Events ${value.from} → ${value.to}${value.truncated ? " (truncated)" : ""}:`,
              ...value.events.map((e) => {
                const when = e.allDay ? `${e.start} (all day)` : `${e.start} → ${e.end}`;
                const where = e.location ? ` @ ${e.location}` : "";
                return `- ${e.title} — ${when}${where} [${e.calendar}]`;
              }),
            ].join("\n"),
      }],
    },
    execute: ({ days, limit }) => {
      const query = new URLSearchParams();
      if (days !== undefined) query.set("days", String(days));
      if (limit !== undefined) query.set("limit", String(limit));
      const suffix = query.toString();
      return call(`/v1/calendar/events${suffix ? `?${suffix}` : ""}`);
    },
    presentCall: (args) => ({
      card: "generic",
      title: `Read calendar (${args.days ?? 7} days)`,
      kind: "other",
    }),
  }));

  ctx.tools.register(defineTool({
    name: "reminders_query",
    description:
      "Read the user's reminders on this device, soonest due first. Completed ones are left out unless `completed` is true. " +
      "Same failure behaviour as calendar_query when the capability is off or iOS has not granted access.",
    parameters: {
      completed: { type: "boolean", description: "Include completed reminders. Default false." },
      limit: { type: "number", description: "Maximum reminders to return. Default 50, max 200." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          reminders: {
            type: "array",
            items: {
              type: "object",
              additionalProperties: false,
              properties: {
                title: { type: "string" },
                completed: { type: "boolean" },
                list: { type: "string" },
                due: { type: "string", description: "ISO 8601; absent when the reminder has no due date." },
                priority: { type: "number" },
                notes: { type: "string", description: "Truncated to 500 characters." },
              },
            },
          },
          truncated: { type: "boolean" },
          note: { type: "string" },
        },
      },
      render: (_args, value) => [{
        type: "text",
        text: value.reminders.length === 0
          ? "No reminders."
          : [
              `Reminders${value.truncated ? " (truncated)" : ""}:`,
              ...value.reminders.map((r) => {
                const due = r.due ? ` — due ${r.due}` : "";
                const state = r.completed ? " [done]" : "";
                return `- ${r.title}${due} [${r.list}]${state}`;
              }),
            ].join("\n"),
      }],
    },
    execute: ({ completed, limit }) => {
      const query = new URLSearchParams();
      if (completed) query.set("completed", "true");
      if (limit !== undefined) query.set("limit", String(limit));
      const suffix = query.toString();
      return call(`/v1/reminders${suffix ? `?${suffix}` : ""}`);
    },
    presentCall: () => ({ card: "generic", title: "Read reminders", kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "health_query",
    description:
      "Read Apple Health data from this device. Pick one metric per call:\n" +
      "- `activity`: steps, walking/running distance and active energy, one row per day.\n" +
      "- `heart_rate`: daily min/average/max and resting heart rate.\n" +
      "- `sleep`: one row per day (asleep, in bed and awake minutes), attributed to the day a sleep stretch ends, so a night across midnight counts on the waking day.\n" +
      "- `workouts`: individual workouts, most recent first.\n" +
      "An empty result carries a `note`: iOS does not let an app tell 'no data' apart from 'read access declined', " +
      "so never conclude from an empty answer that the user did not walk, sleep or exercise — relay the note instead. " +
      "This is health information: report what the user asked for and do not volunteer diagnoses.",
    parameters: {
      metric: {
        type: "string",
        enum: ["activity", "heart_rate", "sleep", "workouts"],
        description: "Which data to read. Required.",
      },
      days: { type: "number", description: "How many days back, including today. Default 7 (30 for workouts), max 366." },
      limit: { type: "number", description: "Workouts only: maximum rows. Default 50, max 200." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          metric: { type: "string" },
          unit: { type: "string" },
          from: { type: "string", description: "ISO 8601 start of the window." },
          to: { type: "string", description: "ISO 8601 end of the window." },
          totalSteps: { type: "number" },
          days: {
            type: "array",
            description: "activity and heart_rate: one entry per day.",
            items: {
              type: "object",
              additionalProperties: false,
              properties: {
                date: { type: "string", description: "YYYY-MM-DD." },
                steps: { type: "number" },
                distanceKm: { type: "number" },
                activeEnergyKcal: { type: "number" },
                averageBpm: { type: "number" },
                minBpm: { type: "number" },
                maxBpm: { type: "number" },
                restingBpm: { type: "number" },
              },
            },
          },
          nights: {
            type: "array",
            description: "sleep: one entry per night.",
            items: {
              type: "object",
              additionalProperties: false,
              properties: {
                date: { type: "string" },
                asleepMinutes: { type: "number" },
                inBedMinutes: { type: "number" },
                awakeMinutes: { type: "number" },
                start: { type: "string" },
                end: { type: "string" },
              },
            },
          },
          workouts: {
            type: "array",
            items: {
              type: "object",
              additionalProperties: false,
              properties: {
                type: { type: "string" },
                start: { type: "string" },
                end: { type: "string" },
                durationMinutes: { type: "number" },
                activeEnergyKcal: { type: "number" },
                distanceKm: { type: "number" },
                source: { type: "string" },
              },
            },
          },
          truncated: { type: "boolean" },
          note: { type: "string", description: "Present when the window came back empty, or the query timed out." },
        },
      },
      render: (_args, value) => {
        const lines = [];
        // A timed-out query answers with a note and no window, so the range is
        // printed only when there is one.
        const range = value.from && value.to ? ` ${value.from} → ${value.to}` : "";
        if (value.metric === "activity") {
          lines.push(`Activity${range} (${value.totalSteps ?? 0} steps total):`);
          for (const d of value.days ?? []) {
            const extra = [
              d.distanceKm !== undefined ? `${d.distanceKm} km` : null,
              d.activeEnergyKcal !== undefined ? `${d.activeEnergyKcal} kcal` : null,
            ].filter(Boolean);
            lines.push(`- ${d.date}: ${d.steps} steps${extra.length ? ` (${extra.join(", ")})` : ""}`);
          }
        } else if (value.metric === "heart_rate") {
          lines.push(`Heart rate${range} (bpm):`);
          for (const d of value.days ?? []) {
            const parts = [
              d.averageBpm !== undefined ? `avg ${d.averageBpm}` : null,
              d.minBpm !== undefined ? `min ${d.minBpm}` : null,
              d.maxBpm !== undefined ? `max ${d.maxBpm}` : null,
              d.restingBpm !== undefined ? `resting ${d.restingBpm}` : null,
            ].filter(Boolean);
            lines.push(`- ${d.date}: ${parts.join(", ")}`);
          }
        } else if (value.metric === "sleep") {
          lines.push(`Sleep${range}:`);
          for (const n of value.nights ?? []) {
            const hours = (n.asleepMinutes / 60).toFixed(1);
            // Not "night of": a daytime nap lands in the same bucket, so the
            // row is the day's total sleep, not strictly one night.
            lines.push(`- ${n.date}: ${hours}h asleep (${n.inBedMinutes} min in bed, ${n.awakeMinutes} min awake)`);
          }
        } else {
          lines.push(`Workouts${range}${value.truncated ? " (truncated)" : ""}:`);
          for (const w of value.workouts ?? []) {
            const extra = [
              w.distanceKm !== undefined ? `${w.distanceKm} km` : null,
              w.activeEnergyKcal !== undefined ? `${w.activeEnergyKcal} kcal` : null,
            ].filter(Boolean);
            lines.push(`- ${w.start}: ${w.type}, ${w.durationMinutes} min${extra.length ? ` (${extra.join(", ")})` : ""}`);
          }
        }
        if (value.note) lines.push(value.note);
        return [{ type: "text", text: lines.join("\n") }];
      },
    },
    execute: ({ metric, days, limit }) => {
      if (!metric) throw new Error("metric is required: activity, heart_rate, sleep or workouts");
      const query = new URLSearchParams();
      if (days !== undefined) query.set("days", String(days));
      if (limit !== undefined) query.set("limit", String(limit));
      const suffix = query.toString();
      return call(`/v1/health/${metric}${suffix ? `?${suffix}` : ""}`);
    },
    presentCall: (args) => ({
      card: "generic",
      title: `Read Health: ${args.metric ?? "activity"}`,
      kind: "other",
    }),
  }));

  ctx.tools.register(defineTool({
    name: "device_power",
    description:
      "Battery level and state, thermal state and low power mode, plus `shouldDeferExpensiveWork` — " +
      "check it before starting something long or CPU-heavy on the user's phone.",
    parameters: {},
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          batteryLevel: { type: "number", description: "Percent; absent when unknown." },
          batteryState: { type: "string" },
          thermalState: { type: "string", description: "nominal | fair | serious | critical." },
          lowPowerMode: { type: "boolean" },
          shouldDeferExpensiveWork: { type: "boolean" },
        },
      },
      render: (_args, value) => [{
        type: "text",
        text: Object.entries(value).map(([key, v]) => `${key}: ${v}`).join("\n"),
      }],
    },
    execute: () => call("/v1/device/power"),
    presentCall: () => ({ card: "generic", title: "Check battery and thermal state", kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "clipboard_write",
    description:
      "Put text on the user's clipboard, replacing what was there. Only do it when they asked for something to be copied. " +
      "There is no way to read the clipboard back — iOS interrupts the user for every read, so DSH does not offer one. " +
      "The user is asked to confirm every call and can decline; if they do, do not try again with the same text.",
    parameters: {
      text: { type: "string", description: "The text to put on the clipboard. Required." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: { written: { type: "boolean" }, characters: { type: "number" } },
      },
      render: (_args, value) => [{ type: "text", text: `Copied ${value.characters} characters to the clipboard.` }],
    },
    execute: ({ text }) => {
      if (typeof text !== "string") throw new Error("text is required");
      return call("/v1/clipboard", { method: "POST", body: { text } });
    },
    presentCall: () => ({ card: "generic", title: "Copy text to the clipboard", kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "location_query",
    description:
      "One location fix from the device, with its accuracy in metres. There is no tracking and no history — each call is a fresh fix. " +
      "Always state the accuracy rather than implying the position is exact. Fails clearly if the user has not allowed location access.",
    parameters: {},
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          latitude: { type: "number" },
          longitude: { type: "number" },
          accuracyMeters: { type: "number" },
          altitudeMeters: { type: "number" },
          speedMetersPerSecond: { type: "number" },
          timestamp: { type: "string" },
        },
      },
      render: (_args, value) => [{
        type: "text",
        text: `${value.latitude.toFixed(5)}, ${value.longitude.toFixed(5)} (±${value.accuracyMeters} m) at ${value.timestamp}`,
      }],
    },
    execute: () => call("/v1/location"),
    presentCall: () => ({ card: "generic", title: "Get the current location", kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "contacts_search",
    description:
      "Look up people in the user's contacts by name. You must say who you are looking for — there is no way to list every contact, by design. " +
      "Treat what comes back as private: use it for the task at hand and do not repeat more of it than the user needs.",
    parameters: {
      query: { type: "string", description: "Name to search for. Required." },
      limit: { type: "number", description: "Maximum matches. Default 10, max 25." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          query: { type: "string" },
          contacts: {
            type: "array",
            items: {
              type: "object",
              additionalProperties: false,
              properties: {
                name: { type: "string" },
                organization: { type: "string" },
                nickname: { type: "string" },
                birthday: { type: "string" },
                phones: {
                  type: "array",
                  items: {
                    type: "object",
                    additionalProperties: false,
                    properties: { label: { type: "string" }, number: { type: "string" } },
                  },
                },
                emails: {
                  type: "array",
                  items: {
                    type: "object",
                    additionalProperties: false,
                    properties: { label: { type: "string" }, address: { type: "string" } },
                  },
                },
                addresses: {
                  type: "array",
                  items: {
                    type: "object",
                    additionalProperties: false,
                    properties: { label: { type: "string" }, address: { type: "string" } },
                  },
                },
              },
            },
          },
          truncated: { type: "boolean" },
        },
      },
      render: (_args, value) => [{
        type: "text",
        text: value.contacts.length === 0
          ? `No contact matches “${value.query}”.`
          : value.contacts.map((c) => {
              const bits = [
                ...(c.phones ?? []).map((p) => `${p.label || "phone"}: ${p.number}`),
                ...(c.emails ?? []).map((e) => `${e.label || "email"}: ${e.address}`),
                ...(c.addresses ?? []).map((a) => `${a.label || "address"}: ${a.address.replace(/\n/g, ", ")}`),
                c.birthday ? `birthday: ${c.birthday}` : null,
              ].filter(Boolean);
              return `${c.name}${c.organization ? ` (${c.organization})` : ""}\n  ${bits.join("\n  ")}`;
            }).join("\n"),
      }],
    },
    execute: ({ query, limit }) => {
      if (!query) throw new Error("query is required: name the person to look up");
      const params = new URLSearchParams({ q: query });
      if (limit !== undefined) params.set("limit", String(limit));
      return call(`/v1/contacts?${params}`);
    },
    presentCall: (args) => ({ card: "generic", title: `Look up “${args.query}” in contacts`, kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "notify",
    description:
      "Send the user a notification on this device — for when a long task finishes and they are not looking at DSH. " +
      "Limited to 10 an hour; if that runs out, just say it in the conversation instead. Do not use it for things the user is already watching happen.",
    parameters: {
      title: { type: "string", description: "Short headline. Required." },
      body: { type: "string", description: "Optional second line." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: { delivered: { type: "boolean" }, remainingThisHour: { type: "number" } },
      },
      render: (_args, value) => [{ type: "text", text: `Notification sent (${value.remainingThisHour} left this hour).` }],
    },
    execute: ({ title, body }) => {
      if (!title) throw new Error("title is required");
      return call("/v1/notify", { method: "POST", body: { title, body } });
    },
    presentCall: (args) => ({ card: "generic", title: `Notify: ${args.title}`, kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "calendar_create_event",
    description:
      "Add an event to the user's default calendar. `start` and `end` take ISO 8601, or \"YYYY-MM-DD HH:mm\" / \"YYYY-MM-DD\" in the device's own time zone — " +
      "prefer the local forms, since that is what the user means. Without `end` the event lasts an hour (or a day when `allDay`). " +
      "The user confirms every call and sees the title, time and calendar first; if they decline, ask what to change rather than retrying.",
    parameters: {
      title: { type: "string", description: "Required." },
      start: { type: "string", description: "Required." },
      end: { type: "string" },
      allDay: { type: "boolean" },
      location: { type: "string" },
      notes: { type: "string" },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          created: { type: "boolean" },
          title: { type: "string" },
          start: { type: "string" },
          end: { type: "string" },
          allDay: { type: "boolean" },
          calendar: { type: "string" },
        },
      },
      render: (_args, value) => [{
        type: "text",
        text: `Added “${value.title}” to ${value.calendar}: ${value.start}${value.allDay ? " (all day)" : ` → ${value.end}`}`,
      }],
    },
    execute: (args) => {
      if (!args.title || !args.start) throw new Error("title and start are required");
      return call("/v1/calendar/events", { method: "POST", body: args });
    },
    presentCall: (args) => ({ card: "generic", title: `Create event “${args.title}”`, kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "reminders_create",
    description:
      "Add a reminder to the user's default list, optionally with a due date (same date formats as calendar_create_event). " +
      "A due date also sets an alarm, so the user actually gets reminded. Confirmed by the user every call.",
    parameters: {
      title: { type: "string", description: "Required." },
      due: { type: "string" },
      notes: { type: "string" },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          created: { type: "boolean" },
          title: { type: "string" },
          due: { type: "string" },
          list: { type: "string" },
        },
      },
      render: (_args, value) => [{
        type: "text",
        text: `Added “${value.title}” to ${value.list}${value.due ? `, due ${value.due}` : ""}.`,
      }],
    },
    execute: (args) => {
      if (!args.title) throw new Error("title is required");
      return call("/v1/reminders", { method: "POST", body: args });
    },
    presentCall: (args) => ({ card: "generic", title: `Create reminder “${args.title}”`, kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "file_import",
    description:
      "Ask the user to hand you a file: opens the iOS file picker and returns the chosen file's contents, base64-encoded. " +
      "Write it into the workspace yourself (Buffer.from(base64, 'base64')) before working on it. " +
      "The user may close the picker without choosing, which is a normal answer, not an error to retry.",
    parameters: {},
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: {
          name: { type: "string" },
          bytes: { type: "number" },
          base64: { type: "string" },
        },
      },
      render: (_args, value) => [{ type: "text", text: `The user picked “${value.name}” (${value.bytes} bytes).` }],
    },
    execute: () => call("/v1/files/import", { method: "POST", body: {} }),
    presentCall: () => ({ card: "generic", title: "Ask the user for a file", kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "file_export",
    description:
      "Save a file out of DSH: the user confirms, then chooses where it goes in the iOS save dialog. " +
      "Send the contents base64-encoded, at most 8 MB. Use it when the user asks for something they want to keep or open elsewhere.",
    parameters: {
      name: { type: "string", description: "File name, e.g. report.md. Required." },
      base64: { type: "string", description: "File contents, base64-encoded. Required." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: { saved: { type: "boolean" }, name: { type: "string" }, bytes: { type: "number" } },
      },
      render: (_args, value) => [{ type: "text", text: `Saved “${value.name}” (${value.bytes} bytes).` }],
    },
    execute: ({ name, base64 }) => {
      if (!name || typeof base64 !== "string") throw new Error("name and base64 are required");
      return call("/v1/files/export", { method: "POST", body: { name, base64 } });
    },
    presentCall: (args) => ({ card: "generic", title: `Save “${args.name}”`, kind: "other" }),
  }));

  ctx.tools.register(defineTool({
    name: "shortcut_run",
    description:
      "Run one of the user's own Shortcuts by name, optionally with text input. Two things to understand before using it:\n" +
      "- A shortcut can do anything the user built it to do, and DSH cannot see inside it. The user confirms every call.\n" +
      "- Running one opens the Shortcuts app, which sends DSH to the background and stops this turn. There is no result to read. " +
      "Say what you asked for and let the user tell you what happened when they come back.",
    parameters: {
      name: { type: "string", description: "The shortcut's name, exactly as in the Shortcuts app. Required." },
      input: { type: "string", description: "Optional text input for the shortcut." },
    },
    output: {
      schema: {
        type: "object",
        additionalProperties: false,
        properties: { started: { type: "boolean" }, name: { type: "string" }, note: { type: "string" } },
      },
      render: (_args, value) => [{ type: "text", text: `Started the shortcut “${value.name}”. ${value.note}` }],
    },
    execute: ({ name, input }) => {
      if (!name) throw new Error("name is required");
      return call("/v1/shortcut/run", { method: "POST", body: { name, input } });
    },
    presentCall: (args) => ({ card: "generic", title: `Run shortcut “${args.name}”`, kind: "other" }),
  }));
}
