#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
#define prDouble(x) cout << fixed << setprecision(10) << x

double dp[3001][3001];

double solve(vector<double> &arr, int i, int x)
{
    // x is the no. of heads which is >=(n+1)/2
    if (x == 0)
    {
        return 1;
    }
    if (i == 0)
    {
        return 0;
    }
    if (dp[i][x] > -0.9)
    {
        return dp[i][x];
    }
    return dp[i][x] = arr[i] * solve(arr, i - 1, x - 1) + (1 - arr[i]) * solve(arr, i - 1, x);
}
int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    vector<double> arr(n + 1);
    F(i, 1, n + 1)
    {
        cin >> arr[i];
    }
    prDouble(solve(arr, n, (n + 1) / 2));
    return 0;
}