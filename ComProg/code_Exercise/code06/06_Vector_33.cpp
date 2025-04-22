#include <bits/stdc++.h>
using namespace std;

struct party
{
    string name;
    int score;
    int num;
    double remainder;
};

bool compareR(party &a, party &b)
{
    return a.remainder > b.remainder;
}

bool compareN(party &a, party &b)
{
    if (a.num == b.num)
    {
        return a.score > b.score;
    }
    return a.num > b.num;
}

int main()
{
    vector<party> all;
    string name;
    int score, cnt = 100;
    double avg = 0;

    while (true)
    {
        cin >> name;
        if (name == "END")
        {
            break;
        }
        cin >> score;

        party temp = {name, score, 0, 0};
        all.push_back(temp);
        avg += score;
    }
    avg /= 100;

    for (auto &x : all)
    {
        x.num = x.score / avg;
        x.remainder = (x.score / avg) - x.num;
        cnt -= x.num;
    }

    sort(all.begin(), all.end(), compareR);
    for (int i = 0; i < cnt; i++)
    {
        all[i].num++;
    }

    sort(all.begin(), all.end(), compareN);
    for (auto &x : all)
    {
        if (x.num > 0)
        {
            cout << x.name << " " << x.num << " " << x.score << "\n";
        }
    }

    return 0;
}