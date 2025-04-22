#include <bits/stdc++.h>
using namespace std;

int lower(int target, int len, vector<int> &vec)
{
    int l = 0, r = len;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (vec[m] >= target)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    return l;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> allRelease;
    for (int i = 0; i < n; i++)
    {
        int year, month;
        cin >> year >> month;

        allRelease.push_back((year * 100) + month);
    }

    sort(allRelease.begin(), allRelease.end());

    for (int i = 0; i < m; i++)
    {
        int year, month, target;
        cin >> year >> month;

        target = (year * 100) + month;
        if (target < allRelease[0])
        {
            cout << "-1 -1 ";
            continue;
        }

        int position = lower(target, n, allRelease);

        if (allRelease[position] == target)
        {
            cout << "0 0 ";
        }
        else
        {
            int tmpYear = allRelease[position - 1] / 100;
            int tmpMonth = allRelease[position - 1] % 100;

            cout << tmpYear << " " << tmpMonth << " ";
        }
    }

    return 0;
}