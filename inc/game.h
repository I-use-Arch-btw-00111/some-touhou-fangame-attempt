#ifndef GAME_H
#define GAME_H

#include <stdint.h>

// Game state structure
typedef struct {
    int is_running;
    float time_elapsed;
    uint32_t frame_count;
} GameState;

// Function declarations
void game_init(void);
void game_update(float dt);
void game_render(void);
void game_cleanup(void);

#endif // GAME_H
