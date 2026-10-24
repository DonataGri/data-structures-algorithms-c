#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void InsertMax(struct Array *arr, int n)
{

    int temp, i = n;
    temp = arr->A[n];
    while (i > 1 && temp > arr->A[i / 2])
    {
        arr->A[i] = arr->A[i / 2];
        i = i / 2;
    }
    arr->A[i] = temp;
}

void InsertMin(struct Array *arr, int n)
{

    int temp, i = n;
    temp = arr->A[n];
    while (i > 1 && temp < arr->A[i / 2])
    {
        arr->A[i] = arr->A[i / 2];
        i = i / 2;
    }
    arr->A[i] = temp;
}

void createMaxHeap(struct Array *arr)
{

    int i;
    for (i = 2; i <= arr->length; i++)
    {
        InsertMax(arr, i);
    }
}

void createMinHeap(struct Array *arr)
{

    int i;
    for (i = 2; i <= arr->length; i++)
    {
        InsertMin(arr, i);
    }
}

void displayHeap(struct Array arr)
{
    int i;
    printf("\n Element in the heap are: \n");

    for (i = 1; i <= arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main(void)
{
    struct Array arr = {{0, 10, 20, 30, 25, 5, 40, 35}, 10, 7};
    // createMaxHeap(&arr);
    displayHeap(arr);
    createMinHeap(&arr);
    displayHeap(arr);
}