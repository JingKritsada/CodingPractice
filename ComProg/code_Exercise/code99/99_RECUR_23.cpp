#include <bits/stdc++.h>
using namespace std;

int F(int n)
{ // Fibonacci number
    if (n <= 1)
    {
        return n;
    }

    if (n % 2 == 1)
    {
        int m = (n + 1) / 2;
        int f0 = F(m);
        int f1 = F(m - 1);
        return f0 * f0 + f1 * f1;
    }
    else
    {
        int m = n / 2;
        int f0 = F(m);
        int f1 = F(m - 1);
        return (2 * f1 + f0) * f0;
    }
}

int M(int n)
{ // Motzkin number
    if (n < 2)
    {
        return 1;
    }

    int sum = M(n - 1);
    for (int k = 0; k <= n - 2; k++)
    {
        sum += (M(k) * M(n - 2 - k));
    }

    return sum;
}

int S(int n)
{ // Schröder–Hipparchus Number
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return ((6 * n - 9) * S(n - 1) - (n - 3) * S(n - 2)) / n;
}

int D(int n)
{ // Derangement
    if (n == 0)
    {
        return 1;
    }

    int temp = 1;
    if (n % 2 == 1)
    {
        temp = -1;
    }

    return n * D(n - 1) + temp;
}

int G(int x, int y)
{
    if (y <= 0)
    {
        return x;
    }

    return G(y, x % y);
}

int J(int n, int k)
{
    if (n <= 1)
    {
        return 0;
    }

    return (J(n - 1, k) + k) % n;
}

int A(int m, int n)
{
    if (m > 0 && n == 0)
    {
        return A(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return A(m - 1, A(m, n - 1));
    }
    else
    {
        return n + 1;
    }
}

int D(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 1;
    }

    return D(m - 1, n) + D(m - 1, n - 1) + D(m, n - 1);
}

int main()
{
    map<string, int (*)(int, int)> func = {{"G", G}, {"J", J}, {"A", A}, {"D", D}};
    string fn;
    int p1, p2;

    while (cin >> fn >> p1 >> p2)
    {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p1 << ',' << p2 << ") = " << func[fn](p1, p2) << "\n";
    }
    return 0;
}