// See link: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

// Fibonacci Series using Space Optimized Method
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int a = 0, b = 1, c, i;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Driver code
int main()
{
    int n = 9;
    for (int i = 0; i <= n; i++)
    {
        cout << fib(i) << " ";
    }
    return 0;
}