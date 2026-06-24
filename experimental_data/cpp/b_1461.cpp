#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stdio.h>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <climits>
using namespace std;

void task()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> field(n, vector<char>(m));

	vector<vector<int>> r(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> field[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		int row = 0;
		for (int j = 0; j < m; j++)
		{
			if (field[i][j] == '*')
			{
				row++;
			}
			else
			{
				row = 0;
			}

			if (i - 1 >= 0 && j - 1 >= 0)
			{
				/*for (int f = 0; f <= r[i - 1][j - 1]; f++)
				{
					if ((f + 1) * 2 - 1 <= row)
					{
						r[i][j] = f + 1;
					}
				}*/

				r[i][j] = min(r[i - 1][j - 1] + 1, (row + 1) / 2);
			}
			else
			{
				r[i][j] = min(row, 1);
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += r[i][j];
		}
	}

	cout << sum << endl;
}

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		task();
	}
	return 0;
}