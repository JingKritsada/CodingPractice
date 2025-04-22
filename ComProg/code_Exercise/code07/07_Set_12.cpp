#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tmp;
    set<int> s;

    while (cin >> tmp)
    {
        if (s.find(tmp) == s.end())
        {
            s.insert(tmp);
        }
        else
        {
            cout << s.size() + 1;
            return 0;
        }
    }

    cout << -1;

    return 0;
}