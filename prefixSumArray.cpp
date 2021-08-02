//link1: https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
//link2: https://www.geeksforgeeks.org/prefix-sum-2d-array/
//video link:https://www.youtube.com/watch?v=Xu0PfCKy8a8
// link2 :https://www.youtube.com/watch?v=n8ez_X3p70Y&ab_channel=StooverCodingStooverCoding

//1-D prefix sum
/*
#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    F(i, 0, n)
    {
        cout << prefixSum[i] << " ";
    }
    return 0;
}
*/
//Given a matrix (or 2D array) a[][] of integers, find prefix sum matrix for it.
// Let prefix sum matrix be psa[][].
//The value of psa[i][j] contains sum of all values which are above it or on left of it.
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2D vector<vi>
#define rows 4
#define cols 5

void prefixSum2d(v2D inp)
{
    v2D prefixSumArray(rows, vi(cols));
    //base case:
    prefixSumArray[0][0] = inp[0][0];

    //filling 1st row and 1st column
    //first row
    for (int k = 1; k < cols; k++)
    {
        prefixSumArray[0][k] = prefixSumArray[0][k - 1] + inp[0][k];
    }
    //first column
    for (int k = 1; k < rows; k++)
    {
        prefixSumArray[k][0] = prefixSumArray[k - 1][0] + inp[k][0];
    }

    //for remaining
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            prefixSumArray[i][j] = prefixSumArray[i - 1][j] + prefixSumArray[i][j - 1] - prefixSumArray[i - 1][j - 1] + inp[i][j];
        }
    }
    //printing the prefixSum array
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            cout << prefixSumArray[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    v2D inp = {{1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1}};

    prefixSum2d(inp);

    return 0;
}