#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9

struct activity
{
    int A, B, C;
};

int solve(vector<activity> arr, int n)
{
    //1-based indexing
    int dp[n + 1][3];
    // base case i.e if one day is there
    dp[1][0] = arr[1].A;
    dp[1][1] = arr[1].B;
    dp[1][2] = arr[1].C;

    //recurrence relation
    F(i, 2, n + 1)
    {
        // if A is chosen for ith day
        dp[i][0] = arr[i].A + max(dp[i - 1][1], dp[i - 1][2]);
        // if B is chosen for ith day
        dp[i][1] = arr[i].B + max(dp[i - 1][0], dp[i - 1][2]);
        // if C is chosen for ith day
        dp[i][2] = arr[i].C + max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[n][0], max(dp[n][1], dp[n][2]));
}

int main()
{

    int n;
    cin >> n;
    vector<activity> arr(n + 1);
    F(i, 1, n + 1)
    {
        cin >> arr[i].A >> arr[i].B >> arr[i].C;
    }
    int ans = solve(arr, n);
    cout << ans;
    return 0;
}