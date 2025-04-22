#include <bits/stdc++.h>
using namespace std;

int lower(int target, int len, vector<int> &vec)
{
    int l = 0, r = len;
    // cout << "DFGHJ";
    while (l < r)
    {
        int m = (l + r) / 2;
        if (vec[m] >= target)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int upper(int target, int len, vector<int> &vec)
{
    int l = 0, r = len;
    // cout << "DFGHJ";
    while (l < r)
    {
        int m = (l + r) / 2;
        if (vec[m] > target)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int main()
{
    int n, m, k;
    vector<int> vec;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < m; i++)
    {
        int num;
        scanf("%d", &num);

        int l = lower(num - k, n, vec);
        int u = upper(num + k, n, vec);

        printf("%d ", u - l);
    }

    return 0;
}
