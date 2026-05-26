#!/usr/bin/env bash
# Compile all main.c files and report failures.
# Usage: ./tools/audit_compile.sh

SRC_DIR="$(dirname "$0")/../src"
PASS=0
FAIL=0
FAIL_LIST=()

while IFS= read -r -d '' file; do
  dir=$(dirname "$file")
  out="$dir/a.out"
  # Extra flags for files that need special libraries
  extra_flags=""
  case "$file" in
    */s98/*) extra_flags="-I/opt/homebrew/Cellar/sqlite/3.53.1/include -L/opt/homebrew/Cellar/sqlite/3.53.1/lib -lsqlite3" ;;
  esac

  # Compile with common flags; suppress output binary to /dev/null
  if cc -Wall -Wextra -std=c11 -o "$out" "$file" \
       -lpthread -lm $extra_flags 2>"$dir/compile.log"; then
    PASS=$((PASS + 1))
    rm -f "$out" "$dir/compile.log"
  else
    FAIL=$((FAIL + 1))
    FAIL_LIST+=("$file")
    echo "FAIL: $file"
    cat "$dir/compile.log" | head -5
    echo "---"
  fi
done < <(find "$SRC_DIR" -name "main.c" -print0 | sort -z)

echo ""
echo "Results: $PASS passed, $FAIL failed"
if [ ${#FAIL_LIST[@]} -gt 0 ]; then
  echo ""
  echo "Failed files:"
  for f in "${FAIL_LIST[@]}"; do
    echo "  $f"
  done
fi
