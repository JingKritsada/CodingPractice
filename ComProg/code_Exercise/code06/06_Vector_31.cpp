#include <bits/stdc++.h>
using namespace std;

bool chk(vector<string> str, vector<string> tar)
{
    for (auto x : str)
    {
        if (find(tar.begin(), tar.end(), x) == tar.end())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char bingo[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> bingo[i];
    }

    string tmp, table[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> tmp;
            table[i][j] = bingo[j] + tmp;
        }
    }

    vector<vector<string>> allTable;
    vector<string> vec;

    // ------------------------------------------------
    for (int i = 0; i < 5; i++)
    {
        vec.clear();
        for (int j = 0; j < 5; j++)
        {
            vec.push_back(table[i][j]);
        }
        allTable.push_back(vec);
    }

    for (int i = 0; i < 5; i++)
    {
        vec.clear();
        for (int j = 0; j < 5; j++)
        {
            vec.push_back(table[j][i]);
        }
        allTable.push_back(vec);
    }

    vec.clear();
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(table[i][i]);
    }
    allTable.push_back(vec);

    vec.clear();
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(table[4 - i][i]);
    }
    allTable.push_back(vec);
    // ------------------------------------------------

    bool hasBingo = false;
    int cnt = 1, n = allTable.size();
    vector<string> target;
    target.push_back(table[2][2]);
    string str;

    while (!hasBingo)
    {
        cin >> str;
        target.push_back(str);

        for (int i = 0; i < n; i++)
        {
            if (chk(allTable[i], target))
            {
                if (!hasBingo)
                {
                    cout << cnt << "\n";
                    hasBingo = true;
                }

                string ans;
                for (auto x : allTable[i])
                    if (x != table[2][2])
                    {
                        ans += x + ", ";
                    }

                cout << ans.substr(0, ans.size() - 2) << "\n";
            }
        }
        cnt++;
    }

    return 0;
}