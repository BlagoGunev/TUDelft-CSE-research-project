// MYCOP



#include <bits/stdc++.h>



#if SEREZHKA

	#define filename "file"

#else

	#define filename ""

#endif // SEREZHKA



#define forn(i, n) for (llong i = 0ll; i < (llong) n; ++i)

#define fornn(i, l, r) for (llong i = (llong) l; i < (llong) r; ++i)

#define here(str) fprintf(stderr, "here: %s\n", #str)

#define size(x) ((int) (x.size()))



using namespace std;



const int MAX_MEM = (int) 1e8;

int mpos = 0;

char mem[MAX_MEM];



inline void * operator new (size_t n) { char *res = mem + mpos; mpos += n; return (void *) res; }

inline void operator delete (void *) { }



struct __io_dev

{

	__io_dev(const bool& __fastio = false)

	{

		if (__fastio) ios_base::sync_with_stdio(false), cin.tie(nullptr);

		srand(time(nullptr));



		if (!string(filename).empty())

			freopen(filename ".in", "r", stdin), freopen(filename ".out", "w", stdout);

	}



	~__io_dev() { fprintf(stderr, "%.6f ms\n", 1e3 * clock() / CLOCKS_PER_SEC); }

}

__io(false);



typedef long long llong;

const llong inf = (llong) 1e+9 + 7ll;

const llong linf = (llong) 1e+18 + 7ll;

const long double eps = (long double) 1e-9;

const long double pi = acosl((long double) -1.0);

const int alph = 26;

const int maxs = 512l;



static char buff[(int) 2e6 + 17];

llong __p[3] = {29ll, 31ll, 33ll};

llong __mod[3] = {inf, inf + 2ll, 14881337ll};



const int maxn = (int) 1e5 + 17;

const int MAGIC = 750;



int n, q;

int a[maxn];

int cnt[maxn / MAGIC + 2][maxn];

vector<int> D[maxn];



void build()

{

	for (int lq = 0; lq < n; lq += MAGIC)

	{

		int rq = min(lq + MAGIC, n);



		for (int i = lq; i < rq; ++i)

		{

			D[lq / MAGIC].push_back(a[i]);

			++cnt[lq / MAGIC][a[i]];

		}

	}

}



void rebuild()

{

	int i = 0;



	for (int bl = 0; bl < n / MAGIC + 1; ++bl)

	{

		for (int j = 0; j < size(D[bl]); ++j)

			a[i++] = D[bl][j], --cnt[bl][D[bl][j]];



		D[bl].clear();

	}



	build();

}



pair<int, int> find(int i)

{

	pair<int, int> res;



	for (int bl = 0; bl < n / MAGIC + 1; ++bl)

		if (size(D[bl]) <= i)

			i -= size(D[bl]);

		else

			return {bl, i};

}



void add(int bl, int i, int x)

{

	++cnt[bl][x];

	D[bl].insert(D[bl].begin() + i, x);

}



void rem(int bl, int i, int x)

{

	--cnt[bl][x];

	D[bl].erase(D[bl].begin() + i);

}



int get(int i, int k)

{

	if (i == -1)

		return 0;



	int res = 0;



	for (int bl = 0; bl < n / MAGIC + 1; ++bl)

		if (size(D[bl]) <= i)

		{

			res += cnt[bl][k];

			i -= size(D[bl]);

		}

		else

		{

			for (int j = 0; j <= i; ++j)

				res += (D[bl][j] == k);



			break;

		}



	return res;

}



int main()

{

	scanf("%d", &n);



	forn (i, n)

		scanf("%d", a + i), --a[i];



	build();



	int lastans = 0;

	scanf("%d", &q);



	forn (ppp, q)

	{

		if (ppp % (2 * MAGIC) == 0)

			rebuild();



		int type, l, r, k;

		scanf("%d %d %d", &type, &l, &r);



		l = (l + lastans - 1) % n;

		r = (r + lastans - 1) % n;



		if (l > r)

			swap(l, r);



		if (type == 1)

		{

			auto lq = find(l), rq = find(r);

			int x = D[rq.first][rq.second];

			add(lq.first, lq.second, x);

			rem(rq.first, rq.second + (lq.first == rq.first), x);

		}

		else

		{

			scanf("%d", &k);

			k = (k + lastans - 1) % n;

			lastans = get(r, k) - get(l - 1, k);

			printf("%d\n", lastans);

		}

	}



	return 0;

}