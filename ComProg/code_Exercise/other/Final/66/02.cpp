#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, set<string>> mp;
    int n, m, score, idx = 0;
    string name;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> score;
        mp[score].insert(name);
    }

    cin >> m;
    vector<int> vec;
    int len = mp.size();

    for (auto x : mp)
    {
        vec.push_back(x.first);
    }

    for (int i = len - 1; i > len - 1 - m; i--)
    {
        cout << vec[i];
        for (auto x : mp[vec[i]])
        {
            cout << " " << x;
        }
        cout << "\n";
    }

    return 0;
}