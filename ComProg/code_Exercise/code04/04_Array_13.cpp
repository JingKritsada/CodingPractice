#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;

    int num[n];
    cin >> num[0] >> num[1];
    for (int i = 2; i < n; i++)
    {
        cin >> num[i];
        if (num[i - 1] > num[i - 2] && num[i - 1] > num[i])
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}