#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, mx = 0;
    cin >> num;

    int x1[num + 5], x2[num + 5], y1[num + 5], y2[num + 5];
    for (int i = 0; i < num; i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    vector<pair<int, int>> vec;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            int w = min(x2[i], x2[j]) - max(x1[i], x1[j]);
            int h = min(y2[i], y2[j]) - max(y1[i], y1[j]);

            if (w <= 0 || h <= 0)
            {
                continue;
            }

            int area = w * h;
            if (area > mx)
            {
                vec.clear();
                mx = area;
            }

            if (area == mx)
            {
                vec.push_back({i, j});
            }
        }
    }

    if (mx == 0)
    {
        cout << "No overlaps";
    }
    else
    {
        cout << "Max overlapping area = " << mx;

        for (int i = 0; i < vec.size(); i++)
        {
            cout << "\nrectangles " << vec[i].first << " and " << vec[i].second;
        }
    }

    return 0;
}