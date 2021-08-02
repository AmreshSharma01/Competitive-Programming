//longest subsequence string
/* #include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    //base case
    if (i == s1.length() or j == s2.length())
    {
        return 0;
    }
    //check if the state is already visited
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    //recursive case
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + lcs(i + 1, j + 1, s1, s2, dp);
    }
    int op1 = lcs(i + 1, j, s1, s2, dp);
    int op2 = lcs(i, j + 1, s1, s2, dp);
    return dp[i][j] = max(op1, op2);
}

int main()
{
    // string s1 = "ABCD";
    // string s2 = "ABEDG";
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    // int n1 = s1.length();
    // int n2 = s2.length();
    int n1 = X.length();
    int n2 = Y.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    cout << lcs(0, 0, X, Y, dp);
    cout << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}  
*/

//DP Approach

/* Dynamic Programming C++ implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];

    /* Following steps build L[m+1][n+1] in
	bottom up fashion. Note that L[i][j]
	contains length of LCS of X[0..i-1]
	and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    //printing the matrix
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << L[i][j] << "  ";
        }
        cout << endl;
    }

    /* L[m][n] contains length of LCS
	for X[0..n-1] and Y[0..m-1] */
    cout << "the length of lcs is:" << L[m][n] << endl;

    //now priting the lcs

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; //lcs to store lcs
    int i = m;
    int j = n;
    while (i > 0 and j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << "the lcs is:" << lcs;
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Driver Code
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    // char X[] = "ABCD";
    // char Y[] = "ABEDG";

    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);
    return 0;
}
