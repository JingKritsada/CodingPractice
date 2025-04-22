#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    string name, nickname, tmp;
    unordered_map<string, string> name2nickname;
    unordered_map<string, string> nickname2name;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> nickname;
        name2nickname[name] = nickname;
        nickname2name[nickname] = name;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        if (name2nickname.find(tmp) != name2nickname.end())
        {
            cout << name2nickname[tmp] << "\n";
        }
        else if (nickname2name.find(tmp) != nickname2name.end())
        {
            cout << nickname2name[tmp] << "\n";
        }
        else
        {
            cout << "Not found\n";
        }
    }

    return 0;
}