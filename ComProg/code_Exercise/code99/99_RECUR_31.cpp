#include <bits/stdc++.h>
using namespace std;

string str;
set<string> ans;

void permu(string now, vector<bool> chk, int cnt, int len)
{
    if (cnt == len)
    {
        ans.insert(now);
        return;
    }

    for (int i = 0; i < len; i++)
    {
        if (chk[i] == false)
        {
            chk[i] = true;
            permu(now + str[i], chk, cnt + 1, len);
            chk[i] = false;
        }
    }
}

int main()
{
    cin >> str;

    int len = str.size();
    vector<bool> used(len, false);
    sort(str.begin(), str.end());

    permu("", used, 0, len);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}