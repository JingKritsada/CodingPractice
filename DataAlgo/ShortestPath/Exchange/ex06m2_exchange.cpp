#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int m;
        cin >> m;

        vector<vector<double>> currency(m, vector<double>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> currency[i][j];
            }
        }

        bool chk = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    if (currency[i][k] * currency[k][j] > currency[i][j])
                    {
                        currency[i][j] = currency[i][k] * currency[k][j];
                    }

                    if (currency[k][k] > 1)
                    {
                        cout << "YES\n";
                        chk = true;
                        break;
                    }
                }

                if (chk)
                {
                    break;
                }
            }

            if (chk)
            {
                break;
            }
        }

        if (!chk)
        {
            cout << "NO\n";
        }
    }

    return 0;
}