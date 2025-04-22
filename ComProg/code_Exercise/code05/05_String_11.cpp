#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        bool chk = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (!isalnum(str[i]) && str[i] != ' ' && str[i] != '.' && str[i] != '-' && str[i] != ',' && str[i] != 39)
            {
                chk = !chk;
                continue;
            }
            if (chk == true)
            {
                cout << str[i];
            }
        }
        cout << "\n";
    }

    return 0;
}