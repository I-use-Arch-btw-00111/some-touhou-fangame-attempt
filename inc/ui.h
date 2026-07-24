#ifndef UI_H
#define UI_H

#include <stdint.h>

// UI state structure
typedef struct {
    uint32_t points;
    uint8_t hearts;          // 0-8
    uint8_t bombs;           // 0-8
    uint32_t graze;
} UIState;

// Function declarations
void ui_init(void);
void ui_render(float time_elapsed, uint32_t frame_count, float fps);
void ui_cleanup(void);

// Getters/Setters
UIState* ui_get_state(void);

#endif // UI_H
