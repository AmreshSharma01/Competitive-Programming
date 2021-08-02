//same as question:optimalStategyGame

#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
#define ll long long
using namespace std;

ll dp[3001][3001];
ll dp_1[3001][3001][2];

//1. approach

ll solve(vector<ll> &v, int n, int i, int j)
{

    //base case
    if (i == j)
    {
        return v[i];
    }
    if (j == i + 1)
    {
        return max(v[i], v[j]);
    }
    //memoziation
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // if Taro chooses the ith number and (Jiro chooses (i+1)th or Jiro chooses jth number)
    ll op1 = v[i] + min(solve(v, n, i + 2, j), solve(v, n, i + 1, j - 1));
    // if Taro chooses the jth number and (Jiro chooses ith or Jiro chooses (j-1)th number)
    ll op2 = v[j] + min(solve(v, n, i + 1, j - 1), solve(v, n, i, j - 2));

    // Taro's point will be:
    ll T_point = max(op1, op2);
    return dp[i][j] = T_point;
}
//2. optimised one

//1- denotes turn for Taro
//0- denotes turn for Jiro
ll optimal_strategy(vector<ll> &v, int i, int j, int turn)
{

    //base case
    if (i > j)
    {
        return 0;
    }
    //memoziation
    if (dp_1[i][j][turn] != -1)
    {
        return dp_1[i][j][turn];
    }
    if (turn == 1)
    {
        return dp_1[i][j][turn] = max(v[i] + optimal_strategy(v, i + 1, j, 0), v[j] + optimal_strategy(v, i, j - 1, 0));
    }
    else
    {
        return dp_1[i][j][turn] = min(optimal_strategy(v, i + 1, j, 1), optimal_strategy(v, i, j - 1, 1));
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    memset(dp, -1, sizeof dp);
    // memset(dp_1, -1, sizeof dp_1);
    F(i, 0, n)
    {
        cin >> v[i];
    }
    ll Taro_point = solve(v, n, 0, n - 1);
    // ll Taro_point = optimal_strategy(v, 0, n - 1, 1);
    //for sum:  accumulate(a.begin(), a.end(), 0);
    ll sum = 0;
    sum = accumulate(v.begin(), v.end(), sum);
    ll Jiro_point = sum - Taro_point;
    ll margin = Taro_point - Jiro_point;
    cout << margin;

    return 0;
}