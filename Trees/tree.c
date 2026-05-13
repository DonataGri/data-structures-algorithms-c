#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void create()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmptyQueue(q))
    {
        p = dequeue(&q);
        printf("enter left child of %d :", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("enter right child of %d :", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {

        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {

        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void iPreorder(struct Node *p)
{
    struct Stack st;
    createStack(&st, 100);

    while (p || !isEmptyStack(st))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void iInorder(struct Node *p)
{
    struct Stack st;
    createStack(&st, 100);

    while (p || !isEmptyStack(st))
    {
        if (p)
        {

            push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void levelOrder(struct Node *root)
{
    struct Queue q;
    createQueue(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmptyQueue(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }

        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int countLeaf(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (!p->lchild && !p->rchild)
    {
        return 1;
    }
    return countLeaf(p->lchild) + countLeaf(p->rchild);
}

int countDegreeTwo(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->lchild && p->rchild)
    {
        return countDegreeTwo(p->lchild) + countDegreeTwo(p->rchild) + 1;
    }
    else
    {
        return countDegreeTwo(p->lchild) + countDegreeTwo(p->rchild);
    }
    return 0;
}

int countDegreeOne(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if ((p->lchild != NULL) ^ (p->rchild != NULL))
    {
        return countDegreeOne(p->lchild) + countDegreeOne(p->rchild) + 1;
    }
    else
    {
        return countDegreeOne(p->lchild) + countDegreeOne(p->rchild);
    }
    return 0;
}

int countDegreeOneTwo(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->lchild || p->rchild)
    {
        return countDegreeOneTwo(p->lchild) + countDegreeOneTwo(p->rchild) + 1;
    }
    else
    {
        return countDegreeOneTwo(p->lchild) + countDegreeOneTwo(p->rchild);
    }
    return 0;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
    {
        return 0;
    }

    x = height(root->lchild);
    y = height(root->rchild);

    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int main(void)
{
    create();

    printf("Count %d ", countDegreeOneTwo(root));

    printf("Height %d ", height(root));

    printf("\n Level order >>>>>");
    levelOrder(root);

    // printf("\n Post Order >>>>>");
    // postorder(root);
    return 0;
}