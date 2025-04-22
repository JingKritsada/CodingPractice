#include <bits/stdc++.h>
using namespace std;

vector<int> flip(vector<int> before, int end)
{
    vector<int> after = before;
    for (int i = 0; i <= end; i++)
    {
        after[i] = before[end - i];
    }

    return after;
}

int main()
{
    int num, tmp;
    cin >> num;

    vector<int> vec;
    priority_queue<int> pq;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
        pq.push(tmp);
        cout << tmp << " ";
    }
    cout << "\n";

    int idxMX;
    while (!pq.empty())
    {
        int len = pq.size();
        for (int i = 0; i < len; i++)
        {
            if (vec[i] == pq.top())
            {
                idxMX = i;
            }
        }

        if (idxMX == len - 1)
        {
            pq.pop();
            continue;
        }
        else if (idxMX == 0)
        {
            vec = flip(vec, len - 1);
        }
        else
        {
            vec = flip(vec, idxMX);
        }

        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}