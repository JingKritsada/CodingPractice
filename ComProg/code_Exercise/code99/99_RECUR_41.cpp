#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> warp;
set<vector<int>> ans;

void recur(int now, int target, vector<int> &path)
{
    path.push_back(now);

    if (now == target)
    {
        ans.insert(path);
    }
    else
    {
        for (auto next : warp[now])
        {
            recur(next, target, path);
        }
    }

    path.pop_back();
}

int main()
{
    int num, pos, des, sta, end;
    cin >> num >> pos >> des;

    for (int i = 0; i < num; i++)
    {
        cin >> sta >> end;
        warp[sta].push_back(end);
    }

    vector<int> path;
    recur(pos, des, path);

    if (ans.empty() == false)
    {
        for (auto x : ans)
        {
            for (int i = 0; i < x.size(); i++)
            {
                if (i != 0)
                {
                    cout << " -> ";
                }
                cout << x[i];
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "no";
    }

    return 0;
}