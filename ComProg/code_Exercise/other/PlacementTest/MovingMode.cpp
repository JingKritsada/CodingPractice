#include <bits/stdc++.h>
using namespace std;

int k, n, m;
vector<int> day(100010, INT_MAX);
map<int, int> cnt;

int main()
{
    cin >> k >> n >> m;

    int d, t;
    for (int i = 0; i < m; i++)
    {
        cin >> d >> t;
        day[d] = t;

        if (d <= k)
        {
            cnt[t]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int nxt = i + k;
        int old = i - k - 1;

        if (nxt <= n)
        {
            if (day[nxt] != INT_MAX)
            {
                cnt[day[nxt]]++;
            }
        }
        if (old >= 1)
        {
            if (day[old] != INT_MAX)
            {
                cnt[day[old]]--;

                if (cnt[day[old]] == 0)
                {
                    cnt.erase(day[old]);
                }
            }
        }

        int max = 0, freqMX = 0;
        if (cnt.size() == 0)
        {
            cout << "X ";
        }
        else
        {
            for (auto &x : cnt)
            {
                if (x.second > freqMX)
                {
                    freqMX = x.second;
                    max = x.first;
                }
            }

            cout << max << " ";
        }
    }

    return 0;
}