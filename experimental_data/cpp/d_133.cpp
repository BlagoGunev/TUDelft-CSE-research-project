#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long LL;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int m, n, a[55][55];
int pos[55][55][4][2];
vector<int> state;

int up(int x, int y)
{
	while (x > 0 && a[x-1][y] == a[x][y])
		--x;
	return x;
}

int left(int x, int y)
{
	while (y > 0 && a[x][y-1] == a[x][y])
		--y;
	return y;
}

int main()
{
	cin>>m>>n;
	int cols;
	for (int i = 0; i < m ; ++i)
	{
		string s;
		cin>>s;
		cols = s.length();
		for (size_t j = 0; j < s.length(); ++j)
			a[i][j] = s[j] - '0';
	}

	int p;

	state.push_back(a[0][0]);
	int x = 0, y = 0, dp = 0, cp = 0;
	pos[x][y][dp][cp] = 1;
	while (1)
	{
		int x1 = x, y1 = y;
		while (x1+dx[dp] >= 0 && x1+dx[dp] < m && y1+dy[dp] >= 0 && y1 + dy[dp] < cols && a[x1][y1] == a[x1+dx[dp]][y1+dy[dp]])
			x1 += dx[dp], y1 += dy[dp];
		int k = (dp + 3) & 3;
		if (cp == 1)
			k = (k + 2) & 3;
		while (x1+dx[k] >= 0 && x1+dx[k] < m && y1+dy[k] >= 0 && y1 + dy[k] < cols && a[x1][y1] == a[x1+dx[k]][y1+dy[k]])
			x1 += dx[k], y1 += dy[k];

		x1 += dx[dp]; y1 += dy[dp];

		if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < cols && a[x1][y1] > 0)
		{
			x = up(x1, y1);
			y = left(x1, y1);
		}
		else
		if (cp == 0)
		   cp = 1;
		else
		{
			cp = 0;
			dp = (dp + 1) & 3;
		}

		if (pos[x][y][dp][cp] == 0)
		{
			state.push_back(a[x][y]);
			pos[x][y][dp][cp] = state.size();
		}
		else
		{
			p = pos[x][y][dp][cp];
			break;
		}
	}


	if (p - 1 >= n)
		cout<<state[n-1]<<"\n";
	else
		cout<<state[(n-p+1)%(state.size() - p + 1) + p - 1]<<"\n";

	return 0;
}