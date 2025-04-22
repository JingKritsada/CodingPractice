#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> vec(k);
    for (int i = 0; i < k; i++)
    {
        cin >> vec[i];
    }

    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (auto x : vec)
        {
            if (i + x <= n)
            {
                dp[i + x] = (dp[i + x] + dp[i]) % 1000003;
            }
        }
    }

    cout << dp[n];
}