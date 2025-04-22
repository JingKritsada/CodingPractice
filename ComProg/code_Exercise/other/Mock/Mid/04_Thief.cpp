#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, sumW, sum = 0, arr[100];
    cin >> num >> sumW;

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (sum - arr[i] - arr[j] == sumW)
            {
                cout << i << " " << arr[i] << "\n";
                cout << j << " " << arr[j];
            }
        }
    }

    return 0;
}