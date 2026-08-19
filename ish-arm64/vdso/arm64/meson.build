# ARM64 VDSO Build Configuration
#
# The VDSO gets inserted into the address space of emulated processes, so it
# needs to be compiled as an aarch64 ELF shared library. This requires a cross
# compiler and linker.
#
# On macOS, you need an aarch64 cross-compiler toolchain.
# On Linux, you can use the native compiler if running on arm64, or a cross compiler.

# Try to find an aarch64 compiler
clang = find_program('/usr/local/opt/llvm/bin/clang', '/opt/homebrew/opt/llvm/bin/clang', '/opt/local/bin/clang', 'clang', required: false)

# The check has to gate the build, not merely warn: Apple's clang compiles for
# aarch64 but cannot link an ELF (no lld), which would fail the configure step
# on a stock macOS toolchain.
vdso_cc_usable = false
if clang.found()
    check_cc = find_program('./check-cc-arm64.sh', required: false)
    if check_cc.found()
        result = run_command(check_cc, clang, check: false)
        vdso_cc_usable = result.returncode() == 0
        if not vdso_cc_usable
            message('ARM64 VDSO: cross-compiler check failed, building a stub instead')
            message(result.stdout() + result.stderr())
        endif
    else
        vdso_cc_usable = true
    endif
endif

if vdso_cc_usable
    vdso_compiler = [clang, '-target', 'aarch64-linux-gnu', '-fuse-ld=lld']

    vdso = custom_target('vdso-arm64',
        input: ['vdso.S', 'vdso.c', 'vdso.lds'],
        output: 'libvdso.so.elf',
        command: vdso_compiler + [
            '-o', '@OUTPUT@', '@INPUT0@', '@INPUT1@',
            '-nostdlib', '-Wl,-T,@INPUT2@', '-Wl,--hash-style,sysv',
            '-shared', '-fPIC', '-ffreestanding'
        ] + get_option('vdso_c_args').split())
else
    # Create a dummy vdso target if no compiler is available
    # This allows building for ARM64 guest even without a vdso
    # A stub lets the configure step finish, but the guest needs the real VDSO
    # to run: install lld (brew install lld) and reconfigure.
    warning('ARM64 VDSO: no aarch64 cross-toolchain with lld — building a stub. The emulator will build but guest processes will not run; install lld and reconfigure.')
    # Create an empty file as placeholder
    vdso = custom_target('vdso-arm64-stub',
        output: 'libvdso.so.elf',
        command: ['touch', '@OUTPUT@'])
endif
