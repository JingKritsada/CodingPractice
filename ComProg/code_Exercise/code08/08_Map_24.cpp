#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, double> priceMap;
    map<string, double> cntMap;
    double sum = 0, mx = 0;
    int n, m;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string product;
        double price;

        cin >> product >> price;
        priceMap[product] = price;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string product;
        int num;

        cin >> product >> num;
        if (priceMap.find(product) != priceMap.end())
        {
            if (cntMap.find(product) == cntMap.end())
            {
                cntMap[product] = 0;
            }

            sum += priceMap[product] * num;
            cntMap[product] += priceMap[product] * num;

            if (cntMap[product] > mx)
            {
                mx = cntMap[product];
            }
        }
    }

    if (sum == 0)
    {
        cout << "No ice cream sales";
    }
    else
    {
        cout << "Total ice cream sales: " << sum << "\n";
        cout << "Top sales:";

        for (auto &x : cntMap)
        {
            if (x.second == mx)
            {
                cout << " " << x.first;
            }
        }
    }

    return 0;
}