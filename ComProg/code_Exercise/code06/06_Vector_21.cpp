#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    str += "$";
    int len = str.size();

    vector<string> bwt;
    for (int i = 0; i < len; i++)
    {
        bwt.push_back(str);
        str = str.substr(1, len - 1) + str.substr(0, 1);
    }

    sort(bwt.begin(), bwt.end());
    for (int i = 0; i < len; i++)
    {
        cout << bwt[i][len - 1];
    }

    return 0;
}