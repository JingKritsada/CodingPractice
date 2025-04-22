#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> fatherMp;
    for (int i = 0; i < n; i++)
    {
        string father, son;
        cin >> father >> son;
        fatherMp[son] = father;
    }

    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;

        if (a != b && fatherMp.find(a) != fatherMp.end() && fatherMp.find(b) != fatherMp.end())
        {
            if (fatherMp.find(fatherMp[a]) != fatherMp.end() && fatherMp.find(fatherMp[b]) != fatherMp.end())
            {
                if (fatherMp[fatherMp[a]] == fatherMp[fatherMp[b]])
                {
                    cout << "YES\n";
                    continue;
                }
            }
        }

        cout << "NO\n";
    }

    return 0;
}