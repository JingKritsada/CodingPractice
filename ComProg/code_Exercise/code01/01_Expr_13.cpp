#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    double x1 = ((0.0 - b) - sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a);
    double x2 = ((0.0 - b) + sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a);

    cout << round(x1 * 1e3) / 1e3 << " " << round(x2 * 1e3) / 1e3;

    return 0;
}