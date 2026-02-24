#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;

} *first;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

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

int length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int findMiddleElement(struct Node *p)
{
    int i;
    int pos = (length(p) - 1) / 2;

    for (i = 0; i < pos; i++)
    {
        p = p->next;
    }
    return p->data;
}

int findMiddleElementOneScan(struct Node *p)
{
    struct Node *q = p;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }

        if (q)
        {
            p = p->next;
        }
    }
    return p->data;
}

// implement later
// int findMiddleElementStack(struct Node *p)

int main(void)
{
    int A[] = {8, 6, 3, 9, 10};
    create(A, 5);
    printf("%d \n", findMiddleElement(first));
    printf("%d \n", findMiddleElementOneScan(first));
    display(first);
    return 0;
}