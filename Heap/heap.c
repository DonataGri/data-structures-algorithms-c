#include <stdlib.h>
#include <stdio.h>

struct Heap
{
    int *data;
    int size;
    int capacity;
};

void InsertMax(struct Heap *h, int n)
{

    int temp, i = n;
    temp = h->data[i];
    while (i > 0 && temp > h->data[(i - 1) / 2])
    {
        h->data[i] = h->data[(i - 1) / 2];
        // move to parent
        i = (i - 1) / 2;
    }
    h->data[i] = temp;
}

void InsertMin(struct Heap *h, int n)
{

    int temp, i = n;
    temp = h->data[n];
    while (i > 0 && temp < h->data[(i - 1) / 2])
    {
        h->data[i] = h->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->data[i] = temp;
}

void pushMax(struct Heap *h, int value)
{

    if (h->size >= h->capacity)
    {
        return;
    }
    h->data[h->size] = value;
    InsertMax(h, h->size);
    h->size++;
}

void pushMin(struct Heap *h, int value)
{

    if (h->size >= h->capacity)
    {
        return;
    }
    h->data[h->size] = value;
    InsertMin(h, h->size);
    h->size++;
}

void displayHeap(struct Heap h)
{
    int i;
    printf("\n Element in the heap are: \n");

    for (i = 0; i < h.size; i++)
    {
        printf("%d ", h.data[i]);
    }
    printf("\n");
}

void displayRaw(struct Heap h)
{
    int i;
    printf("\n Element in the heap are: \n");

    for (i = 0; i < h.capacity; i++)
    {
        printf("%d ", h.data[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int DeleteMax(struct Heap *h)
{
    if (h->size == 0)
    {
        return -1;
    }

    int i, j, x;
    int n = h->size - 1;
    int top = h->data[0];
    h->data[0] = h->data[n];
    h->size--;

    i = 0;
    j = 2 * i + 1;

    while (j < n)
    {
        if (j + 1 < n)
        {
            if (h->data[j + 1] > h->data[j])
            {
                j = j + 1;
            }
        }
        if (h->data[i] < h->data[j])
        {
            swap(&h->data[i], &h->data[j]);
            i = j;
            j = 2 * j + 1;
        }
        else
        {
            break;
        }
    }
    h->data[n] = top;
    return top;
}

int DeleteMin(struct Heap *h)
{
    if (h->size == 0)
    {
        return -1;
    }

    int i, j, x;
    int n = h->size - 1;
    int top = h->data[0];
    h->data[0] = h->data[n];
    h->size--;

    i = 0;
    j = 2 * i + 1;

    while (j < n)
    {
        if (j + 1 < n)
        {
            if (h->data[j + 1] < h->data[j])
            {
                j = j + 1;
            }
        }
        if (h->data[i] > h->data[j])
        {
            swap(&h->data[i], &h->data[j]);
            i = j;
            j = 2 * j + 1;
        }
        else
        {
            break;
        }
    }
    h->data[n] = top;
    return top;
}

int main(void)
{
    int capacity = 10;
    int *arr = malloc(capacity * sizeof(int));
    struct Heap h = {arr, 0, capacity};

    displayHeap(h);
    pushMin(&h, 5);
    pushMin(&h, 10);
    pushMin(&h, 12);
    pushMin(&h, 15);
    pushMin(&h, 25);
    pushMin(&h, 30);
    pushMin(&h, 45);
    displayHeap(h);

    DeleteMin(&h);
    DeleteMin(&h);
    DeleteMin(&h);
    DeleteMin(&h);
    // Delete(&h);
    // Delete(&h);
    // Delete(&h);
    // Delete(&h);

    displayHeap(h);
    displayRaw(h);

    free(arr);
    return 0;
}