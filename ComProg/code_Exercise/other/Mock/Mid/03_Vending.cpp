#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long price, num, sum = 0;
    string temp;
    char cha;

    cin >> price;
    cin.ignore();

    getline(cin, temp);
    stringstream ss(temp);

    while (ss >> cha >> num)
    {
        sum += num;
        // cout << sum << " " ;
    }

    cout << sum * price;

    return 0;
}