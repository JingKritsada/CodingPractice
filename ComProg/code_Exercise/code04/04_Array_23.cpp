#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int fee;
    string name;
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> fee;
        mp[name] = fee;
    }

    int sum = 0;
    string path;
    string cur = "", des = "";
    while (cin >> path)
    {
        des += path[4];
        des += path[5];

        if (cur != des && cur != "")
        {
            sum += mp[des];
        }

        cur = des;
        des = "";

        // cout << sum << " " ;
    }

    cout << sum;

    return 0;
}