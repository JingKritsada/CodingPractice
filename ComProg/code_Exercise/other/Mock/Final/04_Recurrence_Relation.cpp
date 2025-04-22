#include <bits/stdc++.h>
using namespace std;

int S(int n, int k)
{
    if (n == 0 && k == 0)
    {
        return 1;
    }
    else if (n == 0 || k == 0)
    {
        return 0;
    }

    return k * S(n - 1, k) + S(n - 1, k - 1);
}

int B(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int result = 0;
    for (int k = 0; k < n; k++)
    {
        int combi = 1;
        int Bk = B(k);

        for (int i = 1; i <= k; i++)
        {
            combi *= (n - i);
            combi /= i;
        }

        result += combi * Bk;
    }
    return result;
}

int T(int n, int x)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }

    return 2 * x * T(n - 1, x) - T(n - 2, x);
}

int main()
{
    string fn;
    int i, j;
    while (cin >> fn)
    {
        if (fn == "S")
        {
            cin >> i >> j;
            printf("S(%d, %d) = %d\n", i, j, S(i, j));
        }
        else if (fn == "B")
        {
            cin >> i;
            printf("B(%d) = %d\n", i, B(i));
        }
        else if (fn == "T")
        {
            cin >> i >> j;
            printf("T(%d, %d) = %d\n", i, j, T(i, j));
        }
    }
    return 0;
}