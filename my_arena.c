// https://grok.com/share/c2hhcmQtMg%3D%3D_f50ca157-a7e2-477a-88bf-e5e41b68ec38

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "my_arena.h"

#define MEM_SIZE_BYTES 1024

// Example struct to initialize
typedef struct MyObject
{
    int id;
    float value;
} MyObject;

int main()
{
    mem_arena_t arena;
    arena_init(&arena);

    // Allocate memory for MyObject
    printf("To allocate the objecy of size: %lu bytes\n", sizeof(MyObject));
    MyObject* obj = arena_alloc(&arena, sizeof(MyObject));
    
    obj->id = 42;
    obj->value = 3.14f;

    printf("Object: id=%d, value=%f\n", obj->id, obj->value);
    
    arena_reset(&arena);
    arena_free(&arena);
    
    return 0;
}