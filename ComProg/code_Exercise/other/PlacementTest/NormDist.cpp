#include <bits/stdc++.h>
using namespace std;

int main()
{
    double u, o, a, b, dx, x, fx, area;
    cin >> u >> o >> a >> b >> dx;

    int m = (b - a) / dx;
    for (int i = 0; i <= m; i++)
    {
        x = a + i * dx;
        fx = (1 / (o * sqrt(2 * M_PI))) * pow(M_E, (0.0 - pow(x - u, 2)) / (2 * o * o));

        area += fx * dx;
    }

    cout << round(area * 1e4) / 1e4;

    return 0;
}