#include <bits/stdc++.h>
using namespace std;

struct lookpud
{
    int color, len;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num, insertPos, insertColor;
    cin >> num >> insertPos >> insertColor;

    int color, prevColor, start = 0, len = 1;
    vector<lookpud> vec;
    bool target;

    cin >> prevColor; // first color

    for (int i = 1; i < num + 1; i++)
    {
        // Select (insert or input) ----------------------
        if (i == insertPos)
        {
            color = insertColor;
        }
        else
        {
            cin >> color;
        }

        // count len -------------------------------------
        if (color == prevColor)
        {
            len++;
        }
        else
        {
            vec.push_back({prevColor, len});

            if (i <= insertPos)
            {
                start++;
            }

            prevColor = color;
            len = 1;
        }
    }

    vec.push_back({color, len});

    int left = start, right = start;
    if (vec[start].len >= 3)
    {
        left--;
        right++;

        while ((left >= 0 && right <= vec.size()) && (vec[left].color == vec[right].color) && (vec[left].len + vec[right].len >= 3))
        {
            left--;
            right++;
        }
    }

    // cout << left << " " << right << "\n";
    for (int i = 0; i < vec.size(); i++)
    {
        // cout << vec[i].color << " " << vec[i].len << "\n";
        if (i <= left || i >= right)
        {
            for (int j = 0; j < vec[i].len; j++)
            {
                cout << vec[i].color << ' ';
            }
        }
    }

    return 0;
}