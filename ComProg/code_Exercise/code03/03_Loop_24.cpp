#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt[50] = {0};

    string str;
    cin >> str;
    str += " ";

    for (int i = 0; i < str.size() - 1; i++)
    {
        cnt[str[i] - 'A']++;

        if (str[i] != str[i + 1])
        {
            cout << str[i] << " " << cnt[str[i] - 'A'] << " ";
            cnt[str[i] - 'A'] = 0;
        }
    }

    return 0;
}