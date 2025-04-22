#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num;
    long long d = 2;

    cin >> num;

    if (num < 2)
    {
        cout << "No prime factors for numbers less than 2.";
    }
    else
    {
        while (num > 1)
        {
            if (d * d > num)
            {
                cout << num;
                return 0;
            }
            else
            {
                while (num % d == 0)
                {
                    num /= d;
                    cout << d << " ";
                }

                d++;
            }
        }
    }

    return 0;
}