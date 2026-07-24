#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include <raylib.h>

// Map tile structure
typedef struct {
    uint8_t type;      // Terrain type (0=grass, 1=water, 2=rock, etc.)
    int8_t height;     // Height level for 2.5D
} MapTile;

// Map chunk (for scrolling)
typedef struct {
    MapTile tiles[16][16];  // 16x16 tiles per chunk
    float scroll_offset;    // Scrolling position
} MapChunk;

// Map manager
typedef struct {
    MapChunk* chunks;
    int num_chunks;
    float camera_distance;  // Camera distance along scroll axis
} Map;

// Function declarations
Map* map_create(int width, int height);
void map_destroy(Map* map);
void map_update(Map* map, float dt);
void map_render(Map* map);
void map_scroll(Map* map, float distance);

#endif // MAP_H
