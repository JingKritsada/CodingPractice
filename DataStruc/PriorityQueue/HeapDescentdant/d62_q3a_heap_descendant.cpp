#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;

    vector<int> ans;
    queue<int> que;
    que.push(a);

    while (!que.empty())
    {
        int temp = que.front();
        que.pop();

        ans.push_back(temp);

        if (temp * 2 + 1 < n)
        {
            que.push(temp * 2 + 1);
        }
        if (temp * 2 + 2 < n)
        {
            que.push(temp * 2 + 2);
        }
    }

    cout << ans.size() << "\n";
    for (auto &x : ans)
    {
        cout << x << " ";
    }

    return 0;
}