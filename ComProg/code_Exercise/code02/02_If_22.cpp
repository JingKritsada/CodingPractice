#include <bits/stdc++.h>
using namespace std;

int main()
{
  int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int d, m, y, ans = 0;
  cin >> d >> m >> y;

  y -= 543;
  if (y % 4 == 0)
  {
    if (y % 100 == 0)
    {
      if (y % 400 == 0)
      {
        month[2] = 29;
      }
      else
      {
        month[2] = 28;
      }
    }
    else
    {
      month[2] = 29;
    }
  }

  for (int i = 0; i < m; i++)
  {
    ans += month[i];
  }
  ans += d;

  cout << ans;

  return 0;
}