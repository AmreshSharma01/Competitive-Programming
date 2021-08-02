#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
int minCost(vector<int> arr, int n)
{
    vector<int> dp(n + 1);
    dp[1] = 0;
    F(i, 2, n + 1)
    {
        // reaching to i from i-1
        int option1 = abs(arr[i] - arr[i - 1]) + dp[i - 1];
        //reaching to i from i-2

        // note:for 2nd position we can only reach from 1st position
        int option2 = (i == 2) ? inf : abs(arr[i] - arr[i - 2]) + dp[i - 2];
        dp[i] = min(option1, option2);
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = minCost(arr, n);
    cout << ans;
    return 0;
}