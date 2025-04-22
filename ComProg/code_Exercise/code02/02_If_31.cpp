#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d1, m1, y1, d2, m2, y2;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

    y1 -= 543;
    y2 -= 543;

    int numD = 0;
    numD += (((y2 - 1) - (y1 + 1)) + 1) * 365;

    int day;
    for (int m = m1; m <= 12; m++)
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            day = 31;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            day = 30;
        }
        else
        {
            if (y1 % 4 == 0)
            {
                if (y1 % 100 == 0)
                {
                    if (y1 % 400 == 0)
                    {
                        day = 29;
                    }
                    else
                    {
                        day = 28;
                    }
                }
                else
                {
                    day = 29;
                }
            }
            else
            {
                day = 28;
            }
        }

        if (m == m1)
        {
            numD += day - d1 + 1;
        }
        else
        {
            numD += day;
        }
    }
    for (int m = 1; m < m2; m++)
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            numD += 31;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            numD += 30;
        }
        else
        {
            if (y2 % 4 == 0)
            {
                if (y2 % 100 == 0)
                {
                    if (y2 % 400 == 0)
                    {
                        numD += 29;
                    }
                    else
                    {
                        numD += 28;
                    }
                }
                else
                {
                    numD += 29;
                }
            }
            else
            {
                numD += 28;
            }
        }
    }

    numD += d2 - 1;
    double p = sin((2 * M_PI * numD) / 23);
    double e = sin((2 * M_PI * numD) / 28);
    double i = sin((2 * M_PI * numD) / 33);

    cout << numD << " ";
    cout << round(p * 100.0) / 100.0 << " ";
    cout << round(e * 100.0) / 100.0 << " ";
    cout << round(i * 100.0) / 100.0;

    return 0;
}