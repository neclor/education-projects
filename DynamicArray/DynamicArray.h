#pragma once
#include <stdlib.h>

typedef struct DynamicArray DynamicArray;

DynamicArray* DynamicArrayCreate();

size_t DynamicArraySize(DynamicArray* dynamicArray);

int DynamicArrayGetAt(DynamicArray* dynamicArray, size_t index);

ptrdiff_t DynamicArrayFind(DynamicArray* dynamicArray, int element);

void DynamicArrayInsert(DynamicArray* dynamicArray, int element, size_t index);

void DynamicArrayAdd(DynamicArray* dynamicArray, int element);

void DynamicArrayInsertArray(DynamicArray* dynamicArray, int* array, size_t arraySize, size_t index);

void DynamicArrayAddArray(DynamicArray* dynamicArray, int* array, size_t arraySize);

void DynamicArrayRemoveAt(DynamicArray* dynamicArray, size_t index);

void DynamicArrayRemove(DynamicArray* dynamicArray);

void DynamicArrayDelete(DynamicArray* dynamicArray);

void DynamicArrayBSort(DynamicArray* dynamicArray);

void DynamicArrayQSort(DynamicArray* dynamicArray);
