#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, ans;
    cin >> num;

    num -= 543;
    num %= 100;
    ans = (num + num / 4 + 11) % 7;

    cout << ans;

    return 0;
}