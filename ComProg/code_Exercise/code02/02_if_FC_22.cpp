#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, m, y;
    cin >> d >> m >> y;

    y -= 543;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2)
    {
        if (y % 4 == 0)
        {
            if (y % 100 == 0)
            {
                if (y % 400 == 0)
                {
                    month[1] = 29;
                }
                else
                {
                    month[1] = 28;
                }
            }
            else
            {
                month[1] = 29;
            }
        }
        else
        {
            month[1] = 28;
        }
    }

    d += 15;
    if (d > month[m - 1])
    {
        d -= month[m - 1];
        m++;
    }

    if (m > 12)
    {
        m -= 12;
        y++;
    }

    cout << d << "/" << m << "/" << y + 543;

    return 0;
}