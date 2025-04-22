#include <bits/stdc++.h>
using namespace std;

void recur(int len, int cnt, string str, int i, int nowi, int j, int nowj, int k, int nowk, set<string> &ans)
{
    if (cnt == len)
    {
        ans.insert(str);
        return;
    }

    if (nowi < i)
    {
        recur(len, cnt + 1, str + "A", i, nowi + 1, j, nowj, k, nowk, ans);
    }
    if (nowj < j)
    {
        recur(len, cnt + 1, str + "B", i, nowi, j, nowj + 1, k, nowk, ans);
    }
    if (nowk < k)
    {
        recur(len, cnt + 1, str + "C", i, nowi, j, nowj, k, nowk + 1, ans);
    }
}

int main()
{
    int n, i, j, k;
    cin >> n >> i >> j >> k;

    set<string> ans;
    recur(n, 0, "", i, 0, j, 0, k, 0, ans);

    cout << ans.size() << "\n";
    for (auto &x : ans)
    {
        cout << x << "\n";
    }

    return 0;
}