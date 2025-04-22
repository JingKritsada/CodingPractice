#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    cin >> x;

    double up = sqrt((x * x) + cos(x / 180 * M_PI));
    double down = sin(x / 180 * M_PI) + (pow(cos(x / 180 * M_PI), 3) / (x * x + 1));

    double ans = up / down;
    cout << fixed << setprecision(1) << ans;

    return 0;
}