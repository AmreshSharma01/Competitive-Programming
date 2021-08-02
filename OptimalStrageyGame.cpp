//similar L-queue problem of Atcoder
//for reference:https://www.youtube.com/watch?v=VwjKZQCaTC8&ab_channel=CodeLibrary
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3001][3001];

int optimalStrategy(int n, vector<int> v, int i, int j)
{

    //Base case
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

    //if player A selects i;
    int ans1 = v[i] + max(optimalStrategy(n, v, i + 2, j), optimalStrategy(n, v, i + 1, j - 1));
    //if player A selects j;
    int ans2 = v[j] + min(optimalStrategy(n, v, i, j - 2), optimalStrategy(n, v, i + 1, j - 1));

    return dp[i][j] = max(ans1, ans2);
}
int main()
{
    memset(dp, -1, sizeof dp);
    int n, i, j;
    // vector<int> v = {8, 15, 3, 7};
    vector<int> v = {10, 80, 90, 30};
    //vector<int> v = {2, 2, 2, 2};
    n = v.size();

    int winnerPoint = optimalStrategy(n, v, 0, n - 1);
    //for sum:  accumulate(a.begin(), a.end(), 0);
    int sum = 0;
    sum = accumulate(v.begin(), v.end(), sum);
    int loserPoint = sum - winnerPoint;
    int margin = winnerPoint - loserPoint;
    cout << "WinnerPoint is: " << winnerPoint << " ,won with margin: " << margin;

    return 0;
}
/*
4
10 80 90 30
*/