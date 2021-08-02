#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
/*
int minCost(vector<int> arr, int n, int k)
{
    vector<int> dp(n + 1);
    dp[1] = 0;
    dp[2] = dp[1] + abs(arr[2] - arr[1]);
    F(i, 3, n + 1)
    {
        int min_val = inf;
        // reaching to i from i-k
        F(j, 1, k + 1)
        {
            //reaching to i from i-2
            if (i - j > 0)
            {
                dp[i] = abs(arr[i] - arr[i - j]) + dp[i - j];
            }
            if (dp[i] < min_val)
            {
                min_val = dp[i];
            }
        }
        dp[i] = min_val;
    }
    //  F(i, 1, n + 1)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    
return dp[n];
}
*/

int minCostSame(vector<int> ar, int n, int k)
{

    vector<int> dp(n + 1);

    dp[1] = 0;

    for (int i = 2; i <= n; i++)

    {

        dp[i] = inf;

        for (int j = i - 1; j >= 1 && (i - j) <= k; j--)

        {
            dp[i] = min(dp[i], abs(ar[i] - ar[j]) + dp[j]);
        }
    }

    return dp[n];
}
int main()
{
    int n, k;
    // here k is the maximum no. of  jumps
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // int ans = minCost(arr, n, k);
    // cout << ans;
    int same_ans = minCostSame(arr, n, k);
    cout << endl
         << same_ans;
    return 0;
}

// question: how to find the path of the minimum_cost ?