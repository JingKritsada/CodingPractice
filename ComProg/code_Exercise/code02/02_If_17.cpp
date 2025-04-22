#include <bits/stdc++.h>
using namespace std;

int main()
{
    int wei;
    cin >> wei;

    if (wei > 2000)
    {
        cout << "Reject";
    }
    else if (wei > 1000)
    {
        cout << 58;
    }
    else if (wei > 500)
    {
        cout << 38;
    }
    else if (wei > 250)
    {
        cout << 28;
    }
    else if (wei > 100)
    {
        cout << 22;
    }
    else
    {
        cout << 18;
    }

    return 0;
}