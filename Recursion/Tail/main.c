#include <stdio.h>

void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
    }
}

void funLoop(int n)
{
    while (n > 0)
    {
        printf("%d ", n);
        n--;
    }
}

int main()
{

    int x = 5;

    fun(x);
    printf("\n");
    funLoop(x);

    return 0;
}