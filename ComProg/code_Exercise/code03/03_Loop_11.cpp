#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n, sum = 0, cnt = 0;
    while (n != -1)
    {
        cin >> n;
        sum += n;
        cnt++;
    }

    sum++;
    cnt--;
    if (cnt == 0)
    {
        cout << "No Data";
        return 0;
    }

    double avg = sum / cnt;
    cout << round(avg * 100) / 100;

    return 0;
}