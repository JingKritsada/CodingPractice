#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ans, stu;

    getline(cin, ans);
    getline(cin, stu);

    int lenA = ans.size();
    int lenS = stu.size();
    int cnt = 0;

    if (lenA != lenS)
    {
        cout << "Incomplete answer";
        return 0;
    }

    for (int i = 0; i < lenA; i++)
    {
        if (ans[i] == stu[i])
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}