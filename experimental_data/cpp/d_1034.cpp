#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pr = pair<int,int>;

#define se second
#define fi first

const int N = 3e5 + 5;

struct node{
	int l,r,i;
	node(int l,int r = -1,int i = 0) : l(l),r(r),i(i){}
	bool operator<(const node& t) const { return pr(l,r) < pr(t.l,t.r); }
};

int n,k; pr a[N];
ll res,c[N];
vector<pr> b[N];
set<node> S;

auto split(int p){
	auto it = S.lower_bound(node(p));
	if(it != S.end() && it->l == p) return it;
	auto[l,r,i] = *(--it);
	S.erase(it); S.emplace(l,p,i);
	return S.emplace(p,r,i).first;
}

void assign(int i){
	auto[l,r] = a[i];
	auto ir = split(r),il = split(l);
	for(auto it = il;it != ir;++it)
		b[i].emplace_back(it->i,it->r - it->l);
	S.erase(il,ir); S.emplace(l,r,i);
	sort(begin(b[i]),end(b[i]));
}

bool chk(int mid){
	for(int i = 0;i <= n + 1;++i) c[i] = 0;
	ll val = 0,sum = 0,cnt = 0,tot = 0;
	for(int R = 1,L = 1;R <= n;++R){
		val += a[R].se - a[R].fi;
		sum += 1LL * (a[R].se - a[R].fi) * L;
		c[R + 1] = a[R].fi - a[R].se;
		for(auto[p,x] : b[R]){
			if(p < L) sum -= 1LL * p * x;
			else val -= x,sum -= 1LL * x * L,c[p + 1] += x;
		}
		while(val >= mid) sum += (val += c[++L]);
		cnt += L - 1,tot += sum - val;
	}
	if(cnt < k) return 0;
	return res = tot - (cnt - k) * mid,1;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;++i) scanf("%d%d",&a[i].fi,&a[i].se);
	S.emplace(1,1000000000,0);
	for(int i = 1;i <= n;++i) assign(i);
	for(int j = 30,f = 0;~j;--j) if(chk(f | (1 << j))) f |= (1 << j);
	printf("%lld\n",res);
	return 0;
}