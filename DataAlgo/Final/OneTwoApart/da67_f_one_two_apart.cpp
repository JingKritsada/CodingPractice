#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 7;

    int mod = 1e8 + 7;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (((2 * dp[i - 1]) % mod) + (dp[i - 3]) % mod) % mod;
    }

    cout << dp[n];

    return 0;
}