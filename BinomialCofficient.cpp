//link: https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
// youtube linlk: https://www.youtube.com/watch?v=ZlzlMURIcEI

//The Problem
//Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
//For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

//1.recursive approach

/*
 C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1

*/
// A naive recursive C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    // Recur
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

//2.dp using bottomUp approach,tc:O(n*k),sc:O(n*k)
int binomialCoefficBottomUp(int n, int k)
{
    int dp[n + 1][k + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            //base case
            if (i == j or j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][k];
}
// 3.more optimised program ,tc:O(n*k),sc:O(k)
int binomialCoeffOptimized(int n, int k)
{
    int C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = k; j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}
// 4.more optimised program ,tc:O(k),sc:O(1)
//link: https://www.youtube.com/watch?v=d1Mtfs7dWlg&t=98s&ab_channel=GeeksforGeeks
double binomialCoeffBestOptimized(double n, double k)
{
    //applying C(n,k)=C(n,n-k) reduces the no. of iterations.
    //useful when K>n-k then reduces k to n-k
    if (k > n - k)
    {
        k = n - k;
    }
    double ans = 1;
    //double countIteration = 0;
    for (double i = 0; i < k; i++)
    {

        ans *= (n - i) / (k - i);
        /* or 
        ans *= (n - i);
        ans /= (i + 1);
        */
        //countIteration++;
    }
    //cout << countIteration << endl;
    return ans;
}

/* Driver code*/
int main()
{
    int n = 9, k = 5;
    double N = 9, K = 5;

    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k);
    cout << endl;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoefficBottomUp(n, k);
    cout << endl;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeffOptimized(n, k);
    cout << endl;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeffBestOptimized(N, K);
    return 0;
}
