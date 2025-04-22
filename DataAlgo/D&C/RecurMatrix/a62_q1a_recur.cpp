#include <bits/stdc++.h>
using namespace std;

void recur(int a, int b, int row, int col, vector<vector<int>> &matrix)
{
    if (a == 0)
    {
        matrix[row][col] = b;
        return;
    }

    int tmp = pow(2, a - 1);

    recur(a - 1, b, row, col, matrix);
    recur(a - 1, b - 1, row, col + tmp, matrix);
    recur(a - 1, b + 1, row + tmp, col, matrix);
    recur(a - 1, b, row + tmp, col + tmp, matrix);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int sz = pow(2, a);
    vector<vector<int>> matrix(sz, vector<int>(sz));
    recur(a, b, 0, 0, matrix);

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}