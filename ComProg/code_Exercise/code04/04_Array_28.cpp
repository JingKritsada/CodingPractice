#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int cnt[200] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        cnt[tolower(str[i])]++;
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        if (cnt[i] > 0)
        {
            printf("%c -> %d\n", i, cnt[i]);
        }
    }

    return 0;
}