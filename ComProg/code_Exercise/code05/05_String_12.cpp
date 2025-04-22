#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> all;
    string num, ans = "";
    int mx;

    while (getline(cin, num))
    {
        if (num == "END")
        {
            break;
        }

        reverse(num.begin(), num.end());
        all.push_back(num);
        if (num.size() > mx)
        {
            mx = num.size();
        }
    }

    int digit, carry = 0;
    for (int i = 0; i < mx; i++)
    {
        int sum = 0;
        for (int j = 0; j < all.size(); j++)
        {
            if (all[j].size() - 1 < i)
            {
                digit = 0;
            }
            else
            {
                digit = all[j][i] - '0';
            }

            sum += digit;
        }

        sum += carry;
        ans += sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry > 0)
    {
        ans += carry + '0';
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}