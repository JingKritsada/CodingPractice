#include <bits/stdc++.h>
using namespace std;

int main()
{
    string command;
    double avg = 0;
    int n, curr, time, cnt = 0, temp;

    queue<int> customerQueue;
    unordered_map<int, int> startTime;

    cin >> n >> command >> curr;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> command;

        if (command == "new")
        {
            cin >> time;

            customerQueue.push(curr);
            startTime[curr] = time;
            cout << ">> ticket " << curr << "\n";

            curr++;
        }
        else if (command == "next")
        {
            temp = customerQueue.front();
            customerQueue.pop();
            cout << ">> call " << temp << "\n";
        }
        else if (command == "order")
        {
            cin >> time;
            int wait = time - startTime[temp];
            avg += wait;
            cnt++;

            cout << ">> qtime " << temp << " " << wait << "\n";
        }
        else if (command == "avg_qtime")
        {
            cout << ">> avg_qtime " << round((avg / cnt) * 100.0) / 100.0 << "\n";
        }
    }

    return 0;
}