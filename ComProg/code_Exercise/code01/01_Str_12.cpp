#include <bits/stdc++.h>
using namespace std;

int main()
{
    string month[12] = {"JAN", "FEB", "MAR", "APR",
                        "MAY", "JUN", "JUL", "AUG",
                        "SEP", "OCT", "NOV", "DEC"};

    string str;
    cin >> str;

    int d = ((str[0] - '0') * 10) + (str[1] - '0');
    int m = ((str[3] - '0') * 10) + (str[4] - '0');
    int y = ((str[6] - '0') * 1000) + ((str[7] - '0') * 100) + ((str[8] - '0') * 10) + (str[9] - '0') - 543;

    cout << month[m - 1] << " " << d << ", " << y;

    return 0;
}