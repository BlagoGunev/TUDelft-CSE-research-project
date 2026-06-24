#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define eb emplace_back
#define mem(a,b) memset(a,b,sizeof(a))
#define mpy(a,b) memcpy(a,b,sizeof(b))
#define dbg(...) cerr<<"#"<<__LINE__<<": "<<__VA_ARGS__<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fio(s) Fi(s".in"),Fo(s".out")
#define SZ(S) (int)S.size()
//#define mod 998244353
//#define mod 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
using namespace std;

template <class T>
void chkmax(T &x,T y){
	if(x < y) x = y;
}

template <class T>
void chkmin(T &x,T y){
	if(x > y) x = y;
}

inline int popcnt(int x){
	return __builtin_popcount(x);
}

inline int ctz(int x){
	return __builtin_ctz(x);
}

/*template <class T,class U>
inline void add(T &x,U y){
	x += y;
	if(x >= mod) x -= mod;
}

template <class T,class U>
inline void sub(T &x,U y){
	x -= y;
	if(x < 0) x += mod;
}

ll power(ll p,int k = mod - 2){
	ll ans = 1;
	while(k){
		if(k % 2 == 1) ans = ans * p % mod;
		p = p * p % mod;
		k /= 2;	
	}
	return ans;
}*/
int T,n,m;

void solve(){
	scanf("%d%d",&n,&m);
	printf("%d\n",n * m);
	rep(i,1,n){
		rep(j,1,m){
			int ret = i + (j << 16);
			printf("%d ",ret);
		}
		printf("\n");
	}
}

int main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}