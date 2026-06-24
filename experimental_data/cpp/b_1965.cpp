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
#define int ll
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
#define MAX 200005
signed main(){
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	int T = rd();
	while(T--){
		int n = rd();
		int k = rd();
		int lst = 0;
		vi v;
		if(k==1){
			rep(i,1,21)v.pb(1<<i);
			v.pb(3);
			cout<<v.size()<<endl;
			for(auto itm:v)cout<<itm<<' ';cout<<endl;
			continue;
		}
		v.pb(1);
		lst = 1;
		while(lst<k-1){
			if(lst*2>=k){
				v.pb(k-1-lst);
				lst = k-1;
			}else{
				v.pb(lst);
				lst <<= 1;
			}
		}
		assert(lst == k-1);
		// cout<<"tmp : "<<v.size()<<endl;
		v.pb(k+1);
		lst = k*2;
		while(lst<n){
			v.pb(lst);
			lst <<= 1;
		}
		v.pb(k*3-1);
		assert(v.size()<=25);
		cout<<v.size()<<endl;
		for(auto itm:v)cout<<itm<<' ';cout<<endl;
	}
	return 0;
}