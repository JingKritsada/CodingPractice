#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    getline(cin, str);
    int len = str.size();

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            str[i] = '[';
        }
        else if (str[i] == '[')
        {
            str[i] = '(';
        }
        else if (str[i] == ')')
        {
            str[i] = ']';
        }
        else if (str[i] == ']')
        {
            str[i] = ')';
        }
    }

    cout << str;

    return 0;
}