#include <bits/stdc++.h>
using namespace std;

vector<string> cut(vector<string> before, int len)
{
    vector<string> after;
    for (int i = len / 2; i < len; i++)
    {
        after.push_back(before[i]);
    }
    for (int i = 0; i < len / 2; i++)
    {
        after.push_back(before[i]);
    }

    return after;
}

vector<string> shuffle(vector<string> before, int len)
{
    vector<string> after;
    int fro = 0, mid = len / 2;
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            after.push_back(before[fro]);
            fro++;
        }
        else
        {
            after.push_back(before[mid]);
            mid++;
        }
    }

    return after;
}

int main()
{
    int num;
    cin >> num;

    string tmp;
    vector<string> str;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        str.push_back(tmp);
    }

    string cmd;
    cin.ignore();
    getline(cin, cmd);
    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i] == 'C')
        {
            str = cut(str, num);
        }
        else if (cmd[i] == 'S')
        {
            str = shuffle(str, num);
        }
    }

    for (int i = 0; i < num; i++)
    {
        cout << str[i] << " ";
    }

    return 0;
}