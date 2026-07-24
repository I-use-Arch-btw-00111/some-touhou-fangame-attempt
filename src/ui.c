#include "ui.h"
#include "config.h"
#include <raylib.h>
#include <stdio.h>
#include <string.h>
#include <GL/gl.h>

static UIState g_ui_state = {0};
static char g_gl_vendor[256] = {0};
static char g_gl_renderer[256] = {0};
static char g_gl_version[256] = {0};

void ui_init(void) {
    g_ui_state.points = 0;
    g_ui_state.hearts = 8;
    g_ui_state.bombs = 8;
    g_ui_state.graze = 0;
    
    // Get OpenGL info
    const char* vendor = (const char*)glGetString(GL_VENDOR);
    const char* renderer = (const char*)glGetString(GL_RENDERER);
    const char* version = (const char*)glGetString(GL_VERSION);
    
    if (vendor) strncpy(g_gl_vendor, vendor, sizeof(g_gl_vendor) - 1);
    if (renderer) strncpy(g_gl_renderer, renderer, sizeof(g_gl_renderer) - 1);
    if (version) strncpy(g_gl_version, version, sizeof(g_gl_version) - 1);
}

void ui_render(float time_elapsed, uint32_t frame_count, float fps) {
    int start_y = UI_Y + 20;
    int line_height = 30;
    int current_y = start_y;
    
    // Title
    DrawText("UI Area", UI_X + 15, current_y, 20, WHITE);
    current_y += line_height + 10;
    
    // Timer (MM:SS.ms format)
    uint32_t minutes = (uint32_t)(time_elapsed / 60.0f);
    uint32_t seconds = (uint32_t)time_elapsed % 60;
    uint32_t milliseconds = (uint32_t)((time_elapsed - (int)time_elapsed) * 100);
    
    DrawText(TextFormat("Time: %02u:%02u.%02u", minutes, seconds, milliseconds), 
             UI_X + 15, current_y, 16, YELLOW);
    current_y += line_height;
    
    // Points
    DrawText(TextFormat("Points: %u", g_ui_state.points), 
             UI_X + 15, current_y, 16, WHITE);
    current_y += line_height;
    
    // Hearts
    DrawText("Hearts: ", UI_X + 15, current_y, 16, RED);
    for (int i = 0; i < 8; i++) {
        Color heart_color = (i < g_ui_state.hearts) ? RED : DARKGRAY;
        DrawText("♥", UI_X + 120 + (i * 18), current_y, 16, heart_color);
    }
    current_y += line_height;
    
    // Bombs
    DrawText("Bombs: ", UI_X + 15, current_y, 16, LIGHTBLUE);
    for (int i = 0; i < 8; i++) {
        Color bomb_color = (i < g_ui_state.bombs) ? LIGHTBLUE : DARKGRAY;
        DrawText("●", UI_X + 120 + (i * 18), current_y, 16, bomb_color);
    }
    current_y += line_height;
    
    // Graze
    DrawText(TextFormat("Graze: %u", g_ui_state.graze), 
             UI_X + 15, current_y, 16, WHITE);
    current_y += line_height;
    
    // FPS
    DrawText(TextFormat("FPS: %.1f", fps), 
             UI_X + 15, current_y, 16, (fps >= TARGET_FPS - 5) ? GREEN : ORANGE);
    current_y += line_height + 20;
    
    // OpenGL Info at bottom
    int bottom_y = UI_Y + UI_HEIGHT - 80;
    
    DrawText("OpenGL Info:", UI_X + 15, bottom_y, 12, LIGHTGRAY);
    DrawText(TextFormat("Vendor: %s", g_gl_vendor), UI_X + 15, bottom_y + 16, 10, DARKGRAY);
    DrawText(TextFormat("Renderer: %s", g_gl_renderer), UI_X + 15, bottom_y + 32, 10, DARKGRAY);
    DrawText(TextFormat("Version: %s", g_gl_version), UI_X + 15, bottom_y + 48, 10, DARKGRAY);
}

void ui_cleanup(void) {
    // Cleanup if needed
}

UIState* ui_get_state(void) {
    return &g_ui_state;
}
