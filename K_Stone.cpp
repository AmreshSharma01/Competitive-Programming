#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9

string solve(vector<int> &v, int k)
{
    bool dp[k + 1];
    memset(dp, 0, sizeof dp);
    F(i, 1, k + 1)
    {
        for (int move : v)
        {
            if (move > i)
            {
                continue;
            }
            if (dp[i - move] == 0)
            {
                dp[i] = 1;
            }
        }
    }
    return dp[k] ? "First" : "Second";
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    F(i, 0, n)
    {
        cin >> v[i];
    }
    cout << solve(v, k);
    return 0;
}