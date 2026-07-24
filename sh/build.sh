#!/bin/bash

# Build script for STFA (Some Touhou Fangame Attempt)
# Target: DragonflyBSD with Raylib + OpenGL 4.4

set -e

echo "Building STFA..."

# Directories
SRC_DIR="../src"
INC_DIR="../inc"
LIB_DIR="../lib"
BUILD_DIR="../build"
OBJ_DIR="$BUILD_DIR/obj"

# Compiler and flags
CC="gcc"
CFLAGS="-std=c17 -Wall -Wextra -O2 -I$INC_DIR"
LDFLAGS="-lraylib -lGL -lm -lpthread -ldl"

# Create build directories
mkdir -p "$BUILD_DIR" "$OBJ_DIR"

# Compile source files
echo "Compiling source files..."
$CC $CFLAGS -c "$SRC_DIR/main.c" -o "$OBJ_DIR/main.o"
$CC $CFLAGS -c "$SRC_DIR/game.c" -o "$OBJ_DIR/game.o"
$CC $CFLAGS -c "$SRC_DIR/opengl_context.c" -o "$OBJ_DIR/opengl_context.o"

# Link
echo "Linking..."
$CC -o "$BUILD_DIR/stfa" "$OBJ_DIR/main.o" "$OBJ_DIR/game.o" "$OBJ_DIR/opengl_context.o" $LDFLAGS

echo "Build complete! Output: $BUILD_DIR/stfa"
