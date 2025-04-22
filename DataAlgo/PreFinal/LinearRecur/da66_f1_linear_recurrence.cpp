#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> c(k);
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }

    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    vector<int> R(2000, 0);
    for (int i = 0; i < k; i++)
    {
        R[i] = a[i] % 32717;
    }

    for (int i = k; i <= n; i++)
    {
        R[i] = 0;
        for (int j = 0; j < k; j++)
        {
            R[i] = (R[i] + (c[j] % 32717) * (R[i - j - 1] % 32717)) % 32717;
        }
    }

    cout << R[n] << endl;
    return 0;
}
