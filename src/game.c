#include "game.h"
#include "config.h"
#include <raylib.h>

static GameState g_game_state = {0};

void game_init(void) {
    g_game_state.is_running = 1;
    g_game_state.time_elapsed = 0.0f;
    g_game_state.frame_count = 0;
}

void game_update(float dt) {
    g_game_state.time_elapsed += dt;
    g_game_state.frame_count++;
    
    // TODO: Game logic here
}

void game_render(void) {
    // Debug text
    DrawText("STFA - Touhou Fangame", 10, 10, 20, WHITE);
    DrawText(TextFormat("Frame: %u", g_game_state.frame_count), 10, 35, 20, WHITE);
    DrawText(TextFormat("Time: %.2f", g_game_state.time_elapsed), 10, 60, 20, WHITE);
    
    // TODO: Render game here
}

void game_cleanup(void) {
    // TODO: Cleanup game resources
}
