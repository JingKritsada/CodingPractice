#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    unordered_map<string, set<int>> student;

    for (int i = 0; i < n; ++i)
    {
        int min;
        string id;
        cin >> id >> min;

        student[id].insert(min);
    }

    int cnt = 0;
    for (auto &x : student)
    {
        if (x.second.size() == k)
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}