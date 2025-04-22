#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;

    int mx = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int degree = 0;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            degree += tmp;
        }

        ans[degree]++;
        if (mx < degree)
        {
            mx = degree;
        }
    }

    for (int i = 0; i <= mx; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}