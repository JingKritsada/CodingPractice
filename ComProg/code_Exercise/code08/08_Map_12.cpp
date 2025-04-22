#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    string name, surname, num, tmp;
    unordered_map<string, string> name2num;
    unordered_map<string, string> num2name;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> surname >> num;
        tmp = name + " " + surname;

        name2num[tmp] = num;
        num2name[num] = tmp;
    }

    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        getline(cin, tmp);
        if (name2num.find(tmp) != name2num.end())
        {
            cout << tmp << " --> " << name2num[tmp] << "\n";
        }
        else if (num2name.find(tmp) != num2name.end())
        {
            cout << tmp << " --> " << num2name[tmp] << "\n";
        }
        else
        {
            cout << tmp << " --> " << "Not found\n";
        }
    }

    return 0;
}