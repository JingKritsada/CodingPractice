#include <bits/stdc++.h>
using namespace std;

void gen(int tar, int cnt, int len, int now, string str)
{
    if (now > len)
    {
        return;
    }

    if (now == len && cnt == tar)
    {
        cout << str << "\n";
        return;
    }

    gen(tar, cnt, len, now + 1, str + "0");
    gen(tar, cnt + 1, len, now + 1, str + "1");
}

int main()
{
    int n, m;
    cin >> n >> m;

    gen(n, 0, m, 0, "");

    return 0;
}