/*
#include <bits/stdc++.h>
using namespace std;

struct student
{
    string code;
    int grade, order;
};

bool cmp(student &a, student &b)
{
    if (a.grade == b.grade)
    {
        return a.order < b.order;
    }
    return a.grade > b.grade;
}

unordered_map<string, int> grade2num = {{"F", 1}, {"D", 2}, {"D+", 3}, {"C", 4}, {"C+", 5}, {"B", 6}, {"B+", 7}, {"A", 8}};
string num2grade[10] = {"", "F", "D", "D+", "C", "C+", "B", "B+", "A"};
unordered_map<string, student> mp;

int main()
{
    int n;
    cin >> n;

    string num, grade;
    for (int idx = 0; idx < n; idx++)
    {
        cin >> num >> grade;
        mp[num] = {num, grade2num[grade], idx};
    }

    string command;
    while (cin >> command)
    {
        if (command == "end")
        {
            break;
        }

        char tmp = command[command.size() - 1];
        command.pop_back();

        if (tmp == '+' && mp[command].grade < 8)
        {
            mp[command].grade++;
        }
        else if (tmp == '-' && mp[command].grade > 1)
        {
            mp[command].grade--;
        }
    }

    vector<student> vec;
    for (auto x : mp)
    {
        vec.push_back(x.second);
    }

    sort(vec.begin(), vec.end(), cmp);
    for (auto x : vec)
    {
        cout << x.code << " " << num2grade[x.grade] << "\n";
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> grade2num = {{"F", 1}, {"D", 2}, {"D+", 3}, {"C", 4}, {"C+", 5}, {"B", 6}, {"B+", 7}, {"A", 8}};
string num2grade[10] = {"", "F", "D", "D+", "C", "C+", "B", "B+", "A", "A"};
unordered_map<string, int> mp;
vector<string> order;

int main()
{
    string num, grade;
    while (cin >> num)
    {
        if (num == "q")
        {
            break;
        }

        cin >> grade;
        order.push_back(num);
        mp[num] = grade2num[grade];
    }

    string command;
    while (cin >> command)
    {
        if (command == "end")
        {
            break;
        }

        mp[command]++;
    }

    for (auto x : order)
    {
        cout << x << " " << num2grade[mp[x]] << "\n";
    }

    return 0;
}