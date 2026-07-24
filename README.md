# STFA - Some Touhou Fangame Attempt

A 2D Touhou-inspired bullet-hell game written in pure C using Raylib with OpenGL 4.4 AZDO rendering.

## Target Platform
- **DragonflyBSD** (with cross-platform support)

## Build System
- **Language:** Pure C
- **Graphics:** Raylib + OpenGL 4.4 Core Profile
- **Rendering Approach:** AZDO (Approaching Zero Driver Overhead)
  - Direct State Access (DSA)
  - Persistent-mapped buffers
  - Custom context with `GL_CONTEXT_RELEASE_BEHAVIOR_NONE`

## Project Structure
```
.
├── src/           # Source files (.c)
├── inc/           # Header files (.h)
├── lib/           # External libraries & bindings
├── res/           # Game resources (sprites, audio, etc.)
├── sh/            # Build helper scripts
└── README.md      # This file
```

## Building

### Prerequisites (DragonflyBSD)
```bash
pkg install raylib sdl2 glew glfw3
```

### Build
```bash
cd sh
./build.sh
```

### Run
```bash
./build/stfa
```

## Development Notes

- All rendering uses OpenGL 4.4 core profile
- Context release behavior set to `GL_CONTEXT_RELEASE_BEHAVIOR_NONE` for fine-grained control
- AZDO techniques minimize CPU-GPU synchronization overhead
