#include <stdio.h>

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        printf("%d ", n);
    }
}

void funLoop(int n)
{
    int i = 1;
    while (i <= n)
    {

        printf("%d ", i);
        i++;
    }
}

int main()
{

    int x = 3;

    fun(x);
    printf("\n");
    funLoop(x);

    return 0;
}