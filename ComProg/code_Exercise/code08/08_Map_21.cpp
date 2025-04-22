#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word, type;
    vector<string> order;
    unordered_map<string, string> mp;

    while (cin >> word >> type)
    {
        if (mp.find(type) == mp.end())
        {
            mp[type] = word;
            order.push_back(type);
        }
        else
        {
            mp[type] += " " + word;
        }
    }

    for (auto x : order)
    {
        cout << x << ": " << mp[x] << "\n";
    }

    return 0;
}