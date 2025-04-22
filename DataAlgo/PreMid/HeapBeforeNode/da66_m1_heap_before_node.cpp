#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ans;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        if (tmp != m)
        {
            ans.push_back(tmp);

            if (tmp * 2 + 1 < n)
            {
                q.push(tmp * 2 + 1);
            }
            if (tmp * 2 + 2 < n)
            {
                q.push(tmp * 2 + 2);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &x : ans)
    {
        cout << x << " ";
    }

    return 0;
}