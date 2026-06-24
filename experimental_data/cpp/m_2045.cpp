#include <bits/stdc++.h>

#define bounds(x, y, n, m) (x >= 1 && y >= 1 && x <= n && y <= m)
#define mp(x, y) make_pair(x, y)

#define ll long long

using namespace std;

char a[201][201];
int mirrors;
int n, m;
map<pair<int, int>, pair<bool, bool>> mir;
bool b = false;
void shoot(int x, int y, int dir)
{
	if (!bounds(x, y, n, m))
		return;

	if (b)
		cout << x << ' ' << y << ' ' << dir << '\n';

	if (a[x][y] == '.')
	{
		switch(dir)
		{
			case 1:
				shoot(x - 1, y, dir);
				break;
			case 2:
				shoot(x, y + 1, dir);
				break;
			case 3:
				shoot(x + 1, y, dir);
				break;
			case 4:
				shoot(x, y - 1, dir);
				break;
			default:
				break;
		}
	}
	else if (a[x][y] == '/')
	{
		switch(dir)
		{
			case 1:
				if (mir[mp(x, y)].second)
					return;
				mir[mp(x, y)].second = true;
				if (!mir[mp(x, y)].first)
					mirrors++;
				shoot(x, y + 1, 2);
				break;
			case 2:
				if (mir[mp(x, y)].first)
					return;
				mir[mp(x, y)].first = true;
				if (!mir[mp(x, y)].second)
					mirrors++;
				shoot(x - 1, y, 1);
				break;
			case 3:
				if (mir[mp(x, y)].first)
					return;
				mir[mp(x, y)].first = true;
				//cout << "asdf\n";
				if (!mir[mp(x, y)].second)
					mirrors++;
				shoot(x, y - 1, 4);
				break;
			case 4:
				if (mir[mp(x, y)].second)
					return;
				mir[mp(x, y)].second = true;
				if (!mir[mp(x, y)].first)
					mirrors++;
				shoot(x + 1, y, 3);
				break;
			default:
				break;
		}
	}
	else
	{
		switch(dir)
		{
			case 1:
				if (mir[mp(x, y)].second)
					return;
				mir[mp(x, y)].second = true;
				if (!mir[mp(x, y)].first)
					mirrors++;
				shoot(x, y - 1, 4);
				break;
			case 2:				
				if (mir[mp(x, y)].second)
					return;
				mir[mp(x, y)].second = true;
				if (!mir[mp(x, y)].first)
					mirrors++;
				shoot(x + 1, y, 3);
				break;
			case 3:
				if (mir[mp(x, y)].first)
					return;
				mir[mp(x, y)].first = true;
				if (!mir[mp(x, y)].second)
					mirrors++;
				shoot(x, y + 1, 2);
				break;
			case 4:
				if (mir[mp(x, y)].first)
					return;
				mir[mp(x, y)].first = true;
				if (!mir[mp(x, y)].second)
					mirrors++;
				shoot(x - 1, y, 1);
				break;
			default:
				break;
		}
	}
}

void solve(){
	
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] != '.')
				cnt++;
		}
	}

	vector<string> v;
	for (int i = 1; i <= n; i++)
	{
		mirrors = 0;
		shoot(1, i, 3);

		if (mirrors == cnt)
			v.push_back("N" + to_string(i));

		mir.clear();
	}
	
	for (int i = 1; i <= n; i++)
	{
		mirrors = 0;
		
		shoot(n, i, 1);

		if (mirrors == cnt)
			v.push_back("S" + to_string(i));

		mir.clear();
	}

	for (int i = 1; i <= m; i++)
	{
		mirrors = 0;
		
		shoot(i, 1, 2);

		if (mirrors == cnt)
			v.push_back("W" + to_string(i));

		mir.clear();
	}

	for (int i = 1; i <= m; i++)
	{
		mirrors = 0;
		shoot(i, m, 4);

		if (mirrors == cnt)
			v.push_back("E" + to_string(i));

		mir.clear();
	}

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

}

 int main() {

 	int t = 1;
 	//cin >> t;

 	while(t--)
 		solve();

 	return 0;
 }