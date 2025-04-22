#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num;
    cin >> n;

    vector<int> vec;
    vector<int> sorted;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
        sorted.push_back(num);
    }

    sort(sorted.begin(), sorted.end());

    int tmp1 = 0, tmp2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > sorted[i])
        {
            tmp1++;
        }
        if (vec[i] < sorted[i])
        {
            tmp2++;
        }
    }

    cout << max(tmp1, tmp2);

    return 0;
}

// 1 1 2 2 2 3 3
// 2 2 1 3 2 1 3