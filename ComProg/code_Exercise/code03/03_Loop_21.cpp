#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pwd;
    while (cin >> pwd)
    {
        int len = pwd.size();
        bool upper = false, lower = false, num = false, other = false;

        for (int i = 0; i < len; i++)
        {
            if (pwd[i] >= 97 && pwd[i] <= 122)
            {
                upper = true;
            }
            else if (pwd[i] >= 65 && pwd[i] <= 90)
            {
                lower = true;
            }
            else if (pwd[i] >= 48 && pwd[i] <= 57)
            {
                num = true;
            }
            else if (pwd[i] >= 33 && pwd[i] <= 126)
            {
                other = true;
            }
        }

        if (len >= 12 && upper && lower && other && num)
        {
            cout << ">> strong\n";
        }
        else if (len >= 8 && upper && lower && num)
        {
            cout << ">> weak\n";
        }
        else
        {
            cout << ">> invalid\n";
        }
    }

    return 0;
}