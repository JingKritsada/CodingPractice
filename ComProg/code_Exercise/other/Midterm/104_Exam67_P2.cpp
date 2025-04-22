#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mp =
        {
            {"1", 1},
            {"2", 2},
            {"3", 3},
            {"4", 4},
            {"5", 5},
            {"6", 6},
            {"7", 7},
            {"8", 8},
            {"9", 9},
            {"10", 10},
            {"J", 10},
            {"Q", 10},
            {"K", 10},
            {"A", 1},
        };

    int a, b, sumA = 0, sumB = 0, cntA = 0, cntB = 0;
    string card;

    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        cin >> card;

        if (card == "A")
        {
            cntA++;
        }

        sumA += mp[card];
    }

    for (int i = 0; i < a; i++)
    {
        cin >> card;

        if (card == "A")
        {
            cntB++;
        }

        sumB += mp[card];
    }

    while (sumA < 12 && cntA > 0)
    {
        sumA += 10;
        cntA--;
    }

    while (sumB < 12 && cntB > 0)
    {
        sumB += 10;
        cntB--;
    }

    if (sumA == sumB || (sumA > 21 && sumB > 21))
    {
        cout << "Draw\n";
    }
    else if ((sumA > sumB && sumA <= 21) || sumB > 21)
    {
        cout << "A\n";
    }
    else if ((sumB > sumA && sumB <= 21) || sumA > 21)
    {
        cout << "B\n";
    }

    cout << sumA << " " << sumB;

    return 0;
}