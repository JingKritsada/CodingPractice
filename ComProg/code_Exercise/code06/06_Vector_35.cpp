#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp =
    {
        {"soon", 0}, {"neung", 1}, {"song", 2}, {"sam", 3}, {"si", 4}, {"ha", 5}, {"hok", 6}, {"chet", 7}, {"paet", 8}, {"kao", 9},

        {"et", 1},
        {"yi", 2},

        {"sip", 10},
        {"roi", 100},
        {"phan", 1000},
        {"muen", 10000},
        {"saen", 100000},
        {"lan", 1000000}};

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (line == "q")
        {
            break;
        }

        string word;
        stringstream ss(line);

        bool chk = false;
        int number = 0, cnt = 0, tmp = 0;

        while (ss >> word)
        {
            if (cnt % 2 == 0)
            {
                if (word == "sip" && tmp == 0)
                {
                    chk = true;
                }
                tmp = mp[word];
            }
            else
            {
                if (chk == false)
                {
                    tmp *= mp[word];
                }
                number += tmp;
                tmp = 0;
            }

            cnt++;
        }

        if (chk == false)
        {
            number += mp[word] % 10;
        }
        else
        {
            number += mp[word];
        }
        cout << number << "\n";
    }

    return 0;
}