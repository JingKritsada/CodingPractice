#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < 12; i++)
    {
        cout << str[i];
        ans += (13 - i) * (str[i] - '0');

        if (i == 0 || i == 4 || i == 9 || i == 11)
        {
            cout << "-";
        }
    }

    ans = (11 - (ans % 11)) % 10;
    cout << ans;

    return 0;
}