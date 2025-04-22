#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b)
{
    if (a >= b)
    {
        return;
    }

    int temp;
    b--;

    temp = *a;
    *a = *b;
    *b = temp;

    reverse(v, ++a, b);
}

int main()
{
    vector<int> v;
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }

    cin >> a >> b;

    reverse(v, v.begin() + a, v.begin() + b + 1);

    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
