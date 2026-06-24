#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)


typedef long double ld;
typedef long long ll;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

inline int rnd(int x) {
  return myrand() % x;
}

using namespace std;

map<char, int> to;

void precalc() {
	to.clear();
	to['A'] = 0;
	to['T'] = 1;
	to['G'] = 2;
	to['C'] = 3;
}

const int maxn = 1e5 + 10;
const int maxl = 11;

struct tree {
	int a[maxn];
	int n;

	tree() {}

	void init(int _n) {
		n = _n;
		for (int i = 0; i < n; ++i) {
			a[i] = 0;
		}
	}

	void add(int p, int dx) {
		for (int i = p; i < n; i = (i | (i + 1))) {
			a[i] += dx;
		}
	}

	int get(int p) {
		int res = 0;
		for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
			res += a[i];
		}
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

char s[maxn];
int n;
int a[maxn];
int b[maxn];

int q;
int tp[maxn];
int l[maxn];
int r[maxn];
int len[maxn];
int e[maxn][maxl];

bool read() {
	if (scanf("%s", s) < 1) {
		return false;
	}

	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		a[i] = to[s[i]];
	}

	if (scanf("%d", &q) < 1) {
		return false;
	}

	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &tp[i], &l[i]);
		if (tp[i] == 1) {
			char c;
			scanf(" %c", &c);
			r[i] = to[c];
		} else {
			scanf("%d%s", &r[i], s);
			len[i] = strlen(s);
			for (int j = 0; j < len[i]; ++j) {
				e[i][j] = to[s[j]];
			}
		}
	}

	return true;
}

tree t[4][maxl];
int res[maxn];

void solve() {
	for (int cl = 1; cl < maxl; ++cl) {
		for (int d = 0; d < 4; ++d) {
			for (int i = 0; i < cl; ++i) {
				t[d][i].init(n / cl + 1);
				for (int j = 0; cl * j + i < n; ++j) {
					int id = cl * j + i;
					if (a[id] == d) {
						t[d][i].add(j, 1);
					}
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			b[i] = a[i];
		}

		/*eprintf("%d\n", t[0][0].n);
					for (int q = 0; q < 4; ++q) {
						eprintf("%d ", t[0][0].a[q]);
					}
		eprintf("\n");*/


		for (int i = 0; i < q; ++i) {
			if (tp[i] == 1) {
				int x = l[i] - 1, nval = r[i];
				int sh = x % cl, j = x / cl;
				for (int d = 0; d < 4; ++d) {
					if (b[x] == d) {
						t[d][sh].add(j, -1);
					}
					if (nval == d) {
						t[d][sh].add(j, 1);
					}
				}
				b[x] = nval;
				
			} else {
				if (len[i] != cl) {
					continue;
				}

				int L = l[i] - 1, R = r[i] - 1;
				int shL = L % cl, shR = R % cl;
				int jL = L / cl, jR = R / cl;

				res[i] = 0;
				for (int sh = 0; sh < cl; ++sh) {
					int curl = (sh >= shL ? jL : jL + 1);
					int curr = (sh <= shR ? jR : jR - 1);

					if (curl > curr) {
						continue;
					}

					int cursh = (sh - shL + cl) % cl;

					//eprintf("symb=%d l=%d r=%d res=%d\n", e[i][cursh], curl, curr, t[e[i][cursh]][sh].get(curl, curr));

					res[i] += t[e[i][cursh]][sh].get(curl, curr);
				}
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		if (tp[i] == 2) {
			printf("%d\n", res[i]);
		}
	}
}

int main() {
	precalc();
	srand(rdtsc());
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*while (true) {
		if (!read()) {
			break;
		}

		solve();
#ifdef DEBUG
	    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	}*/

	read();
	solve();

	return 0;
}