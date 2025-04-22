#include <bits/stdc++.h>
using namespace std;

bool chk(int sta, int end, vector<int> &vec)
{
    if (end - sta == 2)
    {
        return true;
    }

    int mid = (sta + end) / 2;
    int cntL = 0, cntR = 0;

    for (int i = sta; i < end; i++)
    {
        if (i < mid)
        {
            cntL += vec[i];
        }
        else
        {
            cntR += vec[i];
        }
    }

    int diff = abs(cntL - cntR);
    return (diff <= 1) && chk(sta, mid, vec) && chk(mid, end, vec);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int len = pow(2, k);
    while (n--)
    {
        vector<int> vec(len);
        for (int i = 0; i < len; i++)
        {
            cin >> vec[i];
        }

        if (chk(0, len, vec))
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