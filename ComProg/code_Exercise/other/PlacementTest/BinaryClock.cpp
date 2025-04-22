#include <bits/stdc++.h>
using namespace std;

int main()
{
    string time;
    cin >> time;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (((j == 0 || j == 3 || j == 6) && i == 0) || (i == 1 && j == 0))
            {
                cout << " ";
                continue;
            }
            if (j == 2 || j == 5)
            {
                continue;
            }

            int n = time[j] - '0';
            int b = pow(2, 3 - i);

            cout << n / b;
            time[j] = n % b + '0';
        }
        cout << "\n";
    }

    return 0;
}