#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9
#define MAX 3000
int dp[MAX + 1][MAX + 1];

//topdown approach
string getLcs(string &s, string &t, int len_lcs)
{
    string LCS;
    int i = 0, j = 0;
    while (len_lcs > 0)
    {
        if (s[i] == t[j])
        {
            LCS.push_back(s[i]);
            i++;
            j++;
            len_lcs--;
        }
        else
        {
            if (dp[i][j + 1] > dp[i + 1][j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    return LCS;
}

// note if i is included then j value is incremented and viceversa

int lenLcs(string &s, string &t, int i, int j)
{
    //base case:
    //if anyone string is empty
    if (i >= s.length() || j >= t.length())
    {
        return 0;
    }
    //memoization
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    //recursive case
    if (s[i] == t[j])
    {
        return dp[i][j] = 1 + lenLcs(s, t, i + 1, j + 1);
    }
    else
    {
        return dp[i][j] = max(lenLcs(s, t, i, j + 1), lenLcs(s, t, i + 1, j));
    }
}
string solve(string s, string t)
{
    memset(dp, -1, sizeof dp);
    int len = lenLcs(s, t, 0, 0);
    return getLcs(s, t, len);
}

int main()
{

    string s, t;
    cin >> s >> t;
    cout << solve(s, t);
    return 0;
}