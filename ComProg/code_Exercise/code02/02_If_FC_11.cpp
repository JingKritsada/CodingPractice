#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, e, tmp;
    cin >> a >> b >> c >> d >> e;

    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (c > d)
    {
        tmp = c;
        c = d;
        d = tmp;
    }
    if (a > c)
    {
        tmp = b;
        b = d;
        d = tmp;
        c = a;
    }

    a = e;
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (c > a)
    {
        tmp = b;
        b = d;
        d = tmp;
        a = c;
    }

    if (a > d)
    {
        cout << d;
    }
    else
    {
        cout << a;
    }

    return 0;
}