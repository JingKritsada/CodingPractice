#include <bits/stdc++.h>
using namespace std;

void multiple_add(vector<int> &v, int value, int position, int count)
{
    vector<int> vec;
    while (count--)
    {
        vec.push_back(value);
    }

    v.insert(v.begin() + position, vec.begin(), vec.end());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, value, position, count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    multiple_add(v, value, position, count);

    cout << "After call multiple_add" << endl
         << "Size = " << v.size() << endl;

    for (auto &x : v)
    {
        cout << x << " ";
    }

    cout << endl;
}