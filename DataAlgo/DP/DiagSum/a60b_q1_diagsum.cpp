#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = -1000;
    cin >> n;

    vector<int> dp(2 * n, -1000);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;

            int idx = n + (j - i);
            dp[idx] = max(dp[idx] + tmp, tmp);
            ans = max(ans, dp[idx]);
        }
    }

    cout << ans;

    return 0;
}