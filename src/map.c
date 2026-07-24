#include "map.h"
#include "config.h"
#include <stdlib.h>
#include <math.h>

#define TILE_SIZE 32
#define ISOMETRIC_ANGLE 40.0f
#define MAP_COLOR_GRASS (Color){34, 139, 34, 255}
#define MAP_COLOR_WATER (Color){30, 144, 255, 255}
#define MAP_COLOR_ROCK (Color){128, 128, 128, 255}

// Helper function to convert 3D world position to 2D isometric screen position
static void world_to_isometric(float x, float y, float z, float* screen_x, float* screen_y) {
    // Isometric projection at 40 degrees
    float rad = ISOMETRIC_ANGLE * PI / 180.0f;
    
    // Apply isometric transformation
    *screen_x = (x - y) * cosf(rad);
    *screen_y = (x + y) * sinf(rad) - z * TILE_SIZE * 0.5f;
}

// Get color for tile type
static Color get_tile_color(uint8_t type) {
    switch (type) {
        case 1: return MAP_COLOR_WATER;
        case 2: return MAP_COLOR_ROCK;
        default: return MAP_COLOR_GRASS;
    }
}

Map* map_create(int width, int height) {
    Map* map = (Map*)malloc(sizeof(Map));
    map->num_chunks = (width * height) / 256;  // 16x16 tiles per chunk
    map->chunks = (MapChunk*)calloc(map->num_chunks, sizeof(MapChunk));
    map->camera_distance = 0.0f;
    
    // Generate simple procedural map
    for (int c = 0; c < map->num_chunks; c++) {
        for (int y = 0; y < 16; y++) {
            for (int x = 0; x < 16; x++) {
                MapTile* tile = &map->chunks[c].tiles[y][x];
                
                // Simple pattern: mostly grass with some water
                int seed = (x + y + c * 256) % 7;
                if (seed == 0) {
                    tile->type = 1;  // Water
                    tile->height = -1;
                } else if (seed == 1) {
                    tile->type = 2;  // Rock
                    tile->height = 2;
                } else {
                    tile->type = 0;  // Grass
                    tile->height = 0;
                }
            }
        }
    }
    
    return map;
}

void map_destroy(Map* map) {
    if (map) {
        free(map->chunks);
        free(map);
    }
}

void map_update(Map* map, float dt) {
    // Auto-scroll the map (simulate player movement)
    map->camera_distance += 100.0f * dt;  // Scroll at 100 pixels/sec
}

void map_render(Map* map) {
    // Calculate visible tile range based on scroll position
    float scroll_y = map->camera_distance / (TILE_SIZE * 2.0f);
    
    // Render tiles
    for (int c = 0; c < map->num_chunks; c++) {
        for (int ty = 0; ty < 16; ty++) {
            for (int tx = 0; tx < 16; tx++) {
                MapTile* tile = &map->chunks[c].tiles[ty][tx];
                
                // Calculate world position
                float world_x = (c * 16 + tx) * TILE_SIZE;
                float world_y = ty * TILE_SIZE - scroll_y * TILE_SIZE;
                float world_z = tile->height * TILE_SIZE;
                
                // Convert to isometric screen coordinates
                float screen_x, screen_y;
                world_to_isometric(world_x, world_y, world_z, &screen_x, &screen_y);
                
                // Offset to gameplay area center
                screen_x += GAMEPLAY_X + GAMEPLAY_WIDTH / 2;
                screen_y += GAMEPLAY_Y + GAMEPLAY_HEIGHT / 2;
                
                // Cull off-screen tiles
                if (screen_x < GAMEPLAY_X - TILE_SIZE || screen_x > GAMEPLAY_X + GAMEPLAY_WIDTH ||
                    screen_y < GAMEPLAY_Y - TILE_SIZE || screen_y > GAMEPLAY_Y + GAMEPLAY_HEIGHT) {
                    continue;
                }
                
                // Draw tile as diamond shape (isometric)
                Color tile_color = get_tile_color(tile->type);
                
                // Isometric diamond vertices
                Vector2 v1 = {screen_x, screen_y - TILE_SIZE / 2};
                Vector2 v2 = {screen_x + TILE_SIZE / 2, screen_y};
                Vector2 v3 = {screen_x, screen_y + TILE_SIZE / 2};
                Vector2 v4 = {screen_x - TILE_SIZE / 2, screen_y};
                
                // Draw filled diamond
                DrawTriangle(v1, v2, v3, tile_color);
                DrawTriangle(v1, v3, v4, tile_color);
                
                // Draw border
                DrawLineV(v1, v2, DARKGRAY);
                DrawLineV(v2, v3, DARKGRAY);
                DrawLineV(v3, v4, DARKGRAY);
                DrawLineV(v4, v1, DARKGRAY);
            }
        }
    }
}

void map_scroll(Map* map, float distance) {
    map->camera_distance += distance;
}
