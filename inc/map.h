#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include <raylib.h>

// Map tile structure
typedef struct {
    uint8_t type;      // Terrain type (0=grass, 1=water, 2=rock, etc.)
} MapTile;

// Map manager with infinite scrolling
typedef struct {
    MapTile* tiles;        // Dynamic tile array
    int num_tiles_y;       // Height of loaded map
    float scroll_y;        // Current scroll position (world Y)
    int last_chunk_index;  // Last generated chunk index
} Map;

// Function declarations
Map* map_create(void);
void map_destroy(Map* map);
void map_update(Map* map, float dt);
void map_render(Map* map);

#endif // MAP_H
