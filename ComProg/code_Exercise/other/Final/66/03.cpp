#include <bits/stdc++.h>
using namespace std;

unordered_map<string, set<string>> ump;
unordered_map<string, string> current;
set<string> order;

void move()
{
    string name, post;
    cin >> name >> post;

    ump[current[name]].erase(name);
    ump[post].insert(name);
    order.insert(post);
    current[name] = post;
}

void combine()
{
    string pre, post;
    cin >> pre >> post;

    for (auto &x : ump[pre])
    {
        ump[post].insert(x);
    }

    ump.erase(pre);
    order.erase(pre);
}

int main()
{
    int n, m, cmd;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string name, dept;
        cin >> name >> dept;

        current[name] = dept;
        order.insert(dept);
        ump[dept].insert(name);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> cmd;

        if (cmd == 1)
        {
            move();
        }

        if (cmd == 2)
        {
            combine();
        }
    }

    for (auto &DEPT : order)
    {
        cout << DEPT << ":";
        for (auto &x : ump[DEPT])
        {
            cout << " " << x;
        }
        cout << "\n";
    }

    return 0;
}