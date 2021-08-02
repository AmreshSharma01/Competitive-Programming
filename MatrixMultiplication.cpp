//matrix multiplication
// time complexity:O(n^3)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 4;
    int mat1[N][N] = {{1, 1, 1, 1},
                      {2, 2, 2, 2},
                      {3, 3, 3, 3},
                      {4, 4, 4, 4}};

    int mat2[N][N] = {{1, 1, 1, 1},
                      {2, 2, 2, 2},
                      {3, 3, 3, 3},
                      {4, 4, 4, 4}};
    int res[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    //printing the multiplication
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//optimized way :O(n^2): Strassen's matrix multiplication
