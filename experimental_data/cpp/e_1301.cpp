#include <bits/stdc++.h>

 

using namespace std;



template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}

template<class A, class B> bool minimize(A& x, B y) {if (x >= y) return x = y, true; else return false;}



void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(long long x) {cerr << x;}

void __print(unsigned x) {cerr << x;}

void __print(unsigned long x) {cerr << x;}

void __print(unsigned long long x) {cerr << x;}

void __print(float x) {cerr << x;}

void __print(double x) {cerr << x;}

void __print(long double x) {cerr << x;}

void __print(char x) {cerr << '\'' << x << '\'';}

void __print(const char *x) {cerr << '\"' << x << '\"';}

void __print(const string &x) {cerr << '\"' << x << '\"';}

void __print(bool x) {cerr << (x ? "true" : "false");}

 

template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

void _print() {cerr << " ]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define     deb(x...)             cerr << "[ in " <<__func__<< "() : line " <<__LINE__<< " ] : [ " << #x << " ] = [ "; _print(x); cerr << '\n';



typedef     long long             ll;

typedef     unsigned long long    ull;

typedef     double                db;

typedef     long double           ld;

typedef     pair<db, db>          pdb;

typedef     pair<ld, ld>          pld;

typedef     pair<int, int>        pii;

typedef     pair<ll, ll>          pll;

typedef     pair<ll, int>         plli;

typedef     pair<int, ll>         pill;



#define     all(a)                a.begin(), a.end()

#define     pb(a)                 push_back(a)

#define     pf(a)                 push_front(a)

#define     fi                    first

#define     se                    second

// #define     int                   long long



const int MAX_N = 500 + 5;



int n, m, q;

string a[MAX_N];

int prefSum[4][MAX_N][MAX_N];

int b[MAX_N][MAX_N];

int rmq[10][MAX_N][10][MAX_N];



int convert(const char& h) {

	if (h == 'R') return 0;

	if (h == 'G') return 1;

	if (h == 'Y') return 2;

	return 3;

}



bool inside(const int& x, const int& y) {

	return x > 0 && x <= n && y > 0 && y <= m;

}



int get(int t, int x, int y, int u, int v) {

	if (x > u) swap(x, u);

	if (y > v) swap(y, v);

	return prefSum[t][u][v] - prefSum[t][u][y - 1] - prefSum[t][x - 1][v] + prefSum[t][x - 1][y - 1];

}



int getMax(int x, int y, int u, int v) {

	int k1 = __lg(u - x + 1);

	int k2 = __lg(v - y + 1);

	int mx1 = max(rmq[k1][x][k2][y], rmq[k1][x][k2][v - (1 << k2) + 1]);

	int mx2 = max(rmq[k1][u - (1 << k1) + 1][k2][y], rmq[k1][u - (1 << k1) + 1][k2][v - (1 << k2) + 1]);

	return max(mx1, mx2);

}



signed main() {

	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);



	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		a[i] = ' ' + a[i];

	}



	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			for (int t = 0; t < 4; t++) {

				prefSum[t][i][j] = prefSum[t][i - 1][j] + prefSum[t][i][j - 1] - prefSum[t][i - 1][j - 1];

			}

			prefSum[convert(a[i][j])][i][j]++;

		}

	}



	for (int i = 1; i < n; i++) {

		for (int j = 1; j < m; j++) {

			if (a[i][j] == 'R' && a[i][j + 1] == 'G' && a[i + 1][j] == 'Y' && a[i + 1][j + 1] == 'B') {

				int low = 1, high = min(n, m);

				while (low <= high) {

					int mid = (low + high) >> 1;

					if (inside(i - mid + 1, j - mid + 1) && inside(i - mid + 1, j + mid) && inside(i + mid, j - mid + 1) && inside(i + mid, j + mid) && get(0, i - mid + 1, j - mid + 1, i, j) == mid * mid && get(1, i, j + 1, i - mid + 1, j + mid) == mid * mid && get(2, i + 1, j, i + mid, j - mid + 1) == mid * mid && get(3, i + 1, j + 1, i + mid, j + mid) == mid * mid) {

						b[i][j] = mid;

						low = mid + 1;

					}

					else {

						high = mid - 1;

					}

				}

			}

		}

	}



	for (int ir = 1; ir <= n; ir++) {

		for (int ic = 1; ic <= m; ic++) {

			rmq[0][ir][0][ic] = b[ir][ic];

		}

		for (int jc = 1; jc < 10; jc++) {

			for (int ic = 1; ic <= m; ic++) {

				if (ic + (1 << jc) > m) break;

				rmq[0][ir][jc][ic] = max(rmq[0][ir][jc - 1][ic], rmq[0][ir][jc - 1][ic + (1 << (jc - 1))]);

			}

		}

	}



	for (int jc = 0; jc < 10; jc++) {

		for (int ic = 1; ic <= m; ic++) {

			if (ic + (1 << jc) > m) break;

			for (int jr = 1; jr < 10; jr++) {

				for (int ir = 1; ir <= n; ir++) {

					if (ir + (1 << jr) > n) break;

					rmq[jr][ir][jc][ic] = max(rmq[jr - 1][ir][jc][ic], rmq[jr - 1][ir + (1 << (jr - 1))][jc][ic]);

				}

			}

		}

	}



	while (q--) {

		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int low = 1, high = min(n, m);

		int ans = 0;

		while (low <= high) {

			int mid = (low + high) >> 1;

			int u1 = x1 + mid - 1;

			int v1 = y1 + mid - 1;

			int u2 = x2 - mid;

			int v2 = y2 - mid;

			if (u1 <= u2 && v1 <= v2 && getMax(u1, v1, u2, v2) >= mid) {

				ans = mid;

				low = mid + 1;

			}

			else {

				high = mid - 1;

			}

		}

		cout << 4 * ans * ans << '\n';

	}



	return 0;

}



/*





*/