//memoization
#include <bits/stdc++.h>
using namespace std;
#define nil -1
#define max 100
//lookup table
int lookup[max];
void _initialize()
{
    for (int i = 0; i < max; i++)
    {
        lookup[i] = nil;
    }
}

int fib(int n)
{
    if (lookup[n] == nil)
    {
        if (n <= 1)
        {
            lookup[n] = n;
        }
        else
        {
            lookup[n] = fib(n - 1) + fib(n - 2);
        }
    }
    return lookup[n];
}

//tabulation method(bottom-up approach)
int fibT(int n)
{
    int f[n + 1];
    int i;
    f[0] = 0;
    f[1] = 1;
    if (n < 0)
    {
        return n;
    }
    for (i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
}

int main()
{
    int num;
    cin >> num;
    _initialize();
    cout << "Fibonacii of the " << num << " is:" << fib(num);
    cout << '\n';
    cout << "Fibonacii of the " << num << " is:" << fibT(num);
    return 0;
}