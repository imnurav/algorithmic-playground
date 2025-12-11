#!/bin/bash

# Check if user passed a path
if [ -z "$1" ]; then
    echo "Usage: ./new.sh \"arrays/easy/Problem Name\""
    exit 1
fi

RAW_PATH="$1"

# Extract directory and problem name
DIR_PATH=$(dirname "$RAW_PATH")
PROBLEM_NAME=$(basename "$RAW_PATH")

# Convert problem name to lowercase, replace spaces with hyphens
SAFE_NAME=$(echo "$PROBLEM_NAME" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g' | sed 's/--*/-/g')

TARGET="$DIR_PATH/$SAFE_NAME"

# Create target folder
mkdir -p "$TARGET"

# Copy template files
cp template/index.cpp "$TARGET/index.cpp"

# Auto-fill README
{
    echo "# $PROBLEM_NAME"
    echo
    echo "(Add problem statement here)"
} > "$TARGET/Readme.md"

echo "Created new problem at: $TARGET"
echo "Problem Name: $PROBLEM_NAME"
