#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    head->prev = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
    head->prev = last;
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
    printf("\n");
}

int length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void insert(struct Node *h, int pos, int x)
{
    int i;
    struct Node *t, *p;
    if (pos < 0 || pos > length(h))
    {
        return;
    }

    if (pos == 0)

    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        if (h == NULL)
        {
            h = t;
            h->next = h;
            h->prev = h;
        }
        else
        {
            h->prev->next = t;
            t->next = h;
            t->prev = h->prev;
            h->prev = t;
            head = t;
        }
    }
    else
    {
        p = h;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}

int main()
{

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    insert(head, 0, 61);
    display(head);
    return 0;
}