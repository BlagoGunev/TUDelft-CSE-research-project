#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long
#define all(v) v.begin(), v.end()
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


const int maxn = 2e5+10, mod = 998244353;
ll inf = 2e18;
#define int ll

ll A[600100];

struct Node {
	ll sum;   // Sum tag
	ll max1;  // Max value
	ll max2;  // Second Max value
	ll maxc;  // Max value count
	ll min1;  // Min value
	ll min2;  // Second Min value
	ll minc;  // Min value count
	ll lazy;  // Lazy tag
} T[6*100010 * 4];

void merge(int t) {
	// sum
	T[t].sum = T[t << 1].sum + T[t << 1 | 1].sum;

	// max
	if (T[t << 1].max1 == T[t << 1 | 1].max1) {
		T[t].max1 = T[t << 1].max1;
		T[t].max2 = max(T[t << 1].max2, T[t << 1 | 1].max2);
		T[t].maxc = T[t << 1].maxc + T[t << 1 | 1].maxc;
	} else {
		if (T[t << 1].max1 > T[t << 1 | 1].max1) {
			T[t].max1 = T[t << 1].max1;
			T[t].max2 = max(T[t << 1].max2, T[t << 1 | 1].max1);
			T[t].maxc = T[t << 1].maxc;
		} else {
			T[t].max1 = T[t << 1 | 1].max1;
			T[t].max2 = max(T[t << 1].max1, T[t << 1 | 1].max2);
			T[t].maxc = T[t << 1 | 1].maxc;
		}
	}

	// min
	if (T[t << 1].min1 == T[t << 1 | 1].min1) {
		T[t].min1 = T[t << 1].min1;
		T[t].min2 = min(T[t << 1].min2, T[t << 1 | 1].min2);
		T[t].minc = T[t << 1].minc + T[t << 1 | 1].minc;
	} else {
		if (T[t << 1].min1 < T[t << 1 | 1].min1) {
			T[t].min1 = T[t << 1].min1;
			T[t].min2 = min(T[t << 1].min2, T[t << 1 | 1].min1);
			T[t].minc = T[t << 1].minc;
		} else {
			T[t].min1 = T[t << 1 | 1].min1;
			T[t].min2 = min(T[t << 1].min1, T[t << 1 | 1].min2);
			T[t].minc = T[t << 1 | 1].minc;
		}
	}
}

ll llINF = 1e18;

void push_add(int t, int tl, int tr, ll v) {
	if (v == 0) { return; }
	T[t].sum += (tr - tl + 1) * v;
	T[t].max1 += v;
	if (T[t].max2 != -llINF) { T[t].max2 += v; }
	T[t].min1 += v;
	if (T[t].min2 != llINF) { T[t].min2 += v; }
	T[t].lazy += v;
}

// corresponds to a chmin update
void push_max(int t, ll v, bool l) {
	if (v >= T[t].max1) { return; }
	T[t].sum -= T[t].max1 * T[t].maxc;
	T[t].max1 = v;
	T[t].sum += T[t].max1 * T[t].maxc;
	if (l) {
		T[t].min1 = T[t].max1;
	} else {
		if (v <= T[t].min1) {
			T[t].min1 = v;
		} else if (v < T[t].min2) {
			T[t].min2 = v;
		}
	}
}

// corresponds to a chmax update
void push_min(int t, ll v, bool l) {
	if (v <= T[t].min1) { return; }
	T[t].sum -= T[t].min1 * T[t].minc;
	T[t].min1 = v;
	T[t].sum += T[t].min1 * T[t].minc;
	if (l) {
		T[t].max1 = T[t].min1;
	} else {
		if (v >= T[t].max1) {
			T[t].max1 = v;
		} else if (v > T[t].max2) {
			T[t].max2 = v;
		}
	}
}

void pushdown(int t, int tl, int tr) {
	if (tl == tr) return;
	// sum
	int tm = (tl + tr) >> 1;
	push_add(t << 1, tl, tm, T[t].lazy);
	push_add(t << 1 | 1, tm + 1, tr, T[t].lazy);
	T[t].lazy = 0;

	// max
	push_max(t << 1, T[t].max1, tl == tm);
	push_max(t << 1 | 1, T[t].max1, tm + 1 == tr);

	// min
	push_min(t << 1, T[t].min1, tl == tm);
	push_min(t << 1 | 1, T[t].min1, tm + 1 == tr);
}

int N;

