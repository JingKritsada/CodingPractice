#include <bits/stdc++.h>
using namespace std;

struct info
{
    int price, order;
};

int main()
{
    unordered_map<string, unordered_map<string, info>> productMap;
    set<string> bidderSet;

    string bidder, product;
    int n, price;
    char cmd;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd >> bidder >> product;

        if (cmd == 'B')
        {
            cin >> price;
            bidderSet.insert(bidder);
            productMap[product][bidder] = {price, i};
        }
        else if (cmd == 'W')
        {
            if (productMap.find(product) != productMap.end() && productMap[product].find(bidder) != productMap[product].end())
            {
                productMap[product].erase(bidder);
            }
        }
    }

    unordered_map<string, vector<pair<int, string>>> ans;
    string temp;

    for (auto &p : productMap)
    {
        int mx = 0, mn = INT_MAX;
        for (auto &x : p.second)
        {
            if ((x.second.price > mx) || (x.second.price == mx && x.second.order < mn))
            {
                temp = x.first;
                mx = x.second.price;
                mn = x.second.order;
            }
        }

        if (mx > 0)
        {
            ans[temp].push_back({mx, p.first});
        }
    }

    for (auto &b : bidderSet)
    {
        vector<string> vec;
        int sum = 0;

        for (auto &p : ans[b])
        {
            vec.push_back(p.second);
            sum += p.first;
        }

        sort(vec.begin(), vec.end());

        if (vec.size() == 0)
        {
            cout << b << ": $0" << "\n";
        }
        else
        {
            cout << b << ": $" << sum << " -> ";

            for (auto e : vec)
            {
                cout << e << " ";
            }

            cout << "\n";
        }
    }

    return 0;
}