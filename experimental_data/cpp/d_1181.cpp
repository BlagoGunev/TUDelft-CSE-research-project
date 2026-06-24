#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename _tp> inline void read(_tp&x) {
	char ch=getchar(),ob=0;x=0;
	while(ch!='-'&&!isdigit(ch))ch=getchar();if(ch=='-')ob=1,ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();if(ob)x=-x;
}

const int N = 501000;
int sz[N<<2];
int a[N];
int Ans[N];

int n, m, Q;

pair <int,int> b[N];
pair <ll, int> q[N];

void upd(int l, int r, int x, int ps) {
	++sz[x];
	if(l == r) return ;
	int mid = l + r >> 1;
	if(ps <= mid) upd(l, mid, x<<1, ps);
	else upd(mid+1, r, x<<1|1, ps);
}

int qry(int l, int r, int x, int k) {
	if(l == r) return l;
	int mid = l + r >> 1;
	if(k <= sz[x<<1]) return qry(l, mid, x<<1, k);
	else return qry(mid+1, r, x<<1|1, k-sz[x<<1]);
}

int main() {
	read(n), read(m), read(Q);
	for(int i=1,x;i<=n;++i) read(x), ++a[x];
	for(int i=1;i<=m;++i) b[i] = make_pair(a[i], i);
	sort(b+1,b+m+1);
	for(int i=1;i<=Q;++i) read(q[i].first), q[i].first -=n, q[i].second = i;
	sort(q+1,q+Q+1);
	int qt = 1;
	
	ll L = 0;
	b[++m] = make_pair(int(1e9), 1);
	for(int i=1,j=1;i<=m;i=j) {
		ll R = L + (ll)(i-1) * (b[i].first - b[i-1].first);
		if(i == m) R = 2e18;
		while(qt <= Q and q[qt].first <= R) {
			int t = (q[qt].first-L-1)%(i-1)+1;
			Ans[q[qt].second] = qry(1,m,1,t);
			++qt;
		}
		L = R;
		while(j <= m and b[i].first == b[j].first) ++j;
		for(int l=i;l<j;++l)
			upd(1,m,1,b[l].second);
	}
	
	for(int i=1;i<=Q;++i) printf("%d\n", Ans[i]);
	return 0;
}