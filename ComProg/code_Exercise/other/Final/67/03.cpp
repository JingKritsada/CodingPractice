#include <bits/stdc++.h>
using namespace std;

vector<int> mnX(5, INT_MAX), mnY(5, INT_MAX);
vector<int> mxX(5, INT_MIN), mxY(5, INT_MIN);
vector<bool> chk(5, false);

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y, Q;
        cin >> x >> y;

        if (x > 0 && y > 0)
        {
            Q = 1;
            chk[1] = true;
        }
        else if (x < 0 && y > 0)
        {
            Q = 2;
            chk[2] = true;
        }
        else if (x < 0 && y < 0)
        {
            Q = 3;
            chk[3] = true;
        }
        else if (x > 0 && y < 0)
        {
            Q = 4;
            chk[4] = true;
        }
        else
        {
            continue;
        }

        mnX[Q] = min(mnX[Q], x);
        mnY[Q] = min(mnY[Q], y);

        mxX[Q] = max(mxX[Q], x);
        mxY[Q] = max(mxY[Q], y);
    }

    if (!chk[1] && !chk[2] && !chk[3] && !chk[4])
    {
        cout << "No point in any quadrant";
        return 0;
    }
    for (int Q = 1; Q <= 4; Q++)
    {
        if (chk[Q])
        {
            int area = (mxX[Q] - mnX[Q]) * (mxY[Q] - mnY[Q]);
            printf("Q%d: (%d, %d) (%d, %d) %d\n", Q, mnX[Q], mnY[Q], mxX[Q], mxY[Q], area);
        }
    }

    return 0;
}