//link:https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
#define ll long long
using namespace std;

struct knapsack
{
    int weight;
    ll value;
};
//n is no. of items
ll solve(vector<knapsack> arr, int n, int max_weight)
{
    ll dp[n + 1][max_weight + 1];
    //base case
    F(w, 0, max_weight + 1)
    {
        dp[1][w] = 0;
    }
    dp[1][arr[1].weight] = arr[1].value;
    // recurrence relation
    F(i, 2, n + 1)
    {
        F(w, 0, max_weight + 1)
        {
            // if the ith weight is not taken
            dp[i][w] = dp[i - 1][w];
            if (arr[i].weight > w)
            {
                continue;
            }
            // if the ith weight is taken
            // dp[i][w] = arr[i].value+dp[i - 1][w - arr[i].weight];

            //returning the max value of the above two cases into the dp array
            dp[i][w] = max(dp[i][w], arr[i].value + dp[i - 1][w - arr[i].weight]);
        }
    }
    return *max_element(dp[n], dp[n] + max_weight + 1);
}

int main()
{
    int no_of_items, at_most_weight;
    cin >> no_of_items >> at_most_weight;
    vector<knapsack> arr(no_of_items + 1);
    F(i, 1, no_of_items + 1)
    {
        cin >> arr[i].weight >> arr[i].value;
    }
    ll ans = solve(arr, no_of_items, at_most_weight);
    cout << ans;

    return 0;
}

/*

// naive approach
int knap_sack(int W, int wt[], int val[], int n)
{

    if (W == 0 || n == 0)
        return 0;

    if (wt[n - 1] > W)
    {
        return knap_sack(W, wt, val, n - 1);
    }
    //case 1.if the nth item is included
    //case 2.if the nth item is not  included
    // ans is the max of both case1 and case2
    else
    {
        int case1 = val[n - 1] + knap_sack(W - wt[n - 1], wt, val, n - 1);
        int case2 = knap_sack(W, wt, val, n - 1);
        return max(case1, case2);
    }
}
*/

//my solution:
/*
#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
#define ll long long

ll knapSack(int W, int wt[], int val[], int n)
{
    ll dp[n + 1][W + 1];
    F(i, 0, n + 1)
    {
        F(w, 0, W + 1)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
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
    ll ans = knapSack(W, wt, val, n);

    cout << ans;
    return 0;
}
*/