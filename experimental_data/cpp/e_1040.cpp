#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair < int, int >

using namespace std;

const int N = 5e5 + 11;
const ll mod = 1e9 + 7;
int n, m, k;
ll a[N], ans;
int par[N], sz[N];
pair < ll, pii > b[N];
vector < pii > v;
vector < int > cur;
bool u[N];

int find_set(int v){
	if (v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if (a != b){
		if (sz[a] < sz[b])
			swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
}

ll binpow(int n){
	ll a = 2, res = 1;
	while (n){
		if (n % 2 == 0){
			n /= 2;
			a = (a * a) % mod;
		}
		else{
			n--;
			res = (res * a) % mod;
		}
	}
	return res;
}

int main(){
	#ifdef LOCAL
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &b[i].s.f, &b[i].s.s);
		b[i].f = a[b[i].s.f] ^ a[b[i].s.s];
	}
	sort(b + 1, b + m + 1);
	int l = 0;
	int uniq = 0, comp;
	for (int i = 1; i <= m; i++){
		if (b[i].f == b[i + 1].f)
			continue;
		comp = 0;
		for (int j = l + 1; j <= i; j++)
			v.pb(b[j].s);
		for (auto i : v){
			par[i.f] = i.f;
			par[i.s] = i.s;
			sz[i.f] = sz[i.s] = 1;
		}
		for (auto i : v){
			if (!u[i.f])
				cur.pb(i.f);
			if (!u[i.s])
				cur.pb(i.s);
			u[i.f] = u[i.s] = true;
		}
		for (auto i : v)
			union_sets(i.f, i.s);
		for (auto i : cur)
			if (find_set(i) == i)
				comp++;
		ans = (ans + binpow(n - (int)cur.size() + comp)) % mod;
		for (auto i : cur){
			u[i] = false;
		}
		cur.clear();
		v.clear();
		l = i;
		uniq++;
	}
	ll p = ((1ll << k) - uniq) % mod;
	p = (p * binpow(n)) % mod;
	ans = (ans + p) % mod;
	cout << ans;
	return 0;
}