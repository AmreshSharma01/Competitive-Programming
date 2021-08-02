#include <bits/stdc++.h>
using namespace std;
//x -cost for doubling
//y -cost for increment by 1
//z -cost for dedreent by 1
long long minCost(int n, int x, int y, int z)
{
    //using bottomUp DP
    long long *dp = new long long[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        }
        else
        {
            dp[i] = min(dp[(i + 1) / 2] + x + z, dp[i - 1] + y);
        }
    }
    return dp[n];
}
int main()
{
    long long x, y, z, n;
    cin >> n;
    cin >> x >> y >> z;
    cout << minCost(n, x, y, z);
    return 0;
}