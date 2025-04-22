#include <bits/stdc++.h>
using namespace std;

int lower(int tar, vector<int> &vec)
{
    int ans = -1, left = 0, right = vec.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] <= tar)
        {
            ans = vec[mid];
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    while (m--)
    {
        int x;
        cin >> x;

        cout << lower(x, vec) << "\n";
    }

    return 0;
}