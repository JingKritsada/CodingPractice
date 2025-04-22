#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    cin >> num;

    if (num.size() == 10 && num[0] == '0' && (num[1] == '6' || num[1] == '8' || num[1] == '9'))
    {
        cout << "Mobile number";
    }
    else
    {
        cout << "Not a mobile number";
    }

    return 0;
}