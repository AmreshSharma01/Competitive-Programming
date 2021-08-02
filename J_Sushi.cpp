#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
#define prDouble(x) cout << fixed << setprecision(10) << x

double dp[301][301][301];
double solve(int x, int y, int z, int &n)
{
    // this is done to stop the recurrence to go into infinite recursion
    if (x < 0 || y < 0 || z < 0)
    {
        return 0;
    }
    if (x == 0 && y == 0 && z == 0)
    {
        return 0;
    }
    if (dp[x][y][z] > -0.9)
    {
        return dp[x][y][z];
    }

    double exp = n + x * solve(x - 1, y, z, n) + y * solve(x + 1, y - 1, z, n) + z * solve(x, y + 1, z - 1, n);
    return dp[x][y][z] = exp / (x + y + z);
}

int main()
{
    int n, x;
    cin >> n;
    memset(dp, -1, sizeof dp);
    int one = 0, two = 0, three = 0;
    F(i, 1, n + 1)
    {
        cin >> x;
        if (x == 1)
        {
            one++;
        }
        else if (x == 2)
        {
            two++;
        }
        else
            three++;
    }
    prDouble(solve(one, two, three, n));
    return 0;
}