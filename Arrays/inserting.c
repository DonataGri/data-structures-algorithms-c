#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{

    int i;
    printf("\nElements are: \n");

    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
};

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index <= arr->length)
    {

        x = arr->A[index];
        for (i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            // swap(&arr->A[i], &arr->A[i - 1]); // transposition
            swap(&arr->A[i], &arr->A[0]); //  move to head
            return i;
        }
    }
    return -1;
};

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }

    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;

    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;

    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{

    int sum = 0;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }

    return sum;
}

float Avg(struct Array arr)
{
    return (float)(Sum(arr) / arr.length);
}

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
    int i, j, temp;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void ReverseRange(struct Array *arr, int start, int end)
{
    int i, j, temp;
    for (i = start, j = end - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void ShiftLeft(struct Array *arr)
{
    if (arr->length == 0)
        return;

    int i;
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[arr->length - 1] = 0;
}

// O(n)
void ShiftLeftByN(struct Array *arr, int n)
{
    if (arr->length == 0)
        return;

    if (n < 0 || n == 0)
        return;

    int i = 0;
    // if n > arr->length for loop does not start
    for (; i < arr->length - n; i++)
    {
        arr->A[i] = arr->A[i + n];
    }

    for (; i < arr->length; i++)
    {
        arr->A[i] = 0;
    }
}

void RotateLeft(struct Array *arr)
{
    if (arr->length == 0)
        return;

    int i;
    int first = arr->A[0];
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[arr->length - 1] = first;
}

void RotateLeftByN(struct Array *arr, int n)
{
    if (arr->length == 0)
        return;

    if (n < 0)
        return;

    n = n % arr->length;

    if (n == 0)
        return;

    // int i;
    // int j;
    // int temp[n];

    // for (j = 0; j < n; j++)
    // {
    //     temp[j] = arr->A[j];
    // }

    // for (i = 0; i < arr->length - n; i++)
    // {

    //     arr->A[i] = arr->A[i + n];
    // }

    // for (j = 0; i < arr->length; i++, j++)
    // {
    //     arr->A[i] = temp[j];
    // }

    ReverseRange(arr, 0, n);
    ReverseRange(arr, n, arr->length);
    Reverse2(arr);

    // n = 3;

    // [23,3,14,25,6] -> [25,6,23,3,14]
    // [3,23,6,25,14]
    // [14,25,6,23,3]
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;

    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }

        while (arr->A[j] >= 0)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main(void)
{

    struct Array arr = {{23, 3, 14, 25, 6}, 10, 5};
    struct Array arr2 = {{1, 2, 5, 6, 7, 14}, 10, 5};
    struct Array arr3 = {{-6, 3, -2, 6, 7, -3, -1}, 10, 7};
    struct Array sortedA = {{3, 8, 16, 20, 25}, 5, 5};
    struct Array sortedB = {{4, 16, 12, 25, 23}, 5, 5};
    struct Array *merged;
    struct Array *unionArr;
    struct Array *intersectionArr;
    struct Array *differenceArr;
    // Append(&arr, 10);
    // Insert(&arr, 2, 35);
    // Display(arr);
    // printf("%d\n", Delete(&arr, 3));
    // printf("%d\n", LinearSearch(&arr, 6));
    // printf("%d\n", LinearSearch(&arr, 6));
    // printf("%d\n", LinearSearch(&arr, 6));

    // printf("%d\n", Get(arr, 2));
    // printf("%d\n", Max(arr));
    // printf("%d\n", Min(arr));
    // printf("%d\n", Sum(arr));
    // printf("%f\n", Avg(arr));
    // Set(&arr, 1, 22);
    // Reverse2(&arr);
    // RotateLeft(&arr);
    // RotateLeftByN(&arr, 2);
    InsertSort(&arr2, 4);

    Display(arr2);
    printf("\n%d\n", isSorted(arr));
    Rearrange(&arr3);
    Display(arr3);
    merged = Merge(&sortedA, &sortedB);
    Display(*merged);
    unionArr = Union(&sortedA, &sortedB);
    Display(*unionArr);
    intersectionArr = Intersection(&sortedA, &sortedB);
    Display(*intersectionArr);
    differenceArr = Difference(&sortedA, &sortedB);
    Display(*differenceArr);
    return 0;
}