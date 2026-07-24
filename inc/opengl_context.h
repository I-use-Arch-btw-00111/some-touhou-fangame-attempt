#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#include <stdint.h>

// OpenGL context initialization with AZDO support
void gl_context_init(void);
void gl_context_cleanup(void);

// AZDO rendering utilities
uint32_t gl_create_buffer(const void* data, size_t size);
void gl_delete_buffer(uint32_t buffer);

uint32_t gl_create_texture(const void* data, int width, int height);
void gl_delete_texture(uint32_t texture);

#endif // OPENGL_CONTEXT_H
