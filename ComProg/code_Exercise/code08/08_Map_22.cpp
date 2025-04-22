#include <bits/stdc++.h>
using namespace std;

unordered_map<string, double> rateMap = {{"THB", 1.0}};

int main()
{
    int n;
    double num, rate;
    string country, curr, next;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> country >> rate;
        rateMap[country] = rate;
    }

    cin >> num >> curr;
    cout << num << " " << curr;

    while (cin >> next)
    {
        // cout << "\n" << num << " " << rateMap[curr] << " " << rateMap[next] ;
        num = floor((num * rateMap[curr]) / rateMap[next]);
        cout << " -> " << fixed << setprecision(0) << num << " " << next;
        curr = next;
    }

    return 0;
}