#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MEM_SIZE_BYTES 1024

typedef struct MemArena
{
    uint8_t data[MEM_SIZE_BYTES];
    size_t bytes_used; 
} mem_arena_t;

void arena_free(mem_arena_t* arena);
void arena_init(mem_arena_t* arena);
void arena_reset(mem_arena_t* arena);

// Return a valid pointer from the arena
void* arena_alloc(mem_arena_t* arena, size_t size)
{
    if (arena->bytes_used + size > MEM_SIZE_BYTES)
    {
        return NULL; // OOM
    }
    void* ptr = &arena->data[arena->bytes_used];
    printf("Allocating data at %p\n", ptr);
    printf("Arena size before: %lu\n", arena->bytes_used);
    arena->bytes_used += size;
    printf("Arena size after:  %lu\n", arena->bytes_used);
    
    return ptr;
}

// Initialize the arena
void arena_free(mem_arena_t* arena)
{
    arena->bytes_used = 0;
}

void arena_init(mem_arena_t* arena)
{
    arena_free(arena);
}

void arena_reset(mem_arena_t* arena)
{
    memset(arena->data, 0, MEM_SIZE_BYTES);
}
