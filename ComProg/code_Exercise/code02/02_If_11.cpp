#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    if (str == "01" || str == "02" || str == "20" ||
        str == "21" || str == "22" || str == "23" ||
        str == "24" || str == "25" || str == "26" ||
        str == "27" || str == "28" || str == "29" ||
        str == "30" || str == "31" || str == "32" ||
        str == "33" || str == "34" || str == "35" ||
        str == "36" || str == "37" || str == "38" ||
        str == "39" || str == "40" || str == "51" ||
        str == "53" || str == "55" || str == "58")
    {
        cout << "OK";
    }
    else
    {
        cout << "Error";
    }

    return 0;
}