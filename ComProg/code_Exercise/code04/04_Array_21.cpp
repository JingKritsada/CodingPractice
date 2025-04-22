#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    double down;
    for (int i = 0; i < n; i++)
    {
        down = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            down = a[j] + (1 / down);
        }

        cout << setprecision(10) << down << "\n";
    }

    return 0;
}