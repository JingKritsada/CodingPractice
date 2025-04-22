#include <bits/stdc++.h>
using namespace std;

bool isVirus(int sta, int end, bool isReverse, vector<int> &code)
{
    int len = end - sta;
    if (len == 2)
    {
        if (!isReverse)
        {
            return code[sta] == 0 && code[sta + 1] == 1;
        }
        else
        {
            return code[sta] == 1 && code[sta + 1] == 0;
        }
    }

    int mid = (sta + end) / 2;
    if (!isReverse)
    {
        bool fnt = isVirus(sta, mid, false, code) || isVirus(sta, mid, true, code);
        bool bck = isVirus(mid, end, false, code);

        return fnt && bck;
    }
    else
    {
        bool fnt = isVirus(sta, mid, true, code);
        bool bck = isVirus(mid, end, false, code) || isVirus(mid, end, true, code);

        return fnt && bck;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int sz = pow(2, k);
    vector<int> code(sz);

    while (n--)
    {
        for (int i = 0; i < sz; i++)
        {
            cin >> code[i];
        }

        if (isVirus(0, sz, false, code))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}