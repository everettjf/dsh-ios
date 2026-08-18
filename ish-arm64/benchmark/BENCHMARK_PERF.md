# iSH Performance Benchmark

> **Generated:** 2026-07-11 12:45:34
> **Host:** macOS 26.5.1 / arm64
> **x86:** ish (705K, fakefs)
> **ARM64:** ish (5.5M, fakefs)
> **Runs:** 3 (median) | **Timeout:** 120s

| | x86 Emulation | ARM64 JIT |
|---|:---:|:---:|
| Engine | Interpreter (Jitter) | JIT Compiler (Asbestos) |
| Guest | i386 → ARM64 host | AArch64 → AArch64 host |
| Address | 32-bit (4 GB) | 48-bit (256 TB) |
| SIMD | Partial SSE/SSE2 | Full NEON + Crypto |
| Node/Go/Rust | Not possible | Supported |

---

## 1. Shell Benchmark (Native vs x86 vs ARM64)

> **Guest-side timing** — each test measured inside the emulator with
> monotonic clock. Startup overhead (fakefs init) is excluded.
> This isolates pure emulation performance.

### System

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| echo | 3ms | 10ms | 5ms | 3.3x | **2.0x** |
| uname -a | 9ms | 17ms | 8ms | 1.9x | **2.1x** |
| ls /bin | 8ms | 21ms | 8ms | 2.6x | **2.6x** |
| cat file | 5ms | 17ms | 10ms | 3.4x | **1.7x** |
| wc -l | 5ms | 19ms | 8ms | 3.8x | **2.4x** |
| date | 6ms | 18ms | 7ms | 3.0x | **2.6x** |
| env | 8ms | 11ms | 6ms | 1.4x | **1.8x** |

### Compute

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| loop 1000 | 5ms | 188ms | 47ms | 37.6x | **4.0x** |
| loop 5000 | 16ms | 904ms | 220ms | 56.5x | **4.1x** |
| loop 10000 | 29ms | 1809ms | 433ms | 62.4x | **4.2x** |
| seq+awk 10K | 9ms | 665ms | 92ms | 73.9x | **7.2x** |
| seq+awk 50K | 18ms | 3229ms | 417ms | 179.4x | **7.7x** |
| seq+awk 100K | 30ms | 6403ms | 821ms | 213.4x | **7.8x** |
| expr loop 500 | 917ms | 4002ms | 1677ms | 4.4x | **2.4x** |
| bc sqrt | 6ms | 24ms | 15ms | 4.0x | **1.6x** |
| bc pi | 5ms | 18ms | 6ms | 3.6x | **3.0x** |

### Text

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| sed replace | 5ms | 14ms | 6ms | 2.8x | **2.3x** |
| sort 1K | 10ms | 34ms | 13ms | 3.4x | **2.6x** |
| sort 5K | 7ms | 117ms | 21ms | 16.7x | **5.6x** |
| uniq count | 8ms | 28ms | 12ms | 3.5x | **2.3x** |
| grep count | 5ms | 286ms | 52ms | 57.2x | **5.5x** |
| tr lowercase | 5ms | 17ms | 10ms | 3.4x | **1.7x** |

### File-IO

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| create 50 | 20ms | 40ms | 45ms | 2.0x | **0.9x** |
| create 200 | 38ms | 97ms | 82ms | 2.6x | **1.2x** |
| find /bin | 6ms | 18ms | 11ms | 3.0x | **1.6x** |
| dd 64K | 9ms | 26ms | 13ms | 2.9x | **2.0x** |

### Crypto

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| md5sum | 8ms | 17ms | 10ms | 2.1x | **1.7x** |
| sha256sum | 6ms | 17ms | 9ms | 2.8x | **1.9x** |

### Process

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| fork+exec 10 | 10ms | 89ms | 39ms | 8.9x | **2.3x** |
| fork+exec 50 | 31ms | 368ms | 160ms | 11.9x | **2.3x** |
| pipe chain | 5ms | 50ms | 15ms | 10.0x | **3.3x** |

### Python

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| startup | 46ms | 549ms | 149ms | 11.9x | **3.7x** |
| sum(1M) | 35ms | 6346ms | 579ms | 181.3x | **11.0x** |
| fib(30) | 134ms | 15570ms | 1683ms | 116.2x | **9.3x** |
| str concat 10K | 28ms | 1744ms | 297ms | 62.3x | **5.9x** |
| json roundtrip | 45ms | 6059ms | 1315ms | 134.6x | **4.6x** |
| sha256 1MB | 74ms | 782ms | 189ms | 10.6x | **4.1x** |
| regex 50K | 28ms | 1163ms | 249ms | 41.5x | **4.7x** |
| sort 100K | 67ms | 10396ms | 1597ms | 155.2x | **6.5x** |

### C

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| int_arith_2M | 10ms | 805ms | 65ms | 80.5x | **12.4x** |
| float_arith_1M | 6ms | 88ms | 35ms | 14.7x | **2.5x** |
| mem_seq_4MB | 0ms | 25ms | 26ms | — | **1.0x** |
| mem_rand_500K | 1ms | 21ms | 15ms | 21.0x | **1.4x** |
| func_call_2M | 1ms | 101ms | 34ms | 101.0x | **3.0x** |
| branch_2M | 2ms | 60ms | 44ms | 30.0x | **1.4x** |
| matrix_64x64 | 0ms | 12ms | 8ms | — | **1.5x** |
| string_200K | 3ms | 635ms | 189ms | 211.7x | **3.4x** |

### Go

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| version | 38ms | 320ms | 130ms | 8.4x | **2.5x** |
| env | 12ms | 305ms | 98ms | 25.4x | **3.1x** |

### Node.js

| Test | Native | x86 | ARM64 | x86/Native | **x86/ARM64** |
|------|:---:|:---:|:---:|:---:|:---:|
| startup | 108ms | 1867ms | 423ms | 17.3x | **4.4x** |
| sum 1M | 45ms | FAIL | 1040ms | — | **—** |
| JSON 10K | 42ms | FAIL | 808ms | — | **—** |
| sha256 | 32ms | 325ms | 656ms | 10.2x | **0.5x** |

