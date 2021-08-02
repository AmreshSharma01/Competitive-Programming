//Ladder's Problem
#include <bits/stdc++.h>
using namespace std;

//top down approach(recursion +memoziation)
int ladder_prob(int n, int k, int dp[])
{
    //base case
    if (n == 0)
    {
        return 1;
    }
    //lookup array
    if (dp[n] != 0)
    {
        return dp[n];
    }
    //recursive case
    int ways = 0;
    for (int i = 1; i <= k; i++) //here i=jumps(variable),k=maximum jump value
    {
        if (n - i >= 0)
        {
            ways += ladder_prob(n - i, k, dp);
        }
    }
    return dp[n] = ways;
}
//bottom Up approach
int ladder_probB(int n, int k)
{
    int dp[100] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++) //j=jump(variable),k=maximum jump value
            if (i - j >= 0)
            {

                dp[i] += dp[i - j];
            }
    }
    return dp[n];
}
// optimized approach
int ladder_prob1(int n, int k)
{
    int dp[100] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    //print
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
}
int main()
{
    int k, n;
    int dp1[100] = {0};
    cin >> n >> k;
    cout << ladder_prob(n, k, dp1);
    cout << endl;
    cout << ladder_probB(n, k);
    cout << ladder_prob1(n, k);
    return 0;
}
