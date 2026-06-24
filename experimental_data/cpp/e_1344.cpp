// LUOGU_RID: 93116770
#include<bits/stdc++.h>

#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

#define mod 1000000007

#define ll long long

#define N 100005

#define fi first

#define se second

using namespace std;

template<class T>void read(T&x) {

	T f=1;x=0;char c=getchar();

	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}

	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}

	x*=f;

}

template<class T>void write(T x) {

	if(x<0)putchar('-'),x=-x;int s[20],top=0;

	while(s[++top]=x%10,x/=10);

	while(top)putchar(s[top--]+'0');putchar(' ');

}

template<class T,class...Ts>void write(T arg,Ts...args){write(arg);write(args...);}

template<class...Ts>void print(Ts...args){write(args...);putchar('\n');}

void cer(){cerr << '\n';}

template<class T,class...Ts>void cer(T arg,Ts...args){cerr << arg << ' ';cer(args...);}

namespace MAIN {

char _st;

int n,m,st[N],ed[N],idx;

bool chk(int x,int y){return st[x] <= st[y] && st[y] <= ed[x];}

vector<pair<int,int>>G[N];

vector<pair<ll,ll>>ddl;

set<pair<int,int>>s[N];

vector<int>vec[N];

priority_queue<ll,vector<ll>,greater<ll>>q;

void dfs(int x,ll d) {

	st[x] = ++idx;int mn = INT_MAX,mnid = G[x].back().fi,son = 0;

	for(auto e:G[x]) {

		int y = e.fi;dfs(y,d+e.se);

		int tmp = s[y].size()?(*s[y].begin()).first:INT_MAX;

		if(tmp < mn)mn = tmp,mnid = y;

		if(s[y].size() >= s[son].size())son = y;

	}

	if(mnid != G[x].back().fi)ddl.push_back({1,mn+d});

	swap(s[x],s[son]);

	for(auto e:G[x])if(e.fi != son)for(auto u:s[e.fi])s[x].insert(u);

	for(auto e:G[x])if(e.fi != son) {

		int y = e.fi;

		for(auto u:s[y]) {

			auto itl = s[x].lower_bound(u),itr = itl;itr++;

			if(itl != s[x].begin() && !chk(y,(*--itl).second))ddl.push_back({(*itl).fi+d+1,u.fi+d});

			if(itr != s[x].end() && chk(son,(*itr).second))ddl.push_back({u.fi+d+1,(*itr).fi+d});

		}

	}

	for(int t:vec[x])s[x].insert({t,x});

	ed[x] = idx;

}

char _ed;

int main() {

	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';

	read(n);read(m);

	for(int i=1,x,y,z; i<n; ++i)read(x),read(y),read(z),G[x].push_back({y,z});

	for(int i=1,x,t; i<=m; ++i)read(x),read(t),vec[x].push_back(t);

	dfs(1,0);sort(ddl.begin(),ddl.end());

	ll tim = -1;int ans = 0;

	for(int i=0,j; i<ddl.size()&&!~tim; i=j) {

		for(j=i; j<ddl.size()&&ddl[i].fi==ddl[j].fi; ++j);

		for(int k=i; k<j; ++k)q.push(ddl[k].se);

		ll nxt = j==ddl.size()?LLONG_MAX:ddl[j].fi;

		for(ll k=ddl[i].fi; k<nxt&&!q.empty(); ++k) {

			if(q.top() < k){tim = q.top();break;}

			q.pop();

		}

	}

	if(!~tim)ans = ddl.size();

	else for(auto u:ddl)if(u.se < tim)ans++;

	print(tim,ans);

	return 0;

}

}

int main(){MAIN::main();}