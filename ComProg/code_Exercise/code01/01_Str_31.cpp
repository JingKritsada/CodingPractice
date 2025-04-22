#include <bits/stdc++.h>
using namespace std;

long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    long upper, lower;
    upper = stoi(a + b);
    upper = upper * (pow(10, c.size()) - 1) + stoi(c);

    lower = pow(10, c.size()) - 1;
    lower = lower * pow(10, b.size());

    long num = gcd(upper, lower);
    upper /= num;
    lower /= num;

    cout << upper << " / " << lower;

    return 0;
}