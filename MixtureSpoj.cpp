#include <bits/stdc++.h>
using namespace std;
int a[1000];
long long dp[1000][1000];

long long cumlatSum(int s, int e)
{
    long long ans = 0;
    for (int i = s; i <= e; i++)
    {
        ans += a[i];
        ans %= 100;
    }
    return ans;
}
long long solveMixtures(int i, int j)
{
    //base case
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    //we have to break expression at every possible k
    for (int k = i; k <= j; k++)
    {
        dp[i][j] = min(dp[i][j], solveMixtures(i, k) + solveMixtures(k + 1, j) + cumlatSum(i, k) * cumlatSum(k + 1, j));
    }
    return dp[i][j];
}
int main()
{
    int n;
    while ((scanf("%d", &n)) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        //initializing dp 2-d array as -1
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << solveMixtures(0, n - 1) << endl;
        }
    return 0;
}
