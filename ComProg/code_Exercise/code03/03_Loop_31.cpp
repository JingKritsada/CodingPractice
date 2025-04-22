#include <bits/stdc++.h>
using namespace std;

long long pow10(int n)
{
    long long sum = 1;

    for (int i = 0; i < n; i++)
    {
        sum *= 10;
    }

    return sum;
}

int main()
{
    long long sta, end;
    cin >> sta >> end;

    long long sumS = 0, sumE = 0;
    int lenS = log10(sta) + 1;
    int lenE = log10(end) + 1;

    if (sta == 0)
    {
        sumE++;
    }
    else
    {
        sta--;
    }

    while (lenS > 0)
    {
        long long tmp = pow10(lenS - 1);

        sumS += ((sta - tmp + 1) * lenS);
        sta = tmp - 1;
        lenS--;
    }

    while (lenE > 0)
    {
        long long tmp = pow10(lenE - 1);

        sumE += ((end - tmp + 1) * lenE);
        end = tmp - 1;
        lenE--;
    }

    cout << sumE - sumS;

    return 0;
}

/*
1234 56789012345678901

1234 - 1000 + 1 = 235 * 4 ตัว = 940
999  - 100  + 1 = 900 * 3 ตัว = 2700
99   - 10   + 1 = 90  * 2 ตัว = 180
9    - 0    + 1 = 10  * 1 ตัว = 10
*/