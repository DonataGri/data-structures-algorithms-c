#include <stdio.h>

// pow(m,n) = pow(m,n-1) * m;

int powF(int m, int n)
{

    if (n == 0)
    {
        return 1;
    }

    return powF(m, n - 1) * m;
}

int powF2(int m, int n)
{

    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return powF2(m * m, n / 2);
    }
    else
    {
        return m * powF2((m * m), (n - 1) / 2);
    }

    return 0;
}

int main()
{

    int x = 2;
    int y = 5;

    int powResult = powF(x, y);
    printf("%d\n", powResult);

    int powResult2 = powF2(x, y);
    printf("%d\n", powResult2);

    return 0;
}