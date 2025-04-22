#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string cmd;

	cin >> N >> cmd;

	float sumxi = 0, sumyi = 0, sumxy = 0, sumx2 = 0;
	for (int i = 0; i < N; i++)
	{
		float xi, yi;
		cin >> xi >> yi;

		sumxi += xi;
		sumyi += yi;
		sumxy += xi * yi;
		sumx2 += xi * xi;
	}

	float m = ((N * sumxy) - (sumxi * sumyi)) / ((N * sumx2) - (sumxi * sumxi));
	float b = (sumyi - (m * sumxi)) / N;

	if (cmd == "mb")
	{
		cout << round(m * 1e3) / 1e3 << "\n";
		cout << round(b * 1e3) / 1e3;
	}
	else
	{
		m = round(m * 1e3) / 1e3;
		b = round(b * 1e3) / 1e3;

		if (m < -1)
		{
			if (b < 0)
			{
				cout << "y = -" << m * -1 << "x - " << b * -1;
			}
			else if (b == 0)
			{
				cout << "y = -" << m * -1 << "x";
			}
			else if (b > 0)
			{
				cout << "y = -" << m * -1 << "x + " << b;
			}
		}

		else if (m == -1)
		{
			if (b < 0)
			{
				cout << "y = -x - " << b * -1;
			}
			else if (b == 0)
			{
				cout << "y = -x";
			}
			else if (b > 0)
			{
				cout << "y = -x + " << b;
			}
		}

		else if (m == 0)
		{
			if (b < 0)
			{
				cout << "y = -" << b * -1;
			}
			else if (b == 0)
			{
				cout << "y = 0";
			}
			else if (b > 0)
			{
				cout << "y = " << b;
			}
		}

		else if (m == 1)
		{
			if (b < 0)
			{
				cout << "y = x - " << b * -1;
			}
			else if (b == 0)
			{
				cout << "y = x";
			}
			else if (b > 0)
			{
				cout << "y = x + " << b;
			}
		}

		else if (m > 1)
		{
			if (b < 0)
			{
				cout << "y = " << m << "x - " << b * -1;
			}
			else if (b == 0)
			{
				cout << "y = " << m << "x";
			}
			else if (b > 0)
			{
				cout << "y = " << m << "x + " << b;
			}
		}
	}

	return 0;
}
