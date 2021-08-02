//if some paths are blocked in the grid based dynamic programming problem,then total ways to reach the specified place are:
//link:https://www.hackerearth.com/practice/notes/dynamic-programming-problems-involving-grids/

//Finding the number of ways to reach a particular position in a grid from a starting position
//(given some cells which are blocked)
//problem: robot and path
//link: https://www.codechef.com/problems/CD1IT4

#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define mod 1000000007
int dp[1001][1001];

int numOfWays(int row, int col)
{

    //base case
    if (dp[0][0] == -1)
    {
        return 0;
    }
    //compute the number of ways for first row
    F(j, 0, col)
    {
        if (dp[0][j] == -1)
        {
            break;
        }

        dp[0][j] = 1;
    }

    //compute the number of ways for first col
    F(i, 0, row)
    {
        if (dp[i][0] == -1)
        {
            break;
        }

        dp[i][0] = 1;
    }

    // for rest of the matrix ,used bottomUp approach
    F(i, 1, row)
    {
        F(j, 1, col)
        {
            // if cell is blocked then leave it and go to another column of same row
            if (dp[i][j] == -1)
            {
                continue;
            }
            dp[i][j] = 0;
            // if up cell is not blocked
            if (dp[i - 1][j] != -1)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
            // if left cell is not blocked
            if (dp[i][j - 1] != -1)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    if (dp[row - 1][col - 1] == -1)
    {
        return 0;
    }
    return dp[row - 1][col - 1];
}

int main()
{
    int row, col;

    cin >> row >> col;
    vector<vector<char>> inp(row, vector<char>(col));
    // initializing the dp with 0
    memset(dp, 0, sizeof(dp));
    // here '#'denotes  the  blocked cell;
    // here '.'denotes  the  unblocked  cell;
    F(i, 0, row)
    {
        F(j, 0, col)
        {
            cin >> inp[i][j];
        }
    }
    F(i, 0, row)
    {
        F(j, 0, col)
        {
            if (inp[i][j] == '.')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = -1;
            }
        }
    }
    int ans = numOfWays(row, col);
    cout << ans;
    return 0;
}