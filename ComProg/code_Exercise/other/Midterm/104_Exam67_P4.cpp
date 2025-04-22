#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, beads[2000], mx = 0;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> beads[i];
        beads[i + num] = beads[i];
    }

    for (int sta = 0; sta < num; sta++)
    {
        for (int skip = sta - 1; skip < num + sta; skip++)
        {
            int sum = 0, prev = 0;

            for (int i = sta; i < num + sta; i++)
            {
                if (i == skip)
                {
                    continue;
                }

                if (beads[i] < prev)
                {
                    break;
                }

                // cout << beads[i] << " ";
                sum += beads[i];
                prev = beads[i];
            }

            // cout << " -> " << sum << "\n";
            if (sum > mx)
            {
                mx = sum;
            }
        }
    }

    cout << mx;

    return 0;
}