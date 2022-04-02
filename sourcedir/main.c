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
    
    char* boso = calloc(9, sizeof(char)); strncpy(boso, "RIP BOZO", sizeof(char) * 9);
    vector_push(vector, boso);

    printf("string in vector: %s\n", (char*)vector_get(vector, 100));

    printf("vector capacity: %d\n", vector->capacity);
    
    vector_destroy_members(vector);

    return 0;
}
