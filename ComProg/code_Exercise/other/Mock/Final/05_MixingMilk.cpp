#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cap[3], vol[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> cap[i] >> vol[i];
    }

    for (int i = 0; i < 100; i++)
    {
        int curr = i % 3;
        int next = (i + 1) % 3;

        if (cap[next] < vol[curr] + vol[next])
        {
            vol[curr] = vol[curr] + vol[next] - cap[next];
            vol[next] = cap[next];
        }
        else
        {
            vol[next] = vol[curr] + vol[next];
            vol[curr] = 0;
        }

        // cout << curr << " -> " << next << " : " << vol[0] << " " << vol[1] << " " << vol[2] << " \n";
    }

    cout << vol[0] << " " << vol[1] << " " << vol[2] << " \n";

    return 0;
}