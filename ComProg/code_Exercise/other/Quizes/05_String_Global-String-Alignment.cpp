#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.size();
    int len2 = str2.size();
    int mx = 0, cnt = 0, num = 0, chk = 0;

    for (int staS2 = 0; staS2 < len2; staS2++)
    {
        cnt = 0;
        for (int i = 0; i < len1 && (i + staS2) < len2; i++)
        {
            if (str1[i] == str2[staS2 + i])
            {
                cnt++;
            }
        }

        if (cnt > mx)
        {
            mx = cnt;
            num = staS2;
            chk = 1;
        }
    }

    for (int staS1 = 0; staS1 < len1; staS1++)
    {
        cnt = 0;
        for (int i = 0; i < len2 && (i + staS1) < len1; i++)
        {
            if (str2[i] == str1[staS1 + i])
            {
                cnt++;
            }
        }

        if (cnt > mx)
        {
            mx = cnt;
            num = staS1;
            chk = 2;
        }
    }

    string shift = string(num, '-');

    if (chk == 1)
    {
        str1 = shift + str1;
    }
    else if (chk == 2)
    {
        str2 = shift + str2;
    }

    cout << str1 << "\n" << str2 << "\n" << mx;

    return 0;
}