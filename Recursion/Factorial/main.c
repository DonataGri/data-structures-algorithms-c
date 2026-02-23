#include <stdio.h>

// 1 * 2 * 3 * 4 * 5 * 6 * 7
// fact(n-1)*n

int factR(int n)
{

    if (n < 0)
    {
        return 0;
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (n > 1)
    {

        return factR(n - 1) * n;
    }
    return 0;
}

int factL(int n)
{

    int i;
    int f = 1;

    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (n > 1)
        for (int i; i <= n; i++)
        {
            f = f * i;
        }

    return f;
}

int main()
{

    int x = 5;

    int factorialR = factR(x);
    printf("%d ", factorialR);
    int factorialL = factL(x);
    printf("%d ", factorialL);

    return 0;
}