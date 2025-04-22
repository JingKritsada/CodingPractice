#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int n, num, sum = 0, mn = INT_MAX;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> num;
            sum += num;

            if (num < mn)
            {
                mn = num;
            }
        }

        sum -= mn;
        cout << sum << "\n";
    }

    return 0;
}