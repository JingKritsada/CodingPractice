#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, idx = 0, tmp;
    int mnA = INT_MAX, mxA = 0;
    int mnB = INT_MAX, mxB = 0;

    while (true)
    {
        cin >> a;
        if (a == -998 || a == -999)
        {
            break;
        }

        cin >> b;

        if (idx % 2 != 0)
        {
            tmp = a;
            a = b;
            b = tmp;
        }
        idx++;

        if (a < mnA)
            mnA = a;
        if (a > mxA)
            mxA = a;
        if (b < mnB)
            mnB = b;
        if (b > mxB)
            mxB = b;

        // cout << a << " " << b << "\n" ;
    }

    if (a == -998)
    {
        cout << mnA << " " << mxB;
    }
    else
    {
        cout << mnB << " " << mxA;
    }

    return 0;
}