#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Vector_ {
    int capacity;
    int elementCount;
    void** list;
} * Vector;

void increase_capacity(Vector vec)
{
    vec->capacity = vec->capacity * 2;

    vec->list = realloc(vec->list, sizeof(void*) * vec->capacity);
    if (!vec->list) exit(1);

    memset(&vec->list[vec->elementCount], 0, sizeof(void*) * (vec->capacity - vec->elementCount));
}

Vector vector_new()
{
    Vector vec = malloc(sizeof(struct Vector_));
    vec->capacity = 128;
    vec->elementCount = 0;
    vec->list = calloc(vec->capacity, sizeof(void*));

    return vec;
}

void* vector_get(Vector vec, int index)
{
    return index <= vec->capacity ? vec->list[index] : NULL;
}

void vector_push(Vector vec, void* value)
{
    if (vec->elementCount >= vec->capacity) {
        increase_capacity(vec);
    }

    vec->list[vec->elementCount] = value;
    vec->elementCount += 1;
}

void vector_destroy(Vector vec) 
{
    free(vec->list);
    free(vec);
}

void vector_destroy_members(Vector vec) 
{
    for (int i = 0; i <= vec->capacity; i++) {
        free(vector_get(vec, i));
    }
    vector_destroy(vec);
}
