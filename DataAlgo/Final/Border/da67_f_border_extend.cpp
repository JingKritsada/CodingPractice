#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c, k;
    cin >> r >> c >> k;

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

    vector<pair<int, int>> direc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<pair<int, int>> next;

    while (k--)
    {
        while (!curr.empty())
        {
            auto [curri, currj] = curr.front();
            curr.pop();

            for (auto [i, j] : direc)
            {
                int nexti = curri + i;
                int nextj = currj + j;

                if (1 <= nexti && nexti <= r && 1 <= nextj && nextj <= c && arr[nexti][nextj] == 0)
                {
                    arr[nexti][nextj] = 2;
                    next.push({nexti, nextj});
                }
            }
        }

        curr = next;
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}