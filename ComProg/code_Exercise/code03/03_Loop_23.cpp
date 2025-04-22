#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, tmp = "", ans = "";
    int k;

    cin >> str >> k;
    tmp = str[0];
    str += " ";

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != str[i - 1])
        {
            if (tmp.size() < k)
            {
                ans += tmp;
            }
            tmp = str[i];
        }
        else
        {
            tmp += str[i];
        }
    }

    cout << ans;

    return 0;
}