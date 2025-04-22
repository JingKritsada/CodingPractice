#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int tmp, cnt = 0;
bool chk[100000] = {false};

int main()
{
    while (cin >> tmp)
    {
        if (chk[tmp] == false)
        {
            vec.push_back(tmp);
            chk[tmp] = true;
            cnt++;
        }
    }

    sort(vec.begin(), vec.end());

    cout << cnt << "\n";
    for (int i = 0; i < vec.size() && i < 10; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}