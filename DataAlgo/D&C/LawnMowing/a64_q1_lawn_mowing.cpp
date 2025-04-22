#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, price;
    cin >> n >> m >> price;

    vector<long long> vec(n + 1, 0);
    for (long long i = 1; i <= n; i++)
    {
        long long grass;
        cin >> grass;
        vec[i] = vec[i - 1] + grass;
    }

    while (m--)
    {
        long long sta, money;
        cin >> sta >> money;

        long long left = sta + 1, right = n, ans = 0;
        while (left <= right)
        {
            long long mid = (left + right) / 2;

            long long numCell = mid - sta;
            long long numGrass = vec[mid] - vec[sta];

            if ((numCell * price) + numGrass <= money)
            {
                ans = numGrass;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
