#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    int sumA = accumulate(a.begin(), a.end(), 0);
    int sumB = accumulate(b.begin(), b.end(), 0);

    if (sumA != sumB)
    {
        return sumA > sumB;
    }
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }

    return a < b;
}

void printResult(vector<vector<int>> &result)
{
    for (auto &sublist : result)
    {
        sort(sublist.begin(), sublist.end());
    }
    sort(result.begin(), result.end(), compare);

    for (auto &sublist : result)
    {
        for (auto number : sublist)
        {
            cout << number << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> firstFit(vector<int> &numbers)
{
    vector<vector<int>> result;
    for (int num : numbers)
    {
        bool placed = false;
        for (auto &sublist : result)
        {
            int sum = accumulate(sublist.begin(), sublist.end(), 0) + num;
            if (sum <= 100)
            {
                sublist.push_back(num);
                placed = true;
                break;
            }
        }
        if (!placed)
        {
            vector<int> sublist;
            sublist.push_back(num);
            result.push_back(sublist);
        }
    }

    return result;
}

vector<vector<int>> bestFit(vector<int> &numbers)
{
    vector<vector<int>> result;
    for (int num : numbers)
    {
        int mn = 101, best = -1;
        for (int i = 0; i < result.size(); i++)
        {
            int sum = accumulate(result[i].begin(), result[i].end(), 0);
            int left = 100 - sum;

            if (num <= left && left < mn)
            {
                best = i;
                mn = left;
            }
        }

        if (best != -1)
        {
            result[best].push_back(num);
        }
        else
        {
            vector<int> sublist;
            sublist.push_back(num);
            result.push_back(sublist);
        }
    }

    return result;
}

int main()
{
    string command;
    cin >> command;

    int num;
    vector<int> numbers;
    while (cin >> num)
    {
        numbers.push_back(num);
    }

    vector<vector<int>> res;
    if (command == "first")
    {
        res = firstFit(numbers);
    }
    else
    {
        res = bestFit(numbers);
    }

    printResult(res);

    return 0;
}