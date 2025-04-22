#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, set<string>> mp;
    string id, city, keyID;
    vector<string> order;
    bool chk = false;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> id;
        order.push_back(id);

        set<string> allcity;
        while (cin >> city && city != "*")
        {
            allcity.insert(city);
        }
        mp[id] = allcity;
    }

    cin >> keyID;
    set<string> keyCity = mp[keyID];

    for (auto &user : order)
    {
        if (user == keyID)
        {
            continue;
        }

        for (auto &city : mp[user])
        {
            if (keyCity.find(city) != keyCity.end())
            {
                cout << ">> " << user << "\n";
                chk = true;
                break;
            }
        }
    }

    if (chk == false)
    {
        cout << ">> Not Found";
    }

    return 0;
}