#include <bits/stdc++.h>
using namespace std;

int BS(int target, vector<int> &vec)
{
    int l = 0, r = vec.size() - 1;

    while (l < r)
    {
        int m = (l + r) / 2;
        if (vec[m] >= target)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    return l;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    unordered_map<int, int> changeMap;
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 0; i < n; i++)
    {
        int date, baht;
        cin >> date >> baht;

        changeMap[date] = baht;
    }

    int money = start;
    vector<int> quickSum;
    quickSum.push_back(start);

    for (int i = 1; i <= 100000; i++)
    {
        if (changeMap.find(i) != changeMap.end())
        {
            money = changeMap[i];
        }

        quickSum.push_back(quickSum[i - 1] + money);
    }

    for (int i = 0; i < m; i++)
    {
        int price, call, target;
        cin >> price >> call;

        if (price <= quickSum[call])
        {
            target = price;
        }
        else
        {
            target = price + quickSum[call];
        }

        int date = BS(target, quickSum);
        cout << date << " ";
    }

    return 0;
}
