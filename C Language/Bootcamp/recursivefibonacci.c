#include <stdio.h>
int main()
{
    int n, f;
    scanf("%d", &n);
    f = fib(n);
    printf("%d", f);
}

int fib(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}