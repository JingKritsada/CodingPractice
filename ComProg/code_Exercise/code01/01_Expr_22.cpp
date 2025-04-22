#include <bits/stdc++.h>
using namespace std;

int main()
{
    double xe, ye, re, rp, xm, ym, xp, yp;
    cin >> xe >> ye >> re >> rp >> xm >> ym;

    double A = xm - xe;
    double B = ym - ye;
    double C = sqrt(A * A + B * B);

    double c = re - rp;
    xp = xe + (A * c / C);
    yp = ye + (B * c / C);

    cout << round(xp) << " " << round(yp);

    return 0;
}