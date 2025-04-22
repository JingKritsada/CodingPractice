#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i = 2;
    cin >> n;

    while (i < n)
    {
        if (n % i != 0)
        {
            i++;
        }
        else
        {
            cout << i << "*";
            n /= i;
        }
    }

    cout << n;

    return 0;
}