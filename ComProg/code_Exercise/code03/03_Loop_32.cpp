#include "bits/stdc++.h"
using namespace std;

int main()
{
    int nums, score;
    cin >> nums;
    cin.ignore();

    for (int h = 0; h < nums; h++)
    {
        string a;
        a.clear();
        getline(cin, a);
        int score = 0;

        bool y, g, n, b, p, k;
        y = false;
        g = false;
        n = false;
        b = false;
        p = false;
        k = false;

        for (int i = 0; i < a.size(); i++)
        {
            if (i % 2 != 0)
            {
                continue;
            }
            if (a[0] != 'R' || a[2] == 'R')
            {
                score = -1;
                break;
            }

            if (a[i] == 'R' && y == false)
            {
                if (a[i + 2] == 'Y')
                    score += 3;
                else if (a[i + 2] == 'G')
                    score += 4;
                else if (a[i + 2] == 'N')
                    score += 5;
                else if (a[i + 2] == 'B')
                    score += 6;
                else if (a[i + 2] == 'P')
                    score += 7;
                else if (a[i + 2] == 'K')
                    score += 8;
                else if (i + 2 > a.size())
                    score += 1;
                else
                {
                    score = -1;
                    break;
                }

                i += 2;
                continue;
            }

            if (a[i] == 'Y' && !y)
            {
                score += 2;
                y = true;
            }
            else if (a[i] == 'G' && y && !g)
            {
                score += 3;
                g = true;
            }
            else if (a[i] == 'N' && y && g && !n)
            {
                score += 4;
                n = true;
            }
            else if (a[i] == 'B' && y && g && n && !b)
            {
                score += 5;
                b = true;
            }
            else if (a[i] == 'P' && y && g && n && b && !p)
            {
                score += 6;
                p = true;
            }
            else if (a[i] == 'K' && y && g && n && b && p && !k)
            {
                score += 7;
                k = true;
            }
            else
            {
                score = -1;
                break;
            }
        }

        if (score == -1)
            cout << "WRONG_INPUT\n";
        else
            cout << score << "\n";
    }

    return 0;
}