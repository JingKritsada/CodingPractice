#include <bits/stdc++.h>
using namespace std;

void recur(int len, int n, string tar, string cur)
{
    if (len >= n)
    {
        auto pos = cur.find(tar);
        if (pos != string::npos)
        {
            cout << cur << "\n";
        }
    }
    else
    {
        recur(len + 1, n, tar, cur + "0");
        recur(len + 1, n, tar, cur + "1");
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    string str;
    while (k--)
    {
        str += "1";
    }

    recur(0, n, str, "");

    return 0;
}