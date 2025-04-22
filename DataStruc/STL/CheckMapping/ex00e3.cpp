#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        mp[s]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}