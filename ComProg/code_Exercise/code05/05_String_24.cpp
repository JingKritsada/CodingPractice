#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    string a1 = "", b1 = "";
    bool chk = false;
    int sta, end;
    for (int i = 0; str[i] != ' '; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            chk = true;
        }

        if (chk == false)
        {
            a1 += str[i];
        }
        else
        {
            b1 += str[i];
        }
        sta = i;
    }

    string a2 = "", b2 = "";
    chk = false;
    for (int i = str.size() - 1; str[i] != ' '; i--)
    {
        end = i;
    }

    for (int i = end; i < str.size(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            chk = true;
        }

        if (chk == false)
        {
            a2 += str[i];
        }
        else
        {
            b2 += str[i];
        }
    }

    cout << a1 << b2 << str.substr(sta + 1, end - sta - 1) << a2 << b1;

    return 0;
}