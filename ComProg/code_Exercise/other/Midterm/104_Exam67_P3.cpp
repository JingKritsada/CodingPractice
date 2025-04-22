#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    double c[50], sta = -1.0, mid = 0.0, end = 1.0;

    cin >> m;
    for (int i = 0; i <= m; i++)
    {
        cin >> c[i];
    }

    while (true)
    {
        double sum = 0;
        for (int y = 0; y <= m; y++)
        {
            sum += (c[y] / (pow(1 + mid, y)));
        }

        if (-0.00000001 < sum && sum < 0.00000001)
        {
            cout << setprecision(8) << mid;
            break;
        }
        else if (sum < 0)
        {
            end = mid;
            mid = (sta + end) / 2;
        }
        else if (sum > 0)
        {
            sta = mid;
            mid = (sta + end) / 2;
        }
    }

    return 0;
}