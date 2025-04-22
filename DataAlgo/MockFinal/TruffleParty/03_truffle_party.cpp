#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main()
{
    ull tar, mouse;
    cin >> tar >> mouse;

    vector<ull> time(mouse);
    for (ull &x : time)
    {
        cin >> x;
    }

    ull left = 1, right = LLONG_MAX - 1, ans = 0;
    while (left <= right)
    {
        ull mid = (left + right) / 2;
        ull total = 0;

        for (auto &x : time)
        {
            total += (mid / x);
        }

        // cout << left << ", " << mid << ", " << right << ", " << total << "\n";

        if (total >= tar)
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}