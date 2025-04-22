#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    if (num > 0)
    {
        cout << "positive";
    }
    else if (num < 0)
    {
        cout << "negative";
    }
    else
    {
        cout << "zero";
    }

    num = (num < 0) * (num * -1) + (num > 0) * num;
    if (num % 2 == 0)
    {
        cout << "\neven";
    }
    else
    {
        cout << "\nodd";
    }

    return 0;
}