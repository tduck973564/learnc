#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
int main() {
    Vector vector = vector_new();
    
    for (int i = 0; i < 100; i++) {
        int* clonedNumber = malloc(sizeof(int));
        memcpy(clonedNumber, &i, sizeof(int));

        vector_push(vector, clonedNumber);
    }

    for (int i = 0; i < vector->elementCount; i++) {
        printf("%d\n", *(int*)vector_get(vector, i));
    }
    
    printf("vector capacity: %d\n", vector->capacity);
    
    vector_destroy_members(vector);

    return 0;
}

