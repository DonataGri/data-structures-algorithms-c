#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int col;
    int value;
    struct Node *next;
};

void create()
{
    int m, n, num;
    int row, col;
    int i, j;
    struct Node *p, *q;
    printf("Enter dimensions [rows][columns]: ");
    scanf("%d%d", &m, &n);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &num);

    struct Node *A[m];
    for (i = 0; i < m; i++)
    {
        A[i] = NULL;
    }
    struct Node *el;

    printf("NUM %d \n", num);

    printf("Eneter all non-zero elements [row][col][value]: ");
    for (i = 0; i < num; i++)
    {
        el = (struct Node *)malloc(sizeof(struct Node));
        el->next = NULL;
        scanf("%d%d%d", &row, &el->col, &el->value);

        if (A[row] == NULL)
        {
            A[row] = el;
        }
        else
        {
            p = A[row];
            while (p != NULL)
            {
                q = p;
                p = p->next;
            }
            q->next = el;
            p = el;
            el->next = NULL;
        }
    }

    // display
    for (i = 0; i < m; i++)
    {

        p = A[i];
        for (j = 0; j < n; j++)
        {

            if (p != NULL && j == p->col)
            {
                printf("%d ", p->value);
                p = p->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    create();
    return 0;
}