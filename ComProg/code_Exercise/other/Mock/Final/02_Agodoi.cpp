#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<int> s;
    vector<int> vec;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
        vec.push_back(num);
    }

    for (auto &num : vec)
    {
        if (s.find(2 * num) == s.end())
        {
            cout << "0 ";
        }
        else
        {
            cout << "1 ";
        }
    }

    return 0;
}