void build(int t = 1, int tl = 0, int tr = N - 1) {
	T[t].lazy = 0;
	if (tl == tr) {
		T[t].sum = T[t].max1 = T[t].min1 = A[tl];
		T[t].maxc = T[t].minc = 1;
		T[t].max2 = -llINF;
		T[t].min2 = llINF;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(t << 1, tl, tm);
	build(t << 1 | 1, tm + 1, tr);
	merge(t);
}

void update_add(int l, int r, ll v, int t = 1, int tl = 0, int tr = N - 1) {
	if (r < tl || tr < l) { return; }
	if (l <= tl && tr <= r) {
		push_add(t, tl, tr, v);
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	update_add(l, r, v, t << 1, tl, tm);
	update_add(l, r, v, t << 1 | 1, tm + 1, tr);
	merge(t);
}

void update_chmin(int l, int r, ll v, int t = 1, int tl = 0, int tr = N - 1) {
	if (r < tl || tr < l || v >= T[t].max1) { return; }
	if (l <= tl && tr <= r && v > T[t].max2) {
		push_max(t, v, tl == tr);
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	update_chmin(l, r, v, t << 1, tl, tm);
	update_chmin(l, r, v, t << 1 | 1, tm + 1, tr);
	merge(t);
}

void update_chmax(int l, int r, ll v, int t = 1, int tl = 0, int tr = N - 1) {
	if (r < tl || tr < l || v <= T[t].min1) { return; }
	if (l <= tl && tr <= r && v < T[t].min2) {
		push_min(t, v, tl == tr);
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	update_chmax(l, r, v, t << 1, tl, tm);
	update_chmax(l, r, v, t << 1 | 1, tm + 1, tr);
	merge(t);
}

ll query_sum(int l, int r, int t = 1, int tl = 0, int tr = N - 1) {
	if (r < tl || tr < l) { return 0; }
	if (l <= tl && tr <= r) { return T[t].sum; }
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	return query_sum(l, r, t << 1, tl, tm) + query_sum(l, r, t << 1 | 1, tm + 1, tr);
}

void upd_pl(int v, int tl, int tr, int l, int r, int val)
{
	update_add(l-1, r-1, val);
}

void upd_mx(int v, int tl, int tr, int l, int r, int val)
{
	update_chmax(l-1, r-1, val);
}



main()
{
	IOS
	int test;
	cin >> test;
	for(int tes = 1; tes <= test; ++tes)
	{
		int n, m, k;
		cin >> n >> m >> k;
		N = k;
		vector <vector <int> > a(n+2), c(n+2), rel(n+2);
		vector <int> add(n+2, 0), dp(k+2, 0);
		for(int i = 0; i <= n + 1; ++i)
			a[i].assign(m+2, 0);
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(a[i][j] != -1)
					rel[i].pb(a[i][j]);
			}
			sort(all(rel[i]));
			rel[i].erase(unique(all(rel[i])), rel[i].end());
			c[i].assign((int)rel[i].size(), 0);
			for(int j = 1; j <= m; ++j)
			{
				if(a[i][j] == -1) 
				{
					add[i]++;
					continue;
				}
				c[i][lower_bound(all(rel[i]), a[i][j]) - rel[i].begin()]++;
			}
		}
		for(int i = 1; i <= k; ++i)
		{
			dp[i] = 0;
			A[i-1] = 0;
		}
		build();
		int ans = 0;
		for(int i = 2; i <= n; ++i)
		{
			for(int itj = 0; itj < rel[i].size(); ++itj)
			{
				int j = rel[i][itj];
				dp[j] += c[i][itj] * add[i-1];
				int temp = lower_bound(all(rel[i-1]), j) - rel[i-1].begin();
				if(temp >= 0 && temp < rel[i-1].size() && rel[i-1][temp] == j)
					ans += c[i][itj] * c[i-1][temp];
				upd_pl(1, 1, k, j, j, c[i][itj]*add[i-1]);
			}
			ll mx = T[1].max1;
			for(int itj = 0; itj < rel[i-1].size(); ++itj)
			{
				int j = rel[i-1][itj];
				dp[j] += c[i-1][itj] * add[i];
				upd_pl(1, 1, k, j, j, c[i-1][itj]*add[i]);
			}
			upd_pl(1, 1, k, 1, k, add[i-1]*add[i]);
			for(int itj = 0; itj < rel[i-1].size(); ++itj)
			{
				int j = rel[i-1][itj];
				upd_mx(1, 1, k, j, j, mx + c[i-1][itj] * add[i]);
			}
			upd_mx(1, 1, k, 1, k, mx);
//			for(int j = 1; j <= k; ++j)
//				cout << " DP " << i << " " << j << " " << query_sum(j-1, j-1) << endl;
		}
		cout << T[1].max1 + ans << "\n";
	}
}