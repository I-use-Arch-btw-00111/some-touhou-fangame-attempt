#include "game.h"
#include "config.h"

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

void game_render_gameplay(void) {
    // Draw gameplay area border
    DrawRectangleLines(GAMEPLAY_X, GAMEPLAY_Y, GAMEPLAY_WIDTH, GAMEPLAY_HEIGHT, DARKBLUE);
    
    // Gameplay content
    DrawText("Gameplay Area", GAMEPLAY_X + 10, GAMEPLAY_Y + 10, 16, BLUE);
    
    // TODO: Render game entities (player, enemies, bullets) here
}

void game_render_ui(void) {
    // Draw UI area background
    DrawRectangle(UI_X, UI_Y, UI_WIDTH, UI_HEIGHT, DARKGRAY);
    
    // Draw UI area border
    DrawRectangleLines(UI_X, UI_Y, UI_WIDTH, UI_HEIGHT, GRAY);
    
    // UI Content
    DrawText("UI Area", UI_X + 10, UI_Y + 10, 16, WHITE);
    DrawText(TextFormat("Frame: %u", g_game_state.frame_count), UI_X + 10, UI_Y + 35, 14, LIGHTGRAY);
    DrawText(TextFormat("Time: %.2f", g_game_state.time_elapsed), UI_X + 10, UI_Y + 55, 14, LIGHTGRAY);
    
    // TODO: Render UI elements (health, score, wave info) here
}

void game_render(void) {
    // Render gameplay area (left)
    game_render_gameplay();
    
    // Render UI area (right)
    game_render_ui();
}

void game_cleanup(void) {
    // TODO: Cleanup game resources
}
