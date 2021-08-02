#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define mod 1000003

ll n, x;
ll dp[105][3][105];

ll diwaliPuzzle(ll i, ll prev, ll cnt)
{

    //base case
    if (i == n)
    {
        if (cnt == x)
        {
            return 1;
        }
        return 0;
    }

    //memoization
    if (dp[i][prev][cnt] != -1)
    {
        return dp[i][prev][cnt];
    }

    //recursive case
    ll ans = 0;
    // when current element is 1
    if (prev == 1)
    {
        ans += diwaliPuzzle(i + 1, 1, cnt + 1); //prev=1 and curr val=1
    }
    else
    {
        ans += diwaliPuzzle(i + 1, 1, cnt); //here prev value=0 and current val=1
    }
    ans %= mod;
    //when current element is 0
    ans += diwaliPuzzle(i + 1, 0, cnt);
    ans %= mod;
    return dp[i][prev][cnt] = ans;
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n >> x;
        cout << (diwaliPuzzle(1, 1, 0) + diwaliPuzzle(1, 0, 0)) % mod << endl;
    }

    return 0;
}