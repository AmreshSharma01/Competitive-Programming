// knapsack space optimised solution
//link: https://www.geeksforgeeks.org/space-optimized-dp-solution-0-1-knapsack-problem/
#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int w = W; w >= 0; w--)

        {

            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    // F(i, 0, W + 1)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return dp[W]; // returning the maximum value of knapsack
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
