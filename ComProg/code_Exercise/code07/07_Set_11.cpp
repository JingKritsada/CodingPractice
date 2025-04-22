#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<char> ms1;
    multiset<char> ms2;

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    for (auto &c : str1)
    {
        if (c == ' ')
            continue;
        ms1.insert(toupper(c));
    }
    for (auto &c : str2)
    {
        if (c == ' ')
            continue;
        ms2.insert(toupper(c));
    }

    if (ms1 == ms2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}