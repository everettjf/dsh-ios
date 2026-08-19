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
        if (value.metric === "activity") {
          lines.push(`Activity ${value.from} → ${value.to} (${value.totalSteps ?? 0} steps total):`);
          for (const d of value.days ?? []) {
            const extra = [
              d.distanceKm !== undefined ? `${d.distanceKm} km` : null,
              d.activeEnergyKcal !== undefined ? `${d.activeEnergyKcal} kcal` : null,
            ].filter(Boolean);
            lines.push(`- ${d.date}: ${d.steps} steps${extra.length ? ` (${extra.join(", ")})` : ""}`);
          }
        } else if (value.metric === "heart_rate") {
          lines.push(`Heart rate ${value.from} → ${value.to} (bpm):`);
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
          lines.push(`Sleep ${value.from} → ${value.to}:`);
          for (const n of value.nights ?? []) {
            const hours = (n.asleepMinutes / 60).toFixed(1);
            // Not "night of": a daytime nap lands in the same bucket, so the
            // row is the day's total sleep, not strictly one night.
            lines.push(`- ${n.date}: ${hours}h asleep (${n.inBedMinutes} min in bed, ${n.awakeMinutes} min awake)`);
          }
        } else {
          lines.push(`Workouts ${value.from} → ${value.to}${value.truncated ? " (truncated)" : ""}:`);
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
}
