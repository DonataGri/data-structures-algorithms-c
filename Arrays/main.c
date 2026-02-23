#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int A[5];
    int i;

    // for (i = 0; i < 5; i++)
    // {
    //     printf("%u\n", &A[i]);
    // }

    int B[5] = {1, 2, 3, 4, 5};
    int C[10] = {2, 4, 6};
    int D[5] = {0};
    int E[] = {1, 2, 3, 4, 5, 6};

    int *p, *q;
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 4;
    p[2] = 5;
    p[3] = 6;
    p[4] = 10;

    for (i = 0; i < 5; i++)
    {
        printf("%u\n", p[i]);
    }

    q = (int *)malloc(10 * sizeof(int));

    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    };

    free(p);
    p = q;
    q = NULL;

    for (i = 0; i < 10; i++)
    {
        printf("%u\n", p[i]);
    }

    return 0;
}