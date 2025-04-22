#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;

        int left = 0, right = n - 1, ans;
        if (q < vec[0])
        {
            cout << "-1\n";
        }
        else
        {
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (vec[mid] <= q)
                {
                    ans = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}