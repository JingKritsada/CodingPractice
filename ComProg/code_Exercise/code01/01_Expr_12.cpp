#include <bits/stdc++.h>
using namespace std;

int main()
{
    double w, h;
    cin >> w >> h;

    double num1 = sqrt(w * h) / 60.0;
    double num2 = 0.024265 * pow(w, 0.5378) * pow(h, 0.3964);
    double num3 = 0.0333 * pow(w, 0.6157 - 0.0188 * log10(w)) * pow(h, 0.3);

    cout << setprecision(15) << num1 << "\n";
    cout << setprecision(15) << num2 << "\n";
    cout << setprecision(15) << num3 << "\n";

    return 0;
}