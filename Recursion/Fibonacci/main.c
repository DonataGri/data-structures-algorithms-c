#include <stdio.h>

int F[10];
// fib(n-2)+fib(n-1);
int fib(int n)
{

    if (n <= 0)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fib(n - 2);
        }

        if (F[n - 1] == -1)
        {
            F[n - 1] = fib(n - 1);
        }

        return F[n - 2] + F[n - 1];
    }

    return fib(n - 2) + fib(n - 1);
};

int fibLoop(int n)
{
    if (n <= 1)
    {
        return n;
    };

    int a = 0;
    int b = 1;
    int sum = 0;

    for (int i = 2; i <= n; i++)
    {

        sum = a + b;
        a = b;
        //  b = a + b;
        b = sum;
    };

    return sum;
}

int main()
{

    // int x = 7;
    // int sum = fibLoop(x);
    // printf("%d", sum);

    int y = 7;
    int sumFib = fib(y);
    printf("%d", sumFib);

    return 0;
}