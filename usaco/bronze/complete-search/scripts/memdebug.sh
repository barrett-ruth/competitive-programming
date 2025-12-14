#!/bin/sh

. ./scripts/utils.sh

SRC="$1"
BASE=$(basename "$SRC" .cc)
INPUT="${BASE}.in"
OUTPUT="${BASE}.out"
DBG_BIN="${BASE}.debug"

test -d build || mkdir -p build
test -d io || mkdir -p io

test -f "$INPUT" && test ! -f "io/$INPUT" && mv "$INPUT" "io/"
test -f "$OUTPUT" && test ! -f "io/$OUTPUT" && mv "$OUTPUT" "io/"

test -f "io/$INPUT" || touch "io/$INPUT"
test -f "io/$OUTPUT" || touch "io/$OUTPUT"

INPUT="io/$INPUT"
OUTPUT="io/$OUTPUT"
DBG_BIN="build/$DBG_BIN"

compile_source "$SRC" "$DBG_BIN" "$OUTPUT" @mem_debug_flags.txt
CODE=$?
test $CODE -gt 0 && exit $CODE

# Use ulimit to restrict memory to 256MB (262144 KB)
# This will run the binary with memory restrictions
execute_binary_with_memory_limit "$DBG_BIN" "$INPUT" "$OUTPUT" 262144
exit $?