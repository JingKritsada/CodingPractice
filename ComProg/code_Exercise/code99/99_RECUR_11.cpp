#include <bits/stdc++.h>
using namespace std;

string dec2hex(int num)
{
    string hex = "0123456789ABCDEF";
    if (num < 16)
    {
        return string(1, hex[num]);
    }

    return dec2hex(num / 16) + hex[num % 16];
}

int main()
{
    int num;
    while (cin >> num)
    {
        cout << num << " -> " << dec2hex(num) << "\n";
    }

    return 0;
}