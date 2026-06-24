// LUOGU_RID: 167909150
#include <bits/stdc++.h>
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mp_ make_pair
#define pb_ push_back
#define pob_ pop_back
#define fst first
#define snd second
#define debug cout<<"********\n";
#define reset(x,y) memset(x,y,sizeof(x))
#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define iosf ios::sync_with_stdio(0);cin.tie(0);
#define prec(x) cout<<setprecision(x);
#define prec0(x) cout<<fixed<<setprecision(x);
#define Misaka16172 sb
#define kamisako femboy

using ll = long long;
using ld = long double;
using db = double;
using ull = unsigned long long;
using uint = unsigned int;

constexpr int inf = 0x3f3f3f3f;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ull mod1 = 1e9+7,mod9 = 998244353;

using namespace std;

template <class T>
inline void read(T &x){
    x = 0;T w = 1;
    char c = 0;
    while(!isdigit(c)){
        if(c=='-')  w = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = ((x<<3)+(x<<1))+c-'0';
        c = getchar();
    }
    x = x*w;
}
template<class T,typename ...Args>
inline void read(T &x,Args &...rest){read(x);read(rest...);}

template<class T>
inline void write(T x){
    if(!x)  return putchar('0'),void();
    else if(x<0) putchar('-'),x*=-1;
    int st[40],t = 0;
    while(x){st[++t] = x%10,x/=10;}
    while(t){putchar(st[t--]+'0');}
}

template <class T>
inline string bin(T x,int d = 0){return (((d>1)||(x>>1))?bin(x>>1,d-1):"")+to_string(x&1);}

int Test = 1,Case = 1;

constexpr int N = 1e5+5,LOG_N = 19,D = 63;

ll dep[N][D],d[N];
vector<pii> tr[N];
int n,fa[N][LOG_N],_dep[N],L[N];
ll ans[N];

void dfs(int u){
	_dep[u] = _dep[fa[u][0]]+1;
	for(int i=1;i<=__lg(_dep[u]);i++)	fa[u][i] = fa[fa[u][i-1]][i-1];
	for(pii e:tr[u]){
		int v = e.fst;
		if(v==fa[u][0])	continue;
		fa[v][0] = u,dfs(v);
	}
}

int lca(int u,int v){
	if(_dep[u]<_dep[v])	swap(u,v);
	while(_dep[u]!=_dep[v])	u = fa[u][__lg(_dep[u]-_dep[v])];
	if(u==v)	return u;
	for(int i=__lg(_dep[u]);i>=0;i--){
		if(fa[u][i]!=fa[v][i])	u = fa[u][i],v = fa[v][i];
	}
	return fa[u][0];
}

void dfs2(int u){
	for(pii e:tr[u]){
		int v = e.fst;
		if(v==fa[u][0])	continue;
		if(dep[v][D-1]<=dep[u][D-1])	throw -1;
		ans[e.snd] = dep[v][D-1]-dep[u][D-1];
		if(ans[e.snd]>1000000000000ll)	throw -1;
		dfs2(v);
	}
}

void solve(){
    read(n);
    for(int i=1;i<n;i++){
    	int u,v;read(u,v);
    	tr[u].pb_({v,i}),tr[v].pb_({u,i});
    }
    for(int i=1;i<n;i++)	read(d[i]);
    dfs(1);
	for(int i=1;i<n;i++)	L[i] = lca(i,i+1);
	for(int j=1;j<D;j++){
		for(int i=1;i<n;i++)	dep[i+1][j] = (d[i]-dep[i][j]+(dep[L[i]][j-1]<<1)+(1ll<<j))%(1ll<<j);
		// for(int i=1;i<=n;i++)	cout<<i<<" "<<j<<" "<<dep[i][j]<<"\n";
	}
	try{dfs2(1);}
	catch(int e){cout<<-1;return;}
	for(int i=1;i<n;i++)	cout<<ans[i]<<"\n";
}

int main(){
//  read(Test);
    for(;Case<=Test;++Case) solve();
    return 0;
}