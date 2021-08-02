//Friends Pairing problem
//link: https://www.geeksforgeeks.org/friends-pairing-problem/

//bottomUp approach
#include <bits/stdc++.h>
using namespace std;

int dp[100];

int pairFriends(int n)
{
    //base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

//as the above problem is similar to fibonacii .so it can be optimised.
int countFriendsPairings(int n)
{
    int a = 1, b = 2, c = 0;
    if (n <= 2)
    {
        return n;
    }
    for (int i = 3; i <= n; i++)
    {
        c = (i - 1) * a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    dp[100] = {0};
    int n;
    cin >> n;
    cout << pairFriends(n) << endl;
    cout << countFriendsPairings(n);
    return 0;
}