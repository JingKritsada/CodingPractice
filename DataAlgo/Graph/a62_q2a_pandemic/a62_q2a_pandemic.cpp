#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, t;
    cin >> r >> c >> t;

    int cnt = 0;
    int arr[r][c];
    queue<pair<int, int>> curr;
    vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
            {
                cnt++;
                curr.push({i, j});
            }
        }
    }

    while (t--)
    {
        queue<pair<int, int>> next;

        while (!curr.empty())
        {
            auto tmp = curr.front();
            curr.pop();

            for (auto &[x, y] : direc)
            {
                int tmpX = tmp.first + x;
                int tmpY = tmp.second + y;

                if ((0 <= tmpX && tmpX < r) && (0 <= tmpY && tmpY < c) && arr[tmpX][tmpY] == 0)
                {
                    cnt++;
                    arr[tmpX][tmpY] = 1;
                    next.push({tmpX, tmpY});
                }
            }
        }

        curr = next;
    }

    cout << cnt;

    return 0;
}