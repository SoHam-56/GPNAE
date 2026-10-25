#!/bin/bash
# Runs regression.py (arguments pass through) with an optional toolchain fix-up for a Verilator built against an older g++ than the one that runs it.
# CXX_COROUTINES=<g++ path>: wrap that g++ with -fcoroutines (--timing needs C++20 coroutines); VERILATOR_ROOT is used as the environment sets it.
set -e
if [ -n "$CXX_COROUTINES" ]; then
  WRAP="$(mktemp -d)/toolchain"
  mkdir -p "$WRAP"
  printf '#!/bin/bash\nexec %s -fcoroutines "$@"\n' "$CXX_COROUTINES" > "$WRAP/g++"
  chmod +x "$WRAP/g++"
  export PATH="$WRAP:$(dirname "$CXX_COROUTINES"):$PATH"
fi
cd "$(dirname "$0")/.."
exec python3 regression.py "$@"
