#include <bits/stdc++.h>
using namespace std;

vector<string> split(string line, char delimiter)
{
    vector<string> str;
    string tmp;

    for (char x : line)
    {
        if (x == delimiter)
        {
            if (tmp.size() > 0)
            {
                str.push_back(tmp);
            }
            tmp = "";
        }
        else
        {
            tmp += x;
        }
    }

    if (tmp.size() > 0)
    {
        str.push_back(tmp);
    }

    return str;
}

int main()
{
    string line, delim;
    getline(cin, line);
    getline(cin, delim);

    for (string e : split(line, delim[0]))
    {
        cout << '(' << e << ')';
    }
}