// link: https://www.tutorialcup.com/interview/dynamic-programming/printing-brackets-in-matrix-chain-multiplication-problem.htm
#include <bits/stdc++.h>
using namespace std;
// Recursively print the arrangement for minimum cost of multiplication
void printBracketsMatrixChain(int i, int j, vector<vector<int>> &brackets, char &cur_name)
{

    // you have a single matrix ( you cannot further reduce the problem, so print the matrix )
    if (i == j)
    {
        cout << cur_name;
        cur_name++;
    }
    else
    {
        cout << "(";

        // Reduce the problem into left sub-problem ( left of optimal arrangement )
        printBracketsMatrixChain(i, brackets[i][j], brackets, cur_name);

        // Reduce the problem into right sub-problem ( right of optimal arrangement )
        printBracketsMatrixChain(brackets[i][j] + 1, j, brackets, cur_name);
        cout << ")";
    }
}
void matrixMultiplicationProblem(vector<int> matrixSize)
{
    int numberOfMatrices = matrixSize.size() - 1;
    // dp[i][j] = minimum number of operations required to multiply matrices i to j
    int dp[numberOfMatrices][numberOfMatrices];
    // initialising dp array with INT_MAX ( maximum number of operations )
    for (int i = 0; i < numberOfMatrices; i++)
    {
        for (int j = 0; j < numberOfMatrices; j++)
        {
            dp[i][j] = INT_MAX;
            if (i == j) // for a single matrix from i to i, cost = 0
                dp[i][j] = 0;
        }
    }
    vector<vector<int>> brackets(numberOfMatrices, vector<int>(numberOfMatrices, 0));
    for (int len = 2; len <= numberOfMatrices; len++)
    {
        for (int i = 0; i < numberOfMatrices - len + 1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                int val = dp[i][k] + dp[k + 1][j] + (matrixSize[i] * matrixSize[k + 1] * matrixSize[j + 1]);
                if (val < dp[i][j])
                {
                    dp[i][j] = val;
                    brackets[i][j] = k;
                }
            }
        }
    }
    cout << "cost is:" << dp[0][numberOfMatrices - 1];
    // naming the first matrix as A
    char cur_name = 'A';

    // calling function to print brackets
    printBracketsMatrixChain(0, numberOfMatrices - 1, brackets, cur_name);
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> matrixSize(n);
        for (int i = 0; i < n; i++)
            cin >> matrixSize[i];
        matrixMultiplicationProblem(matrixSize);
    }
}