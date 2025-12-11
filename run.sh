#!/bin/bash

# --------------------------
# Usage:
#   ./run.sh path/to/folder
#   ./run.sh path/to/index.cpp
# --------------------------

if [ -z "$1" ]; then
    echo "Usage: ./run.sh <path/to/folder or .cpp file>"
    exit 1
fi

TARGET="$1"

# If user passed a folder, append index.cpp
if [ -d "$TARGET" ]; then
    TARGET="$TARGET/index.cpp"
fi

# Check if file exists
if [ ! -f "$TARGET" ]; then
    echo "Error: $TARGET not found"
    exit 1
fi

# Extract folder path
FOLDER=$(dirname "$TARGET")
OUTPUT="$FOLDER/index"

# Compile
echo "Compiling $TARGET ..."
g++ "$TARGET" -o "$OUTPUT"

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Running program..."
echo "----------------------------"

# Run (interactive)
"$OUTPUT"
