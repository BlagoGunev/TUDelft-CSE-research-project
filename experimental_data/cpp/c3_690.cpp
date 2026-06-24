#include <cstdio>

using namespace std;

int p[200001][20], pow[20], depth[200001];

inline void lca(int up, int neuf, int *_lca, int *_len, int *_ltt) {
	int i, s = 0;
	if (depth[up] < depth[neuf]) {
		for (i = 19; i >= 0; --i)
			if (depth[p[neuf][i]] > depth[up]) {
				neuf = p[neuf][i];
				s += pow[i];
			}
		*_ltt = neuf;
		neuf = p[neuf][0];
		++s;
	} else if (depth[up] > depth[neuf]) {
		*_ltt = 0;
		for (i = 19; i >= 0; --i)
			if (depth[p[up][i]] > depth[neuf]) {
				up = p[up][i];
				s += pow[i];
			}
		up = p[up][i];
		++s;
	}
	if (up == neuf) {
		*_lca = up;
		*_len = s;
		return;
	}
	for (i = 19; i >= 0; --i)
		if (p[up][i] != p[neuf][i]) {
			up = p[up][i];
			neuf = p[neuf][i];
			s += (pow[i] << 1);
		}
	*_lca = p[up][0];
	*_len = s + 2;
}

int main() {
	int up, down, n, i, j, x, y, l, __lca, __len, __ltt, _lca, _len, _ltt;
	
	pow[0] = 1;
	for (j = 1; j < 20; ++j) pow[j] = pow[j - 1] << 1;
	
	scanf("%d", &n);
	up = down = 1;
	l = 0;
	for (j = 0; j < 20; ++j) p[1][j] = 1;
	depth[1] = 0;
	for (i = 2; i <= n; ++i) {
		scanf("%d", &x);
		p[i][0] = x;
		for (j = 1; j < 20; ++j) p[i][j] = p[p[i][j - 1]][j - 1];
		depth[i] = depth[x] + 1;
		if (up == down) {
			lca(up, i, &__lca, &__len, &__ltt);
			if (__len * 2 > l) {
				++l;
				if (__lca == up)
					down = __ltt;
				else
					up = p[up][0];
			}
		} else {
			lca(up, i, &__lca, &__len, &__ltt);
			lca(down, i, &_lca, &_len, &_ltt);
			if (__lca == _lca) {
				if (__len * 2 + 1 > l) {
					++l;
					down = up;
				}
			} else {
				if (__len * 2 - 1 > l) {
					++l;
					up = down;
				}
			}
		}
		printf("%d\n", l);
	}
	
	return 0;
}