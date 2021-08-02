//link: https://www.geeksforgeeks.org/program-nth-catalan-number/

//1. Recursive approach
#include <bits/stdc++.h>
using namespace std;

// A recursive function to find nth catalan number
long int catalan(unsigned long int n)
{
    // Base case
    if (n == 0)
        return 1;

    // catalan(n) is sum of
    // catalan(i-1)*catalan(n-i) ,where i=1 to n
    unsigned long int res = 0;
    for (int i = 1; i <= n; i++)
        res += catalan(i - 1) * catalan(n - i);

    return res;
}

//by book formula
unsigned long int catalan1(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;

    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1) ,where i=0 to n-1
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan1(i) * catalan1(n - i - 1);

    return res;
}

//2. Dp approach
long int catalanButtomUpDp(int n)
{
    int dp[n + 1] = {0};
    //base case
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    { //here i is each catalan number which is corresponding
        //to n in d[n]=dp[i]*dp[n-1]
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}
// 3.analytical approach
// i.e (catalan number)using binomial coefficient in time complexity:O(n)
double binomialCoeffBestOptimized(double n, double k)
{
    //applying C(n,k)=C(n,n-k) reduces the no. of iterations.
    //useful when K>n-k then reduces k to n-k
    if (k > n - k)
    {
        k = n - k;
    }
    double ans = 1;
    for (double i = 0; i < k; i++)
    {

        ans *= (n - i) / (k - i);
    }
    return ans;
}
double catalanUsingBinomialCoeff(int n)
{
    double ans = binomialCoeffBestOptimized(2 * n, n) / (n + 1);
    return ans;
}

// Driver code
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << catalan(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << catalan1(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << catalanButtomUpDp(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << catalanUsingBinomialCoeff(i) << " ";
    }

    return 0;
}
