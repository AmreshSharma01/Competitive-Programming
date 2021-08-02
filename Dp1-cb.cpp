#include <bits/stdc++.h>
using namespace std;

//1.recursion + memoization(top down Approach)
int fib(int n, int lookup[])
{
    if (n == 0 or n == 1)
    {
        return n;
    }
    if (lookup[n] != 0)
    {
        return lookup[n];
    }
    int ans;
    ans = fib(n - 1, lookup) + fib(n - 2, lookup);
    return lookup[n] = ans;
}

//2.bottomUp approach
int Fib(int n)
{
    int lookUp[100] = {0};

    lookUp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        lookUp[i] = lookUp[i - 1] + lookUp[i - 2];
    }
    return lookUp[n];
}
int SpaceOptimized(int n)
{

    if (n == 0 or n == 1)
    {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    int lookup[100] = {0};
    cout << fib(n, lookup);
    cout << endl
         << "BottomUp Approach:\n";
    cout << Fib(n);
    cout << "\n"
         << "Optimized Solution:"
         << SpaceOptimized(n);
    return 0;
}