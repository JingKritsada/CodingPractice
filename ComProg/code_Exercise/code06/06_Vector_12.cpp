#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> vec;
    vec.push_back(num);
    while (num != 1)
    {
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num = 3 * num + 1;
        }

        vec.push_back(num);
        if (vec.size() > 15)
        {
            vec.erase(vec.begin());
        }
    }

    for (int i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[i] << "->";
    }
    cout << 1;

    return 0;
}