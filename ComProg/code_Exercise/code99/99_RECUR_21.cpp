#include <bits/stdc++.h>
using namespace std;

const int R = 7, C = 7;
int arr[10][10];

void floodfill(int r, int c, int n)
{
    if (arr[r][c] != 0 || r >= R || r < 0 || c >= C || c < 0)
    {
        return;
    }

    arr[r][c] = n;

    floodfill(r + 1, c, n);
    floodfill(r - 1, c, n);
    floodfill(r, c + 1, n);
    floodfill(r, c - 1, n);
}

int main()
{
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            cin >> arr[r][c];
        }
    }

    int row, col, num;
    cin >> row >> col >> num;
    floodfill(row, col, num);

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            cout << arr[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}