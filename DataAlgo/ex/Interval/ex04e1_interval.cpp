#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> time(n);
    for (auto &x : time)
    {
        cin >> x.second;
    }
    for (auto &x : time)
    {
        cin >> x.first;
    }

    sort(time.begin(), time.end());

    int end = 0, cnt = 0;
    for (auto &x : time)
    {
        if (end <= x.second)
        {
            end = x.first;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}