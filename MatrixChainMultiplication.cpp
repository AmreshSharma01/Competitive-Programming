//matrixChainMultipication

// 1. A naive recursive implementation

/*
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1);
}
*/

//2.Dp :
//2.1. Dp -topdown approach using memoization
/*
\
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    cout << "Minimum number of multiplications is "
         << matrixChainMemoised(arr, 1, n - 1);
}
*/

//2.2: Dp-Using bottomUp approach(Tabulation)
#include <bits/stdc++.h>
using namespace std;

void inorder(int i, int j, int s[][7], char &cur_name)
{
    if (i == j)
    {
        cout << cur_name;
        cur_name++;
    }
    else
    {
        cout << "(";
        //left
        inorder(i, s[i][j], s, cur_name);
        //right
        inorder(s[i][j] + 1, j, s, cur_name);
        cout << ")";
    }
}

int main()
{
    int n = 7, i;
    // int p[] = {5, 4, 6, 2, 7};
    int p[] = {1, 5, 2, 3, 4, 1000, 64};

    int m[7][7] = {0};
    int s[7][7] = {0};
    int j, q;

    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            j = i + d;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "cost :" << m[1][n - 1] << endl;
    char cur_name = 'A';
    inorder(1, n - 1, s, cur_name);
    cout << endl;

    return 0;
}

// C++ program to print optimal parenthesization
// in matrix chain multiplication.
// Link: https://www.geeksforgeeks.org/printing-brackets-matrix-chain-multiplication-problem/