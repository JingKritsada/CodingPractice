#include <bits/stdc++.h>
using namespace std;

int num, m;
map<string, int> freq;
vector<string> buckets;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
};

void combi(int idx, string str)
{
    if (idx == num)
    {
        sort(str.begin(), str.end());
        freq[str]++;
        return;
    }
    for (int i = 0; i < buckets[idx].size(); i++)
    {
        combi(idx + 1, str + buckets[idx][i]);
    }
}

int main()
{
    cin >> num;

    string tmp;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        buckets.push_back(tmp);
    }
    cin >> m;

    combi(0, "");
    vector<pair<string, int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < m && i < vec.size(); i++)
    {
        cout << vec[i].first << "\n";
    }

    return 0;
}