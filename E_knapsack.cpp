#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9 + 1
#define ll long long

int knapSack(int W, int wt[], int val[], int n)
{
    int maxVal = n * 1000;
    //because the maxvalue size for each value is 1000
    int dp[n + 1][maxVal + 1];

    F(val, 0, maxVal + 1)
    {
        dp[1][val] = inf;
    }
    // base case
    dp[1][0] = 0;
    dp[1][val[0]] = wt[0];

    F(i, 2, n + 1)
    {
        F(v, 0, maxVal + 1)
        {
            if (v == 0)
            {
                dp[i][v] = 0;
            }

            else if (val[i - 1] <= v)
            {
                dp[i][v] = min(wt[i - 1] + dp[i - 1][v - val[i - 1]], dp[i - 1][v]);
            }
            else
            {
                dp[i][v] = dp[i - 1][v];
            }
        }
    }
    int ans = 0;
    F(x, 0, maxVal + 1)
    {
        if (dp[n][x] <= W)
        {
            ans = x;
        }
    }
    return ans;
}
int main()
{

    int n, W;
    cin >> n >> W;
    int wt[n], val[n];
    F(i, 0, n)
    {

        cin >> wt[i];
        cin >> val[i];
    }
    int ans = knapSack(W, wt, val, n);

    cout << ans;
    return 0;
}