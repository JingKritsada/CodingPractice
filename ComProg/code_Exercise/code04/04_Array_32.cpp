#include <bits/stdc++.h>
using namespace std;

struct elevator
{
    int num, cur, des;
};

int cal(elevator x, int user, int target)
{
    if ((x.cur <= user && user <= x.des) || (x.cur >= user && user >= x.des))
    {
        return abs(target - x.des);
    }
    else
    {
        return abs(x.des - user) + abs(target - user);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<elevator> vec;
    for (int i = 0; i < n; i++)
    {
        int num, cur, des;
        cin >> num >> cur >> des;

        elevator x = {num, cur, des};
        vec.push_back(x);
    }

    int que;
    cin >> que;
    for (int i = 0; i < que; i++)
    {
        int sta, end;
        cin >> sta >> end;

        int mn = INT_MAX, ans = INT_MAX;
        for (auto x : vec)
        {
            int temp = cal(x, sta, end);
            if (temp < mn || (temp == mn && x.num < ans))
            {
                mn = temp;
                ans = x.num;
            }
        }

        cout << ">> " << ans << "\n";
    }

    return 0;
}