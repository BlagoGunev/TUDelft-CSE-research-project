#pragma comment (linker, "/STACK:256000000")

 

#define _USE_MATH_DEFINES

#define _CRT_NO_DEPRECEATE

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <iomanip>

#include <fstream>

#include <cstdio>

#include <cstdlib>

#include <string>

#include <cstring>

#include <vector>

#include <utility>

#include <algorithm>

#include <functional>

#include <set>

#include <map>

#include <cmath>

#include <memory.h>

#include <sstream>

#include <queue>

#include <cassert>

#include <ctime>

#include <complex>

#include <unordered_map>

#include <random>

 

using namespace std;

 

typedef unsigned int uint32;

typedef long long int64;

typedef unsigned long long uint64;

typedef pair<int, int> pii;

typedef pair<int64, int64> pll;

typedef pair<int64, int> pli;

typedef pair<pii, pii> piiii;

typedef pair<int64, int> pli;

typedef pair<int, char> pic; 



#define pb push_back

#define sq(x) ((x)*(x))

#define cube(x) (((x)*(x))*(x))

#define tmin(x,y,z) (min(min((x),(y)),(z)))

#define rand32() (((unsigned int)(rand()) << 16) | (unsigned int)(rand()))

#define rand64() (((unsigned int64)(rand32()) << 16) | (unsigned int64)(rand32()))

#define bit(mask, b) ((mask >> b) & 1)

#define biton(mask, bit) (mask | (((uint64)(1)) << bit))

#define bitoff(mask, bit) (mask & (~(((uint64)(1)) << bit)))

#define bitputon(mask, bit) (mask |= (((uint64)(1)) << bit))

#define bitputoff(mask, bit) (mask &= (~(((uint64)(1)) << bit)))

#define FAIL() (*((int*)(0)))++

#define INF ((int)(1e9) + 1337)

#define EPS (1e-9)

#define y1 yy1

#define y0 yy0

#define j0 jj0



const long double PI = acosl((long double)-1.0);

const int64 LINF = 1e18;//((1ull << 63) - 1ull);

const int MOD = 1000000007;



const int LOG = 31;

const int MAXN = 200005;



int n, m;

pii t[MAXN];

int x[MAXN];

int a[LOG][MAXN];

int64 s[LOG][MAXN];

int c[LOG][MAXN];

int nxt[LOG][MAXN];

int64 val[MAXN];

int64 st[LOG][MAXN];

int last[LOG];

int ind;

int lg[MAXN];

int ps[MAXN];



void init()

{

	scanf ("%d", &n);

	for (int i = 1; i <= n; i++)

	{

		scanf ("%d%d", &t[i].second, &t[i].first);

		t[i].first *= -1;

	}

	scanf ("%d", &m);

	for (int i = 1; i <= m; i++)

	{

		scanf ("%d", &x[i]);

	}

}



inline int64 get_sum(int h, int l, int r)

{

	return s[h][r] - s[h][l - 1];

}



inline int get_count(int h, int l, int r)

{

	return c[h][r] - c[h][l - 1];

}



void build_sparse_table()

{

	for (int i = 1; i <= n; i++)

	{

		st[0][i] = val[i];

	}

	for (int h = 1; (1 << h) <= n; h++)

	{

		for (int i = 1; i + (1 << h) - 1 <= n; i++)

		{

			st[h][i] = min(st[h - 1][i], st[h - 1][i + (1 << h - 1)]);

		}

	}

}



inline int64 get_min(int l, int r)

{

	int lvl = lg[r - l + 1];

	return min(st[lvl][l], st[lvl][r - (1 << lvl) + 1]);

}



void build()

{

	sort (t + 1, t + n + 1);

	for (int i = 1; i <= n; i++)

	{

		for (int h = LOG - 1; h >= 0; h--)

		{

			if (t[i].second > (1 << h))

			{

				break;

			}

			a[h][i] = t[i].second;

		}

	}

	for (int h = 0; h < LOG; h++)

	{

		for (int i = 1; i <= n; i++)

		{

			if (a[h][i] && a[h][i] > (1 << h - 1))

			{

				nxt[h][i] = ++ind;

				ps[ind] = i;

			}

			else

			{

				nxt[h][i] = ind + 1;

			}

		}

		last[h] = ind;

		for (int i = 1; i <= n; i++)

		{

			s[h][i] = s[h][i - 1] + a[h][i];

			c[h][i] = c[h][i - 1];

			if (a[h][i])

			{

				c[h][i]++;

				if (a[h][i] > (1 << h - 1))

				{

					val[nxt[h][i]] = a[h][i] + get_sum(h - 1, 1, i - 1);

				}

			}

		}

	}

	build_sparse_table();

}



void solve()

{

	init();

	build();

	/*for (int h = 6; h >= 0; h--)

	{

		for (int i = 1; i <= n; i++)

		{

			fprintf(stderr, "%d ", c[h][i]);

		}

		fprintf(stderr, "\n");

	}*/

	for (int i = 1; i <= m; i++)

	{

		int level = LOG - 1;

		int y = x[i];

		int cnt = 0;

		int pos = 1;

		while (y && level >= 0 && pos <= n)

		{

			while (y <= (1 << level - 1))

			{

				level--;

			}

			if (get_sum(level, pos, n) <= y)

			{

				cnt += get_count(level, pos, n);

				break;

			}

			

			//fprintf(stderr, "i %d level %d y %d pos %d cnt %d\n", i, level, y, pos, cnt);

			if (level)

			{

				int l = nxt[level][pos], r = last[level], p = -1;

				while (l <= r)

				{

					int mid = (l + r) >> 1;

					if (get_min(nxt[level][pos], mid) - get_sum(level - 1, 1, pos - 1) <= y)

					{

						p = ps[mid];

						r = mid - 1;

					}

					else

					{

						l = mid + 1;

					}

				}

				if (p != -1)

				{

					cnt += get_count(level - 1, pos, p) + 1;

					y -= get_sum(level - 1, pos, p - 1);

					y -= a[level][p];

					pos = p + 1;

					continue;

				}

			}



			int l = pos, r = n, p = -1;

			while (l <= r)

			{

				int mid = (l + r) >> 1;

				if (get_sum(level != 0 ? level - 1 : level, pos, mid) <= y)

				{

					p = mid;

					l = mid + 1;

				}

				else

				{

					r = mid - 1;

				}

			}

			y -= get_sum(level != 0 ? level - 1 : level, pos, p);

			cnt += get_count(level != 0 ? level - 1 : level, pos, p);

			pos = p + 1;

			level--;

		}

		printf("%d ", cnt);

	}

}



void precalc()

{

	int cur = 0;

	for (int i = 1; i < MAXN; i++)

	{

		if ((1 << cur + 1) <= i)

		{

			cur++;

		}

		lg[i] = cur;

	}

}



int main()

{

    //ios_base::sync_with_stdio(false); cin.tie(0);

#ifdef _MY_DEBUG

    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);

#else

    //freopen(TASK ".in", "rt", stdin); freopen(TASK ".out", "wt", stdout);

#endif

    srand(707);

	//test_output(); return 0;

	precalc();

	int tests = 1;

	//scanf ("%d", &tests);

	for (int i = 1; i <= tests; i++)

	{

		solve();

	}

	

    return 0;

}