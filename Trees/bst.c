#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
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

struct Node *search(int key)
{
    struct Node *t = root;

    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node *rInsert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }

    return p;
}

int height(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *inPre(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

struct Node *inSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

struct Node *delete(struct Node *p, int key)
{

    struct Node *q;

    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = delete(p->rchild, key);
    }
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = delete(p->lchild, q->data);
        }
        else
        {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = delete(p->rchild, q->data);
        }
    }
    return p;
}

int main(void)
{
    struct Node *temp;
    root = rInsert(root, 50);
    rInsert(root, 10);
    rInsert(root, 40);
    rInsert(root, 20);
    rInsert(root, 30);

    root = delete(root, 40);

    inorder(root);
    printf("\n");

    temp = search(8);
    if (temp != NULL)
    {
        printf("Element %d is found\n", temp->data);
    }
    else
    {
        printf("Element is not found");
    }

    return 0;
}