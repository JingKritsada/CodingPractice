#include <bits/stdc++.h>
using namespace std;

struct item
{
    double price, weight;
};

bool cmp(item &a, item &b)
{
    return a.price / a.weight > b.price / b.weight;
}

int main()
{
    int n;
    double w;
    cin >> w >> n;

    vector<item> vec(n);
    for (auto &x : vec)
    {
        cin >> x.price;
    }
    for (auto &x : vec)
    {
        cin >> x.weight;
    }

    sort(vec.begin(), vec.end(), cmp);

    double ans, remain = w;
    for (auto &x : vec)
    {
        if (remain <= x.weight)
        {
            ans += (x.price / x.weight) * remain;
            break;
        }

        ans += x.price;
        remain -= x.weight;
    }

    printf("%.4f", ans);

    return 0;
}