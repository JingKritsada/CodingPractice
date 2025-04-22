#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, row, cnt = 0;
    cin >> num;

    vector<int> inversion;
    int arr[num + 5][num + 5];

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 0)
            {
                row = i;
            }
            else
            {
                inversion.push_back(arr[i][j]);
            }
        }
    }

    int len = inversion.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (inversion[i] > inversion[j])
            {
                cnt++;
            }
        }
    }

    if (num % 2 == 0)
    {
        if ((cnt % 2 == 0 && row % 2 != 0) || (cnt % 2 != 0 && row % 2 == 0))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        if (cnt % 2 == 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }

    return 0;
}