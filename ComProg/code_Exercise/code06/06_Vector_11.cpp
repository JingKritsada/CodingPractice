#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, i = 0, tmp;
    vector<int> vec;

    cin >> num;
    while (cin >> tmp)
    {
        if (tmp == -1)
        {
            break;
        }

        if (i % 2 == 0)
        {
            vec.push_back(tmp);
        }
        else
        {
            vec.insert(vec.begin(), tmp);
        }
        i++;
    }

    cout << "[";
    for (i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[i] << ", ";
    }
    cout << vec[i] << "]";

    return 0;
}