#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{

    if (i <= j)
    {
        m->A[((i - 1) * m->n) - ((i - 2) * (i - 1) / 2) + j - i] = x;
    }
};

int Get(struct Matrix *m, int i, int j)
{
    if (i <= j)
    {
        return m->A[((i - 1) * m->n) - ((i - 2) * (i - 1) / 2) + j - i];
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
            if (i <= j)
            {
                printf("%d ", m.A[((i - 1) * m.n) - ((i - 2) * (i - 1) / 2) + j - i]);
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
    struct Matrix m;
    printf("Eneter dimension");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter all elements ");
    int i, j, x;
    for (i = 1; i <= m.n; i++)
    {
        // enter values with zeros 1 0 0 ; 1 2 0 ; 1 2 3;
        // for (j = 1; j <= m.n; j++)
        // enter only on-zero values 1; 1 2; 1 2 3
        for (j = i; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }

    printf("\n\n");

    Display(m);

    return 0;
};