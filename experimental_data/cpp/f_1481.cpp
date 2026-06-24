#include <cstdio>

#include <cstring>

#include <vector>

#include <algorithm>

using std::vector;

using std::sort;



int gmax (int x, int y) {

	return x > y ? x : y;

}



const int N = 1e5 + 5;



int n, x;

int dep[N], leaf[N];

vector<int> a[N], b[N], to[N];

	//a: not leaf

int c[N], maxd = 0;

int f[N];

int ct[N];

vector<int> getd[N];

int color[N];



void dp () {

	sort (c + 1, c + 1 + maxd);

	memset (f, 0, sizeof (f));

	memset (ct, 0, sizeof (ct));

	f[0] = 1;

	for (int i = 1, j; i <= maxd; i = j + 1) {

		int x = c[i];

		for (j = i; j < maxd && c[j + 1] == x; ++j);

		int d = (j - i + 1) * x;

		for (int R = 0; R < x; ++R) {

			int last = -10000000;

			for (int i = R; i <= n; i += x) {

				if (f[i]) {

					last = i;

				} else if (i - last <= d) {

					f[i] = 1;

					ct[i] = x;

				}

			}

		}

	}

	return;

}



void dfs (int k, int fr) {

	dep[k] = dep[fr] + 1;

	for (int u : to[k]) {

		if (u != fr) {

			dfs (u, k);

		}

	}

	return;

}



int main () {

	memset (leaf, 0, sizeof (leaf));

	scanf ("%d %d", &n, &x);

	for (int i = 2; i <= n; ++i) {

		int fa;

		scanf ("%d", &fa);

		leaf[fa] = 1;

		to[fa].push_back(i);

	}

	dfs (1, 0);

	for (int i = 1; i <= n; ++i) {

		if (leaf[i]) {

			a[dep[i]].push_back(i);

		} else {

			b[dep[i]].push_back(i);

		}

		maxd = gmax (maxd, dep[i]);

	}

	for (int i = 1; i <= maxd; ++i) {

		c[i] = a[i].size() + b[i].size();

		getd[c[i]].push_back(i);

	}

	dp ();

	memset (color, 0, sizeof (color));

	if (f[x]) {

		int back = x;

		while (back) {

			int sub = ct[back];

			color[getd[sub][getd[sub].size() - 1]] = 1;

			getd[sub].pop_back();

			back -= sub;

		}

		printf ("%d\n", maxd);

		for (int i = 1; i <= n; ++i) {

			if (color[dep[i]]) {

				printf ("a");

			} else {

				printf ("b");

			}

		}

		return 0;

	}

	for (int i = 1; i <= maxd; ++i) {

		if (!x) break;

		if (x >= a[i].size() + b[i].size()) {

			x -= a[i].size() + b[i].size();

			for (int u : a[i]) color[u] = 1;

			for (int u : b[i]) color[u] = 1;

			continue;

		}

		if (x >= a[i].size()) {

			x -= a[i].size();

			for (int u : a[i]) color[u] = 1;

			for (int u : b[i]) {

				if (!x) break;

				color[u] = 1;

				--x;

			}

			break;

		}

	}

	printf ("%d\n", maxd + 1);

	for (int i = 1; i <= n; ++i)

		printf ("%c", color[i] ? 'a' : 'b');

	return 0;

}

/*

19 6

1

1

1

1

1

1

1

2

3

4

5

6

7

8

12

13

14

15





*/