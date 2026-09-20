#!/bin/bash
# Toolchain setup for the GPNAE regression, then run it. Arguments pass through to regression.py.
# Needs VERILATOR_ROOT (verilator lives under ~/.local), gcc-toolset-13 (--timing needs C++20
# coroutines) and -fcoroutines (this verilator was built against g++ 8 and omits the flag).
set -e
export VERILATOR_ROOT="$HOME/.local/share/verilator"

WRAP="$(mktemp -d)/toolchain"
mkdir -p "$WRAP"
cat > "$WRAP/g++" <<'WRAPPER'
#!/bin/bash
exec /opt/rh/gcc-toolset-13/root/usr/bin/g++ -fcoroutines "$@"
WRAPPER
chmod +x "$WRAP/g++"
export PATH="$WRAP:/opt/rh/gcc-toolset-13/root/usr/bin:$PATH"

cd "$(dirname "$0")"
exec python3 regression.py "$@"
