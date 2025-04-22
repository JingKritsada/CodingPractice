#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    str = " " + str;

    string tmp = "";
    bool chknum = false;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (str[i - 1] < '0' || str[i - 1] > '9')
            {
                if (tmp.size() > 0)
                {
                    cout << tmp << ", ";
                    tmp = "";
                }
            }
        }
        else
        {
            if ((str[i - 1] >= '0' && str[i - 1] <= '9') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                if (tmp.size() > 0)
                {
                    cout << tmp << ", ";
                    tmp = "";
                }
            }
        }

        tmp += str[i];
    }
    cout << tmp;

    return 0;
}