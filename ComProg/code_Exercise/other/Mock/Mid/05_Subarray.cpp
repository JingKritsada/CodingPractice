#include <bits/stdc++.h>
using namespace std;

bool chk(vector<int> &subArray, int length)
{
    unordered_map<int, int> mp;
    for (auto x : subArray)
    {
        mp[x]++;
    }

    for (int i = 1; i <= length; i++)
    {
        if (mp[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, num;
    vector<int> vec;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    int cnt = 0;
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i < n; i++)
        {
            if (len + i > n)
            {
                break;
            }

            vector<int> temp;
            for (int j = i; j < len + i; j++)
            {
                temp.push_back(vec[j]);
            }

            if (chk(temp, len) == true)
            {
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}