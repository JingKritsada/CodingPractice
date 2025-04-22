#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numX, numH, sta, end;
    cin >> numX >> numH >> sta >> end;

    unordered_map<int, int> x;
    unordered_map<int, int> h;

    for (int i = 0; i < numX; i++)
    {
        int n, num;
        cin >> n >> num;
        x[n] = num;
    }

    for (int i = 0; i < numH; i++)
    {
        int n, num;
        cin >> n >> num;
        h[n] = num;
    }

    for (int n = sta; n <= end; n++)
    {
        long long y = 0;

        for (auto &x_pair : x)
        {
            long long k = x_pair.first;
            long long x_val = x_pair.second;
            long long h_idx = n - k;

            if (h.find(h_idx) != h.end())
            {
                y += x_val * h[h_idx];
            }
        }

        cout << y << " ";
    }

    return 0;
}
