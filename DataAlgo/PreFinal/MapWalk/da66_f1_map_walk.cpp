#include <bits/stdc++.h>
using namespace std;

bool block[12][12];
bool visited[12][12];

void walk(int curR, int curC, int r, int c, string ans)
{
    if (curR == r && curC == c)
    {
        cout << ans << "\n";
        return;
    }

    visited[curR][curC] = true;

    if (curC < c && !visited[curR][curC + 1] && !block[curR][curC + 1])
    {
        walk(curR, curC + 1, r, c, ans + "A");
    }
    if (curR < r && !visited[curR + 1][curC] && !block[curR + 1][curC])
    {
        walk(curR + 1, curC, r, c, ans + "B");
    }
    if (curR > 1 && !visited[curR - 1][curC] && !block[curR - 1][curC])
    {
        walk(curR - 1, curC, r, c, ans + "C");
    }

    visited[curR][curC] = false;
}

int main()
{
    int r, c;
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> block[i][j];
        }
    }

    walk(1, 1, r, c, "");
    cout << "DONE";

    return 0;
}