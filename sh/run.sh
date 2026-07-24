#!/bin/bash

# Run the game

BUILD_DIR="../build"

if [ ! -f "$BUILD_DIR/stfa" ]; then
    echo "Build not found. Running build.sh first..."
    ./build.sh
fi

echo "Running STFA..."
"$BUILD_DIR/stfa"
