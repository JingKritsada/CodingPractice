#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, mx = 0, sum = 0;
    cin >> num;

    int arr[55];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }

    for (int i = mx; i > 0; i--)
    {
        int l = 0, r = 0, chk = 0;
        for (int j = 0; j < num; j++)
        {
            // cout << i << " " << r << " " << l << " " << sum << "\n" ;

            if (arr[j] >= i)
            {
                if (chk == 0)
                {
                    r = j;
                }
                else
                {
                    l = r;
                    r = j;
                    sum += r - l - 1;
                }
                chk++;
            }
        }
    }

    cout << sum;

    return 0;
}