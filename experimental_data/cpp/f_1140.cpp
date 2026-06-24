#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)

int const N = 300000;
int q;
vector<pair<int, int> > s[N << 2];
map<pair<int, int>, int> edtm;
vector<pair<int, int> > p;
ll an[N + 1];

void adsg(pair<int, int> e, int x, int y, int l = 1, int r = q, int id = 1){
	if (l > y || r < x)return;
	if (l >= x && r <= y) { s[id].push_back(e); return; }
	int m = l + r >> 1, a = id << 1, b = a | 1;
	adsg(e, x, y, l, m, a);
	adsg(e, x, y, m + 1, r, b);
}

int pa[N << 1 | 1];
pair<int, int> sz[N << 1 | 1];
stack<pair<int, int> > st;
ll can;

int P(int p) { while (pa[p])p = pa[p]; return p; }
void adan(pair<int, int> p) { can += (ll)p.first * p.second; }
void sban(pair<int, int> p) { can -= (ll)p.first * p.second; }

void fn(int l = 1, int r = q, int id = 1){
	int undc = 0;
	for (auto &t: s[id]){
		int a = P(t.first), b = P(t.second);
		if (a == b)continue;
		if (sz[a].first + sz[a].second < sz[b].first + sz[b].second)swap(a, b);
		pa[b] = a;
		sban(sz[a]);
		sban(sz[b]);
		sz[a].first += sz[b].first;
		sz[a].second += sz[b].second;
		adan(sz[a]);
		st.push(make_pair(a, b));
		++undc;
	}
	if (l == r)an[l] += can;
	else {
		int m = l + r >> 1, a = id << 1, b = a | 1;
		fn(l, m, a);
		fn(m + 1, r, b);
	}
	while (undc--){
		int a = st.top().first, b = st.top().second;
		st.pop();
		sban(sz[a]);
		sz[a].first -= sz[b].first;
		sz[a].second -= sz[b].second;
		adan(sz[a]);
		adan(sz[b]);
		pa[b] = 0;
	}
}

int main(){
	scanf("%d", &q);
	f(i, 0, q){
		int a, b;
		scanf("%d%d", &a, &b);
		b += N;
		pair<int, int> v = make_pair(a, b);
		auto it = edtm.find(v);
		if (it == edtm.end())edtm[v] = i + 1;
		else adsg(v, it->second, i), edtm.erase(it);
	}
	for (auto it = edtm.begin(); it != edtm.end(); ++it)adsg(it->first, it->second, q);
	f(i, 1, N + 1)sz[i].first = 1;
	f(i, N + 1, N << 1 | 1)sz[i].second = 1;
	fn();
	printf("%lld", an[1]);
	f(i, 2, q + 1)printf(" %lld", an[i]);
	printf("\n");
}