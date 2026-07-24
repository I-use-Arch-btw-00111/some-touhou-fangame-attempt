#include <raylib.h>
#include <stdio.h>
#include "config.h"
#include "game.h"
#include "opengl_context.h"

int main(void) {
    // Initialize Raylib with custom OpenGL context
    gl_context_init();
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    
    // Initialize game
    game_init();
    
    // Main game loop
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        
        // Update
        game_update(dt);
        
        // Render
        BeginDrawing();
            ClearBackground(BLACK);
            game_render();
        EndDrawing();
    }
    
    // Cleanup
    game_cleanup();
    gl_context_cleanup();
    CloseWindow();
    
    return 0;
}
