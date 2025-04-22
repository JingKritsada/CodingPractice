#include <bits/stdc++.h>
using namespace std;

int main()
{
    string tar, str, tmp;

    getline(cin, tar);
    getline(cin, str);

    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            tmp += str[i];
        }
        else
        {
            if (tmp == tar)
            {
                cnt++;
            }

            tmp = "";
        }
    }

    if (tmp == tar)
    {
        cnt++;
    }

    cout << cnt;

    return 0;
}