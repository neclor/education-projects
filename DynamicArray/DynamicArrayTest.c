#include <stdio.h>
#include "DynamicArray.h"

int main() {
    DynamicArray* testArray = DynamicArrayCreate();

    DynamicArrayAdd(testArray, 2);
    DynamicArrayAdd(testArray, 1);
    DynamicArrayAdd(testArray, 0);
    DynamicArrayAdd(testArray, 8);
    DynamicArrayAdd(testArray, 9);
    DynamicArrayAdd(testArray, 10);

    printf("array: ");
    for (int i = 0; i < DynamicArraySize(testArray); i++) {
        printf("%d ", DynamicArrayGetAt(testArray, i));
    }
    printf("\n");

    DynamicArrayInsert(testArray, 4, 3);
    DynamicArrayInsert(testArray, 3, 3);
    DynamicArrayInsert(testArray, 5, 5);

    printf("array: ");
    for (int i = 0; i < DynamicArraySize(testArray); i++) {
        printf("%d ", DynamicArrayGetAt(testArray, i));
    }
    printf("\n");


    DynamicArrayRemoveAt(testArray, 4);
    DynamicArrayRemoveAt(testArray, 4);

    printf("array: ");
    for (int i = 0; i < DynamicArraySize(testArray); i++) {
        printf("%d ", DynamicArrayGetAt(testArray, i));
    }
    printf("\n");

    int arr[] = {7, 6, 5, 4, 0};

    DynamicArrayInsertArray(testArray, arr, sizeof(arr), 4);

    DynamicArrayAddArray(testArray, arr, sizeof(arr));

    printf("array: ");
    for (int i = 0; i < DynamicArraySize(testArray); i++) {
        printf("%d ", DynamicArrayGetAt(testArray, i));
    }
    printf("\n");

    DynamicArrayBSort(testArray);

    printf("array: ");
    for (int i = 0; i < DynamicArraySize(testArray); i++) {
        printf("%d ", DynamicArrayGetAt(testArray, i));
    }
    printf("\n");




    printf("BSort TEST\n");

    DynamicArray* testArray2 = DynamicArrayCreate();

    int arr2[] = { 5, 4, 3, 2, 1, 0, -1};
    DynamicArrayAddArray(testArray2, arr2, sizeof(arr2));

    printf("array2: ");
    for (int i = 0; i < DynamicArraySize(testArray2); i++) {
        printf("%d ", DynamicArrayGetAt(testArray2, i));
    }
    printf("\n");

    DynamicArrayBSort(testArray2);

    printf("array2: ");
    for (int i = 0; i < DynamicArraySize(testArray2); i++) {
        printf("%d ", DynamicArrayGetAt(testArray2, i));
    }
    printf("\n");


    printf("QSort TEST\n");

    DynamicArray* testArray3 = DynamicArrayCreate();

    int arr3[] = { 5, 4, 3, 2, 1, 0, -1, 3 };
    DynamicArrayAddArray(testArray3, arr3, sizeof(arr3));

    printf("array3: ");
    for (int i = 0; i < DynamicArraySize(testArray3); i++) {
        printf("%d ", DynamicArrayGetAt(testArray3, i));
    }
    printf("\n");

    DynamicArrayQSort(testArray3);

    printf("array3: ");
    for (int i = 0; i < DynamicArraySize(testArray3); i++) {
        printf("%d ", DynamicArrayGetAt(testArray3, i));
    }
    printf("\n");
}
