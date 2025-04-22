#include <bits/stdc++.h>
using namespace std;

int main()
{
    double mx = 0, mn = INT_MAX, num, sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> num;
        sum += num;
        if (num < mn)
        {
            mn = num;
        }
        if (num > mx)
        {
            mx = num;
        }
    }

    sum = sum - mx - mn;
    cout << round((sum / 2) * 100.0) / 100.0;

    return 0;
}