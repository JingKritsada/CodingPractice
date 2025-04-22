#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

int time2sec(string &str)
{
    int minute, second;
    char colon;

    stringstream ss(str);
    ss >> minute >> colon >> second;

    return minute * 60 + second;
}

string sec2time(int &second)
{
    int minute = second / 60;
    second = second % 60;

    stringstream ss;
    ss << minute << ":" << second;

    return ss.str();
}

int main()
{
    string music, name, type, time;
    unordered_map<string, int> mp;

    while (cin >> music)
    {
        if (music == "end")
        {
            break;
        }

        cin >> name >> type >> time;
        int second = time2sec(time);
        mp[type] += second;
    }

    vector<pair<string, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < 3 && i < vec.size(); i++)
    {
        cout << vec[i].first << " --> " << sec2time(vec[i].second) << "\n";
    }

    return 0;
}