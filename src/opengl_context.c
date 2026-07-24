#include "opengl_context.h"
#include "config.h"
#include <raylib.h>
#include <GL/gl.h>
#include <stdio.h>

// OpenGL context initialization with AZDO configuration
void gl_context_init(void) {
    // Note: Raylib abstracts OpenGL context creation.
    // To use OpenGL 4.4 with CONTEXT_RELEASE_BEHAVIOR_NONE,
    // you may need to configure before InitWindow().
    // This is a placeholder for custom context setup if needed.
    
    printf("Initializing OpenGL context (4.4 AZDO mode)...\n");
    
    // After InitWindow(), you can query the context:
    // glGetIntegerv(GL_MAJOR_VERSION, &major);
    // glGetIntegerv(GL_MINOR_VERSION, &minor);
}

void gl_context_cleanup(void) {
    printf("Cleaning up OpenGL context...\n");
    // Cleanup AZDO resources here
}

// AZDO Buffer Creation (Direct State Access)
uint32_t gl_create_buffer(const void* data, size_t size) {
    uint32_t buffer = 0;
    glCreateBuffers(1, &buffer);
    glNamedBufferStorage(buffer, size, data, GL_DYNAMIC_STORAGE_BIT);
    return buffer;
}

void gl_delete_buffer(uint32_t buffer) {
    glDeleteBuffers(1, &buffer);
}

// AZDO Texture Creation (Direct State Access)
uint32_t gl_create_texture(const void* data, int width, int height) {
    uint32_t texture = 0;
    glCreateTextures(GL_TEXTURE_2D, 1, &texture);
    glTextureStorage2D(texture, 1, GL_RGBA8, width, height);
    if (data) {
        glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    return texture;
}

void gl_delete_texture(uint32_t texture) {
    glDeleteTextures(1, &texture);
}
