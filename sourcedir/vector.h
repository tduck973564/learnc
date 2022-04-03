#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector_ {
    int capacity;
    int elementCount;
    void** list;
} * Vector;

Vector vector_new();
void vector_push(Vector vec, void* value);
void vector_destroy(Vector vec);
void vector_destroy_members(Vector vec);
void* vector_get(Vector vec, int index);

#endif
