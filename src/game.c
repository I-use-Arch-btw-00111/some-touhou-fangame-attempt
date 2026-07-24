#include "game.h"
#include "config.h"
#include "ui.h"
#include "map.h"
#include <raylib.h>

static GameState g_game_state = {0};
static Map* g_map = NULL;

void game_init(void) {
    g_game_state.is_running = 1;
    g_game_state.time_elapsed = 0.0f;
    g_game_state.frame_count = 0;
    
    ui_init();
    g_map = map_create(32, 32);
}

void game_update(float dt) {
    g_game_state.time_elapsed += dt;
    g_game_state.frame_count++;
    
    // Update map
    if (g_map) {
        map_update(g_map, dt);
    }
}

void game_render_gameplay(void) {
    // Fill gameplay area with dark background
    DrawRectangle(GAMEPLAY_X, GAMEPLAY_Y, GAMEPLAY_WIDTH, GAMEPLAY_HEIGHT, (Color){20, 20, 30, 255});
    
    // Render map
    if (g_map) {
        map_render(g_map);
    }
    
    // Draw gameplay area border
    DrawRectangleLines(GAMEPLAY_X, GAMEPLAY_Y, GAMEPLAY_WIDTH, GAMEPLAY_HEIGHT, DARKBLUE);
}

void game_render_ui(void) {
    // Draw UI area background
    DrawRectangle(UI_X, UI_Y, UI_WIDTH, UI_HEIGHT, DARKGRAY);
    
    // Draw UI area border
    DrawRectangleLines(UI_X, UI_Y, UI_WIDTH, UI_HEIGHT, GRAY);
    
    // Calculate FPS
    float fps = 1.0f / GetFrameTime();
    
    // Render UI elements
    ui_render(g_game_state.time_elapsed, g_game_state.frame_count, fps);
}

void game_render(void) {
    // Render gameplay area (left)
    game_render_gameplay();
    
    // Render UI area (right)
    game_render_ui();
}

void game_cleanup(void) {
    if (g_map) {
        map_destroy(g_map);
    }
    ui_cleanup();
}
