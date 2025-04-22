#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> winTeam;
    set<string> loseTeam;

    bool chk = false;
    string win, lose;
    while (cin >> win >> lose)
    {
        winTeam.insert(win);
        loseTeam.insert(lose);
    }

    for (auto team : winTeam)
    {
        if (loseTeam.find(team) == loseTeam.end())
        {
            cout << team << " ";
            chk = true;
        }
    }

    if (chk == false)
    {
        cout << "None";
    }

    return 0;
}