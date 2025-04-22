#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum, cnt = 0, num, diff;
    set<int> s;

    cin >> sum;
    while (cin >> num)
    {
        if (num == -1)
        {
            break;
        }

        s.insert(num);
    }

    for (auto &x : s)
    {
        diff = sum - x;
        if (s.find(diff) != s.end())
        {
            cnt++;
        }
    }

    cout << cnt / 2;

    return 0;
}