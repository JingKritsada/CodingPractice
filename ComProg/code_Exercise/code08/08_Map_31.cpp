#include <bits/stdc++.h>
using namespace std;

struct student
{
    string id;
    float score;
    vector<string> dept;

    bool operator<(const student &x) const
    {
        return score > x.score;
    }
};

int main()
{
    unordered_map<string, int> deptMap;
    int n, m, num;
    string dept;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dept >> num;
        deptMap[dept] = num;
    }

    string id, tmp1, tmp2, tmp3, tmp4;
    map<string, string> ans;
    vector<student> data;
    float score;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> id >> score >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        data.push_back({id, score, {tmp1, tmp2, tmp3, tmp4}});
    }

    sort(data.begin(), data.end());
    for (auto stu : data)
    {
        for (auto dept : stu.dept)
        {
            if (deptMap[dept] > 0)
            {
                deptMap[dept]--;
                ans[stu.id] = dept;
                break;
            }
        }
    }

    for (auto x : ans)
    {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}