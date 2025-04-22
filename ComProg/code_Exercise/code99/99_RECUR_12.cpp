#include <bits/stdc++.h>
using namespace std;

int recur(int a, int k, int m)
{
    if (k == 0)
    {
        return 1;
    }

    int temp = recur(a, k / 2, m);
    temp *= temp;

    if (k % 2 == 0)
    {
        return temp % m;
    }
    else
    {
        return (a * temp) % m;
    }
}

int main()
{
    int a, k, m;
    cin >> a >> k >> m;

    cout << recur(a, k, m);

    return 0;
}