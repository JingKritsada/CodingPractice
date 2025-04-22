#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool num[10] = {false};
    bool chk = true;
    int cnt = 10;

    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (num[str[i] - '0'] == false)
            {
                num[str[i] - '0'] = true;
                cnt--;
            }

            chk = chk && num[str[i] - '0'];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (num[i] == false)
        {
            cout << i;
            if (cnt > 1)
            {
                cout << ",";
                cnt--;
            }
        }

        chk = chk && num[i];
    }

    if (chk == true)
    {
        cout << "None";
    }

    return 0;
}