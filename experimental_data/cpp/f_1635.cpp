#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 1 << 20;

int n, q;

ll x[N], w[N];
int ql[N], qr[N];
ll ns[N];

ll mn[N];
void add(int x, int L, int R, int p, ll w) {
	if(L == R) return mn[x] = min(mn[x], w), void();
	int mid = (L + R) >> 1;
	p <= mid ? add(x << 1, L, mid, p, w) : add(x << 1 | 1, mid + 1, R, p, w);
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
}

ll query(int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) return mn[x];
	int mid = (L + R) >> 1;
	ll ret = 5e18;
	if(l <= mid) ret = min(ret, query(x << 1, L, mid, l, r));
	if(r > mid) ret = min(ret, query(x << 1 | 1, mid + 1, R, l, r));
	return ret;
}

ll MN[N];
void ADD(int x, int L, int R, int p, ll w) {
	MN[x] = min(MN[x], w);
	if(L == R) return ;
	int mid = (L + R) >> 1;
	p <= mid ? ADD(x << 1, L, mid, p, w) : ADD(x << 1 | 1, mid + 1, R, p, w);
}

inline int findp(int x, int L, int R, ll w) { // lst <= w
//	cout << "MN = " << MN[L] << '\n';
	if(L == R) return L;
	int mid = (L + R) >> 1;
	if(MN[x << 1 | 1] <= w) return findp(x << 1 | 1, mid + 1, R, w);
	else return findp(x << 1, L, mid, w);
}

vi vc[N];

set < pair < int, int > > pr;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	
	L(i, 1, n) cin >> x[i] >> w[i];
	L(i, 1, q) cin >> ql[i] >> qr[i], vc[qr[i]].emplace_back(i);
	
	me(mn, 0x3f);
	me(MN, 0x3f);
	
	ADD(1, 1, n, 1, w[1]);
	L(i, 2, n) {
		int v = i - 1;
		while(true) {
			add(1, 1, n, v, (ll) (x[i] - x[v]) * (w[i] + w[v]));
			int S = w[v] - w[i] - 1;
			if(MN[1] <= S) v = findp(1, 1, n, S); 
			else break ;
		}
		
		ADD(1, 1, n, i, w[i]);
		
		for(const int &u : vc[i])
			ns[u] = query(1, 1, n, ql[u], qr[u]); //, cout << "ns = " << ns[u] << '\n'; 
	}
	
	L(i, 1, q) cout << ns[i] << '\n';
	return 0;
}