#include <bits/stdc++.h>
using namespace std;

char table[25][25];
bool state[25][25] = {false};
int num;

bool move(int i, int j, int n)
{
    if (table[i][j] == 'Q' && n != 0)
    {
        state[i][j] = true;
        return true;
    }
    if (i < 0 || j < 0 || i >= num || j >= num)
    {
        return false;
    }

    int direcI[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    int direcJ[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

    if (n == 0)
    {
        return move(i + direcI[1], j + direcJ[1], 1) ||
               move(i + direcI[2], j + direcJ[2], 2) ||
               move(i + direcI[3], j + direcJ[3], 3) ||
               move(i + direcI[4], j + direcJ[4], 4) ||
               move(i + direcI[5], j + direcJ[5], 5) ||
               move(i + direcI[6], j + direcJ[6], 6) ||
               move(i + direcI[7], j + direcJ[7], 7) ||
               move(i + direcI[8], j + direcJ[8], 8);
    }
    else
    {
        return move(i + direcI[n], j + direcJ[n], n);
    }
}

int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (table[i][j] == 'Q' && state[i][j] == false)
            {
                state[i][j] = move(i, j, 0);
            }

            if (state[i][j] == true)
            {
                cout << '-';
            }
            else
            {
                cout << table[i][j];
            }
        }
        cout << "\n";
    }

    return 0;
}