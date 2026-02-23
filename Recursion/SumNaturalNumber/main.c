#include <stdio.h>

// 1 + 2 + 3 + 4 + 5 + 6 +7

int factR(int n)
{

    if (n > 0)
    {

        return factR(n - 1) + n;
    }
    return 0;
}

int funF(int n)
{
    if (n > 0)
    {
        return (n * (n + 1)) / 2;
    }

    return 0;
}

int factL(int n)
{
    int i, sum = 0;
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            sum = sum + i;
        }
    }
    return sum;
}

int main()
{

    int x = 7;

    int sumR = factR(x);
    int sumF = funF(x);
    int sumL = factL(x);
    printf("%d ", sumR);
    printf("%d ", sumF);
    printf("%d ", sumL);

    return 0;
}