#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> dist(r, vector<int>(c, 0));
    queue<pair<int, int>> q;

    arr[0][0] = 0;
    int ans = 0;

    q.push({0, 0});
    while (!q.empty())
    {
        auto [curri, currj] = q.front();
        q.pop();

        for (auto [i, j] : direc)
        {
            int nexti = curri + i;
            int nextj = currj + j;

            if ((0 <= nexti && nexti < r) && (0 <= nextj && nextj < c) && arr[nexti][nextj] != 0 && dist[nexti][nextj] == 0)
            {
                dist[nexti][nextj] = dist[curri][currj] + 1;
                q.push({nexti, nextj});

                if (arr[nexti][nextj] == 2)
                {
                    ans += dist[nexti][nextj];
                }
            }
        }
    }

    cout << ans * 2;

    return 0;
}