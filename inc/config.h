#ifndef CONFIG_H
#define CONFIG_H

// OpenGL Configuration
#define OPENGL_VERSION_MAJOR 4
#define OPENGL_VERSION_MINOR 4
#define OPENGL_CORE_PROFILE 1
#define OPENGL_CONTEXT_RELEASE_BEHAVIOR_NONE 1

// Window Configuration
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "STFA - Some Touhou Fangame Attempt"
#define TARGET_FPS 60

// Gameplay Area Configuration (left side)
#define GAMEPLAY_WIDTH 892
#define GAMEPLAY_HEIGHT 652
#define GAMEPLAY_X 0
#define GAMEPLAY_Y ((WINDOW_HEIGHT - GAMEPLAY_HEIGHT) / 2)  // Center vertically

// UI Area Configuration (right side)
#define UI_WIDTH (WINDOW_WIDTH - GAMEPLAY_WIDTH)
#define UI_HEIGHT WINDOW_HEIGHT
#define UI_X GAMEPLAY_WIDTH
#define UI_Y 0

// Game Configuration
#define GAME_SCALE 1.0f

#endif // CONFIG_H
