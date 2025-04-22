#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec = {1, 2, 2};
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int &step : vec)
        {
            if (i + step <= n)
            {
                dp[i + step] = (dp[i] + dp[i + step]) % 1000000007;
            }
        }
    }

    cout << dp[n];

    return 0;
}