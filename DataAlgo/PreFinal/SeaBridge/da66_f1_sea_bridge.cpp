#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    int arr[r + 1][c + 1];
    queue<pair<int, int>> curr;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                curr.push({i, j});
            }
        }
    }

    vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool chk = false;
    int cnt = 2;

    while (true)
    {
        queue<pair<int, int>> next;

        while (!curr.empty())
        {
            auto tmp = curr.front();
            curr.pop();

            for (auto [x, y] : direc)
            {
                int nextX = tmp.first + x;
                int nextY = tmp.second + y;

                if ((1 <= nextX && nextX <= r) && (1 <= nextY && nextY <= c) && (arr[nextX][nextY] == 0 || arr[nextX][nextY] == 2))
                {
                    if (arr[nextX][nextY] == 2)
                    {
                        chk = true;
                        break;
                    }

                    arr[nextX][nextY] = 1;
                    next.push({nextX, nextY});
                }
            }
        }

        if (chk)
        {
            break;
        }

        cnt++;
        curr = next;
    }

    cout << cnt;

    return 0;
}