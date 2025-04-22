#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long numSeat, numCustomer;
    cin >> numSeat >> numCustomer;

    vector<long long> processTime;
    for (int i = 0; i < numSeat; i++)
    {
        long long time;
        cin >> time;
        processTime.push_back(time);
    }

    sort(processTime.begin(), processTime.end());

    for (int i = 0; i < numCustomer; i++)
    {
        long long target;
        cin >> target;

        long long left = 0, right = 1e12, ans = 0;

        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long totalTask = numSeat;

            for (auto &time : processTime)
            {
                totalTask += (mid / time);
                // cout << left << ", " << mid << ", " << right << ", " << totalTask << "\n";
            }

            if (totalTask >= target)
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
