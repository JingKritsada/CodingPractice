#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        int k, cnt = 0;
        cin >> k;

        for (int x : vec)
        {
            if (x == k)
            {
                break;
            }

            if (x > k)
            {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}