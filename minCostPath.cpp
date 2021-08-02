//link for reference:https://www.hackerearth.com/practice/notes/dynamic-programming-problems-involving-grids/
//minimum cost of path if left to right and top to down movement are only allowed

#include <bits/stdc++.h>
using namespace std;

int cost[3][3] = {{1, 5, 2},
                  {7, 1, 1},
                  {8, 1, 3}};

// int cost[3][3] = {{1, 2, 3},
//                   {4, 8, 2},
//                   {1, 5, 3}};
int dp[3][3];
int min_cost(int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            //base case
            if (i == 0 and j == 0)
            {
                dp[i][j] = cost[0][0];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[0][j - 1] + cost[0][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][0] + cost[i][0];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
            }
        }
    }
    //printing the dp array
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << setw(3) << right << dp[i][j] << " "; //setw() for alignment
        }
        cout << "\n";
    }
    cout << endl;
    return dp[R - 1][C - 1];
}
int main()
{
    int R = 3, C = 3;
    cout << min_cost(R, C);
    return 0;
}

//minimum cost of path if left to right,diagnol movement  and top to down movement are allowed

int min(int x, int y, int z)
{
    if (x < y)
    {
        return (x < z) ? x : z;
    }
    else
    {
        return (y < z) ? y : z;
    }
}
int min_cost3(int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            //base case
            if (i == 0 and j == 0)
            {
                dp[i][j] = cost[0][0];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[0][j - 1] + cost[0][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][0] + cost[i][0];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + cost[i][j];
            }
        }
    }
    //printing the dp array
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
    return dp[R - 1][C - 1];
}