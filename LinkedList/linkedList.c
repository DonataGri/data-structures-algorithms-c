#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n, struct Node **p)
{
    int i;
    struct Node *t = NULL, *last = NULL;

    *p = (struct Node *)malloc(sizeof(struct Node));
    (*p)->data = A[0];
    (*p)->next = NULL;
    last = *p;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int rcount(struct Node *p)
{
    if (p != NULL)
    {
        return count(p->next) + 1;
    }
    return 0;
}

int sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int rsum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return rsum(p->next) + p->data;
    }
}

int max(struct Node *p)
{
    int m = -32768;

    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }

    return m;
}

int rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    x = rmax(p->next);
    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

struct Node *search(struct Node *p, int key)
{
    struct Node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }

    return NULL;
}

struct Node *rsearch(struct Node *p, int key)
{

    if (p == NULL)
    {
        return NULL;
    }

    if (key == p->data)
    {
        return p;
    }

    return rsearch(p->next, key);
}

void insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;

    if (index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {

        for (i = 0; i < index - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {

            t->next = p->next;
            p->next = t;
        }
    }
}

void sortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;

    if (index < 1 || index > count(p))
    {
        return -1;
    }

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removeDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    // points back to first
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}

void reverse3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concat(struct Node *first, struct Node *second)
{
    while (first->next != NULL)
    {
        first = first->next;
    }
    first->next = second;
    second = NULL;
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{

    int A[] = {3, 5, 8, 10, 12, 15};
    int B[] = {4, 7, 9};
    create(A, 6, &first);
    create(B, 3, &second);

    struct Node *temp = NULL;
    // temp = search(first, 7);
    // if (temp)
    // {
    //     printf("Key is found: %d \n", temp->data);
    // }
    // else
    // {
    //     printf("Key is not found \n");
    // }
    // display(first);

    printf("\n<<<<<<<<<<>>>>>>>>>>\n");
    merge(first, second);
    display(third);

    struct Node *t1, *t2;

    t1 = first->next->next;
    t2 = first->next->next->next->next->next;
    t2->next = t1;

    printf("\n%d", isLoop(first));

    return 0;
}