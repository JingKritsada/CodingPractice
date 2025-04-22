#include <bits/stdc++.h>
using namespace std;

int main()
{
    double lower, upper, a, mid;
    cin >> a;

    lower = 0;
    upper = a;
    mid = (upper + lower) / 2;

    while (abs(a - pow(10, mid)) > pow(10, -10) * max(a, pow(10, mid)))
    {
        if (pow(10, mid) > a)
        {
            upper = mid;
        }
        else
        {
            lower = mid;
        }

        mid = (upper + lower) / 2;
    }

    cout << mid;

    return 0;
}