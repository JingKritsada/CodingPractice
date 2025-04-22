#include <bits/stdc++.h>
using namespace std;

const int mxSize = 1e9;
bitset<mxSize> purchased;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            int l, r;
            cin >> l >> r;

            for (int j = l; j <= r; j++)
            {
                if (!purchased[j - 1] && !purchased[j] && !purchased[j + 1])
                {
                    cnt++;
                }
                if (purchased[j - 1] && !purchased[j] && purchased[j + 1])
                {
                    cnt--;
                }

                purchased[j] = true;
            }
        }
        else
        {
            cout << cnt << "\n";
        }
    }

    return 0;
}