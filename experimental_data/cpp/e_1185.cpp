#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 987654321
#define ll long long

int T;
string s[2000];
int sy[26], sx[26], ey[26], ex[26];
vector<pair<int, int> > v[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 26; i++)
		{
			sy[i] = sx[i] = ey[i] = ex[i] = -1;
			v[i].clear();
		}

		int Y, X, fail = 0;
		cin >> Y >> X;
		for (int i = 0; i < Y; i++)
		{
			s[i].clear();
			cin >> s[i];
			for (int j = 0; j < X; j++)
				if (s[i][j] != '.')
					v[s[i][j] - 'a'].push_back({ i, j });
		}
		
		int K = 0, ty, tx;
		for (int i = 0; i < 26; i++)
			if (v[i].size())
			{
				K = i + 1;
				ty = v[i][0].first;
				tx = v[i][0].second;
			}
		if (K == 0)
		{
			cout << "YES\n0\n";
			continue;
		}
		for (int i = 0; i < K; i++)
		{
			if (v[i].size() == 0)
			{
				sy[i] = ty; sx[i] = tx;
				ey[i] = ty; ex[i] = tx;
			}
			else if (v[i].size() == 1)
			{
				sy[i] = v[i][0].first;
				sx[i] = v[i][0].second;
				ey[i] = v[i][0].first;
				ex[i] = v[i][0].second;
			}
			else if (v[i].size() >= 2)
			{
				int ay = v[i][0].first, ax = v[i][0].second;
				int xdiff = 0, ydiff = 0, xm = ax, xM = ax, ym = ay, yM = ay;
				for (int j = 1; j < v[i].size(); j++)
				{
					int y = v[i][j].first, x = v[i][j].second;
					if (y != ay) ydiff = 1;
					if (x != ax) xdiff = 1;

					xm = min(xm, x);
					xM = max(xM, x);
					ym = min(ym, y);
					yM = max(yM, y);
				}
				if (xdiff && ydiff)
				{
					fail = 1;
					break;
				}
				else if (xdiff)
				{
					for (int j = xm; j <= xM; j++)
					{
						if (s[ay][j] == '.' || s[ay][j] < ('a' + i))
						{
							fail = 1;
							break;
						}
					}
					sy[i] = ay; sx[i] = xm;
					ey[i] = ay; ex[i] = xM;
				}
				else if (ydiff)
				{
					for (int j = ym; j <= yM; j++)
					{
						if (s[j][ax] == '.' || s[j][ax] < ('a' + i))
						{
							fail = 1;
							break;
						}
					}
					sy[i] = ym; sx[i] = ax;
					ey[i] = yM; ex[i] = ax;
				}

				if (fail)
					break;
			}
		}
		if (fail)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n" << K << "\n";
		for (int i = 0; i < K; i++)
			cout << sy[i] + 1 << " " << sx[i] + 1 << " " << ey[i] + 1 << " " << ex[i] + 1 << "\n";
	}
	return 0;
}