#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<set<string>, int> record;
    int n, mx = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        set<string> temp = {s1, s2, s3};

        record[temp]++;

        if (record[temp] > mx)
        {
            mx = record[temp];
        }
    }

    cout << mx;

    return 0;
}