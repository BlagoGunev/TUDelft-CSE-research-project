#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<pair<char, int>> b;
pair<int, int> mp[40];
int a[10][10];

void read() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			char c; cin >> c; a[i][j] = c;
			if ('A' > a[i][j]) a[i][j] -= '0';
			else a[i][j] -= 'A' - 10;
			mp[a[i][j]] = {i, j};
		}
}

void R(int x, int y1, int y2) {
	if (y1 > y2) swap(y1, y2);
	for (int i = 1; i <= 4; i++) {
		b.pb({'R', x});
		b.pb({'D', y2});
		b.pb({'L', x});
		if (i < 4) b.pb({'D', y2});
	}
}
void C(int x1, int x2, int y) {
	if (x1 > x2) swap(x1, x2);
	for (int i = 1; i <= 4; i++) {
		b.pb({'D', y});
		b.pb({'R', x2});
		b.pb({'U', y});
		if (i < 4) b.pb({'R', x2});
	}
}

void solve() {
	for (int i = 0; i < 36; i++) {
		int sx = mp[i].first, sy = mp[i].second;
		int ex = i / 6, ey = i % 6;
		while (sy < ey) {
			R(sx, sy, sy + 1);
			mp[a[sx][sy + 1]] = {sx, sy};
			a[sx][sy] = a[sx][sy + 1];
			a[sx][++sy] = i;
		}
		while (sy > ey) {
			R(sx, sy, sy - 1);
			mp[a[sx][sy - 1]] = {sx, sy};
			a[sx][sy] = a[sx][sy - 1];
			a[sx][--sy] = i;
		}
		while (sx < ex) {
			C(sx, sx + 1, sy);
			mp[a[sx + 1][sy]] = {sx, sy};
			a[sx][sy] = a[sx + 1][sy];
			a[++sx][sy] = i;
		}
		while (sx > ex) {
			C(sx, sx - 1, sy);
			mp[a[sx - 1][sy]] = {sx, sy};
			a[sx][sy] = a[sx - 1][sy];
			a[--sx][sy] = i;
		}
	}
}

void write() {
	cout << b.size() << '\n';
	for (auto [d, n]: b)
		cout << d << ++n << '\n';
}

int main() {
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read(), solve(), write();
}