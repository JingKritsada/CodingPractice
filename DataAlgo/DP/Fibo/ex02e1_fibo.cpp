#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int ans = 1, pre1 = 0, pre2 = 0;
  for (int i = 1; i < n; i++)
  {
    pre2 = pre1;
    pre1 = ans;

    ans = pre1 + pre2;
  }

  cout << ans;

  return 0;
}