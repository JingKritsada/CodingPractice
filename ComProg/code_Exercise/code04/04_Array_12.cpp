#include <bits/stdc++.h>
using namespace std;

int main()
{
    string names[10][2] = {{"Robert", "Dick"},
                           {"William", "Bill"},
                           {"James", "Jim"},
                           {"John", "Jack"},
                           {"Margaret", "Peggy"},
                           {"Edward", "Ed"},
                           {"Sarah", "Sally"},
                           {"Andrew", "Andy"},
                           {"Anthony", "Tony"},
                           {"Deborah", "Debbie"}};

    int num;
    cin >> num;
    string str;

    for (int i = 0; i < num; i++)
    {
        cin >> str;
        bool chk = false;

        for (int j = 0; j < 10; j++)
        {
            if (str == names[j][0])
            {
                cout << names[j][1] << "\n";
                chk = true;
                break;
            }
            else if (str == names[j][1])
            {
                cout << names[j][0] << "\n";
                chk = true;
                break;
            }
        }
        if (chk == false)
            cout << "Not found\n";
    }

    return 0;
}