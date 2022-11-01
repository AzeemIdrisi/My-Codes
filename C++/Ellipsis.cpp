// Variable number of arguments in function
#include <iostream>
#include <stdarg.h>

using namespace std;

int sum(int n, ...)
{
    va_list list;
    va_start(list, n);

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += va_arg(list, int);
    }
    va_end(list);
    return s;
}

int main()
{
    int x = sum(5, 1, 2, 3, 4, 5);
    cout << x << endl;
}