#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int Get(struct Matrix *m, int i, int j)
{
    if (i >= j)
    {
        return m->A[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    int i, j;

    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                printf("%3d ", Get(&m, i, j));
            }
            else
            {
                printf("%3d ", 0);
            }
        }
        printf("\n");
    }
}

int main(void)
{
    struct Matrix m;
    printf("Enter dimension of matrix: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter all elements: \n");
    int i, j, x;
    for (i = 1; i <= m.n; i++)
    {
        printf("\nSet %d row: ", i);
        for (j = 1; j <= i; j++)
        {

            scanf("%d", &x);
            printf("Matrix index for x = %d: [%d][%d]\n", x, i, j);
            Set(&m, i, j, x);
        }
    }

    printf("\n\n");
    Display(m);

    free(m.A);

    return 0;
}