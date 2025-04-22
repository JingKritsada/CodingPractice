#include <bits/stdc++.h>
using namespace std;

int main()
{
    double num;
    cin >> num;

    if (num >= 10000000000)
    {
        cout << round(num / 1000000000) << "B";
    }
    else if (num >= 1000000000)
    {
        cout << round(num / 1000000000 * 10) / 10.0 << "B";
    }
    else if (num > 10000000)
    {
        cout << round(num / 1000000) << "M";
    }
    else if (num > 1000000)
    {
        cout << round(num / 1000000 * 10) / 10.0 << "M";
    }
    else if (num > 10000)
    {
        cout << round(num / 1000) << "K";
    }
    else if (num > 1000)
    {
        cout << round(num / 1000 * 10) / 10.0 << "K";
    }
    else
    {
        cout << round(num);
    }

    return 0;
}