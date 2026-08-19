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
}
