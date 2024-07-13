#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

struct DynamicArray {
    int* array;
    size_t size;
};

DynamicArray* DynamicArrayCreate() {
    DynamicArray* dynamicArray = malloc(sizeof(DynamicArray));
    if (!dynamicArray) {
        printf("ERROR: Failed to allocate memory\n");
        exit(1);
    }
    dynamicArray->array = NULL;
    dynamicArray->size = 0;
    return dynamicArray;
}

static void allocateAdditionalMemory(DynamicArray* dynamicArray) {
    int* array = (int*)realloc((void*)(dynamicArray->array), (dynamicArray->size + 1) * sizeof(int));
    if (!array) {
        printf("ERROR: Failed to allocate memory\n");
        exit(1);
    }
    dynamicArray->array = array;
    dynamicArray->size++;
}

int DynamicArraySize(DynamicArray* dynamicArray) {
    return dynamicArray->size;
}

int DynamicArrayGetAt(DynamicArray* dynamicArray, size_t index) {
    if (index >= dynamicArray->size) {
        printf("ERROR: index out of range\n");
        exit(1);
    }
    return dynamicArray->array[index];
}

ptrdiff_t DynamicArrayFind(DynamicArray* dynamicArray, int element) {
    for (size_t i = 0; i < dynamicArray->size; i++) {
        if (element == dynamicArray->array[i]) {
            return i;
        }
    }
    return -1;
}

void DynamicArrayInsert(DynamicArray* dynamicArray, int element, size_t index) {
    if (index > dynamicArray->size) {
        printf("ERROR: index out of range\n");
        exit(1);
    }
    allocateAdditionalMemory(dynamicArray);
    memmove(dynamicArray->array + index + 1, dynamicArray->array + index, (dynamicArray->size - index) * sizeof(int));
    dynamicArray->array[index] = element;
}

void DynamicArrayAdd(DynamicArray* dynamicArray, int element) {
    DynamicArrayInsert(dynamicArray, element, dynamicArray->size);
}

void DynamicArrayInsertArray(DynamicArray* dynamicArray, int* array, size_t arraySize, size_t index) {
    for (size_t i = 0; i < arraySize / sizeof(int); i++) {
        DynamicArrayInsert(dynamicArray, array[i], index + i);
    }
}

void DynamicArrayAddArray(DynamicArray* dynamicArray, int* array, size_t arraySize) {
    DynamicArrayInsertArray(dynamicArray, array, arraySize, dynamicArray->size);
}

void DynamicArrayRemoveAt(DynamicArray* dynamicArray, size_t index) {
    if (index >= dynamicArray->size) {
        printf("ERROR: removing non existing element\n");
        exit(1);
    }
    size_t count = index;
    while (count < dynamicArray->size) {
        dynamicArray->array[count] = dynamicArray->array[count + 1];
        count++;
    }
    dynamicArray->size--;
}

void DynamicArrayRemove(DynamicArray* dynamicArray) {
    DynamicArrayRemoveAt(dynamicArray, dynamicArray->size - 1);
}

void DynamicArrayDelete(DynamicArray* dynamicArray) {
    free(dynamicArray->array);
    free(dynamicArray);
}

static void swapElements(int* a, int* b) {
    int number = *a;
    *a = *b;
    *b = number;
}

void DynamicArrayBSort(DynamicArray* dynamicArray) {
    for (size_t i = dynamicArray->size - 1; i > 0; i--) {
        int flag = 0;
        for (size_t j = 0; j < i; j++) {
            if (dynamicArray->array[j] > dynamicArray->array[j + 1]) {
                swapElements(&dynamicArray->array[j], &dynamicArray->array[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

static void quickSort(DynamicArray* dynamicArray, ptrdiff_t lowIndex, ptrdiff_t highIndex) {
    if (lowIndex < highIndex) {
        ptrdiff_t indexLowElement = lowIndex;
        size_t pivotIndex = highIndex;
        for (size_t i = lowIndex; i < highIndex; i++) {
            if (dynamicArray->array[i] < dynamicArray->array[pivotIndex]) {
                swapElements(&dynamicArray->array[i], &dynamicArray->array[indexLowElement]);
                indexLowElement++;
            }
        }
        swapElements(&dynamicArray->array[indexLowElement], &dynamicArray->array[pivotIndex]);
        quickSort(dynamicArray, lowIndex, indexLowElement - 1);
        quickSort(dynamicArray, indexLowElement + 1, highIndex);
    } 
}

void DynamicArrayQSort(DynamicArray* dynamicArray) {
    if (dynamicArray->size > 0) {
        quickSort(dynamicArray, 0, dynamicArray->size - 1);
    }
}
