#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, double> &a, pair<string, double> &b)
{
    return a.second > b.second;
}

int main()
{
    map<string, double> mp;
    map<string, double> cnt;
    string str;
    double num;

    while (true)
    {
        cin >> str;
        if (str == "END")
        {
            break;
        }
        cin >> num;

        mp[str] = num;
    }

    while (cin >> str)
    {
        if (mp.find(str) != mp.end())
        {
            cnt[str] += mp[str];
        }
    }

    if (cnt.size() == 0)
    {
        cout << "No Sales";
        return 0;
    }

    vector<pair<string, double>> ans(cnt.begin(), cnt.end());
    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < 3 && i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}