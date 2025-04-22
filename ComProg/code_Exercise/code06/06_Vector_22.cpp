#include <bits/stdc++.h>
using namespace std;

struct ranges
{
	int num, sta, end;
};

bool cmp(ranges &a, ranges &b)
{
	return a.num < b.num;
}

int main()
{
	int num;
	vector<int> vec;
	while (cin >> num)
	{
		vec.push_back(num);
	}

	int sta = 0, mx = 1, len = vec.size();
	vec.push_back(-1);
	for (int i = 1; i <= len; i++)
	{
		if (vec[i] != vec[i - 1])
		{
			if (i - sta >= mx)
			{
				mx = i - sta;
			}
			sta = i;
		}
	}

	vector<ranges> ans;
	sta = 0;
	for (int i = 1; i <= len; i++)
	{
		if (vec[i] != vec[i - 1])
		{
			if (i - sta == mx)
			{
				ranges tmp = {vec[i - 1], sta, i};
				ans.push_back(tmp);
			}
			sta = i;
		}
	}

	sort(ans.begin(), ans.end(), cmp);
	for (auto x : ans)
	{
		cout << x.num << " --> x[ "
			 << x.sta << " : "
			 << x.end << " ]\n";
	}

	return 0;
}
