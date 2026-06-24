/* Code by pp_orange */
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define m_p(a,b) make_pair(a,b)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
#define inf 0x7FFFFFFF
#define inff 9223372036854775807
#define rep(i,l,r) for(int i=l;i<r;++i)
#define repp(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r-1;i>=l;--i)
#define pper(i,r,l) for(int i=r;i>=l;--i)
#define pii pair<int,int>
#define fi first
#define se second
#define p_q priority_queue
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define lb(x) ((x)&-(x))
#define lg(x) (31^__builtin_clz(x))
#define vi vector<int>
#define vii vector<pii >
#define vT vector<T>
#define mm1 mint(1)
const int mod = 998244353;
//#define int ll
const int intsz = sizeof(int);
using namespace std;
inline int rd(){
	int x(0),f(1);char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
inline void out(int X){
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) out(X/10);
	putchar(X%10+'0');
}
ll pw(ll x,int d){
	ll t = 1;
	for(;d;d>>=1,x=x*x%mod)if(d&1)t = t*x%mod;
	return t;
}
#define MAX 505
int a[MAX][MAX];
vii v[MAX];
signed main(){
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	int n = rd();
	int m = rd();
	int k = rd();
	repp(i,1,n){
		repp(j,1,m){
			int c = rd();
			a[i][j] = c;
			v[c].pb({i,j});
		}
	}
	vector<array<int,4> > ans;
	repp(i,1,n){
		repp(j,1,m){
			int x = i,y = j,z = 1,c=a[i][j];
			repp(t,1,n-i){
				z++;
				ans.pb({x,y,z,c});
			}
			repp(t,1,i-1){
				x++;
				ans.pb({x,y,z,c});
			}
			repp(t,1,i-1){
				z++;
				ans.pb({x,y,z,c});
			}
		}
	}
	// ans.pb({-1,-1,-1,-1});
	repp(cc,1,k){
		for(auto [x,y] : v[cc]){
			int z = n;
			repp(t,1,cc){
				z++;
				ans.pb({x*2-1,y,z,cc});
			}
		}
		int z = cc+n;
		repp(i,1,n){
			repp(j,1,m){
				ans.pb({i*2,j,z,cc});
			}
		}
		repp(i,1,n*2){
			ans.pb({i,m+1,z,cc});
		}
	}
	assert(ans.size()<=400000);
	cout<<ans.size()<<endl;
	for(auto [x,y,z,c]:ans){
		cout<<x<<' '<<y<<' '<<z<<' '<<c<<endl;
	}
	return 0;
}