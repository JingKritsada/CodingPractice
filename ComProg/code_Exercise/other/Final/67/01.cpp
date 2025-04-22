#include <iostream>

using namespace std;

long long T(int n, int k)
{ // Schroder Triangle
    if (k > n)
    {
        return 0;
    }
    else if (k == 0)
    {
        return 1;
    }

    return T(n, k - 1) + T(n - 1, k - 1) + T(n - 1, k);
}

long long S(int n)
{ // Schroder Number
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }

    long long sum = 0;
    for (int k = 1; k <= n - 2; k++)
    {
        sum += (S(k) * S(n - k - 1));
    }

    return 3 * S(n - 1) + sum;
}

long long W(int n)
{ // Wedderburn–Etherington Number
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (n % 2 == 0)
    {
        long long sum = 0;
        for (int i = 1; i <= n / 2 - 1; i++)
        {
            sum += W(i) * W(n - i);
        }

        return (W(n / 2) * (W(n / 2) + 1)) / 2 + sum;
    }
    else
    {
        long long sum = 0;
        for (int i = 1; i <= (n + 1) / 2 - 1; i++)
        {
            sum += W(i) * W(n - i);
        }

        return sum;
    }
}

int main()
{
    string fn;
    int p1, p2;

    while (cin >> fn >> p1)
    {
        if (fn == "T")
        {
            cin >> p2;
            cout << fn << '(' << p1 << ',' << p2 << ") = " << T(p1, p2) << endl;
        }
        else if (fn == "S")
        {
            cout << fn << '(' << p1 << ") = " << S(p1) << endl;
        }
        else if (fn == "W")
        {
            cout << fn << '(' << p1 << ") = " << W(p1) << endl;
        }
    }

    return 0;
}