#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> path;
bool visited[1000];

bool recur(int now, int target)
{
    if (now == target)
    {
        return true;
    }

    for (auto next : path[now])
    {
        if (visited[next] == false)
        {
            visited[next] = true;
            if (recur(next, target))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int num, pos, des, sta, end;
    cin >> num >> pos >> des;

    for (int i = 0; i < num; i++)
    {
        cin >> sta >> end;
        path[sta].push_back(end);
    }

    if (recur(pos, des))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}