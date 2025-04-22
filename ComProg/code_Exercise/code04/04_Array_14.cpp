#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    double Qsum[35][35] = {0};
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> Qsum[i][j];
            Qsum[i][j] = Qsum[i][j] + Qsum[i - 1][j] + Qsum[i][j - 1] - Qsum[i - 1][j - 1];
        }
    }

    for (int i = 3; i <= row; i++)
    {
        for (int j = 3; j <= col; j++)
        {
            double avg = Qsum[i][j] - Qsum[i - 3][j] - Qsum[i][j - 3] + Qsum[i - 3][j - 3];
            avg = avg / 9;
            cout << round(avg * 100) / 100.0 << " ";
        }
        cout << "\n";
    }

    return 0;
}