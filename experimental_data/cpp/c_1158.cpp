/*input
1
3
4 4 4 
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=500005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}

int a[maxn];
int ans[maxn];
bool val;


void build(int l,int r,int ql,int qr){
	// cout<<l<<' '<<r<<' '<<ql<<' '<<qr<<'\n';
	int i;
	for(i=l;i<r;i++){
		if(a[i]!=r) break;
		--qr;
		ans[i]=qr;
	}
	// cout<<i<<'\n';
	if(i==r) return;
	if(a[i]>r){
		val=0;
		return;
	}
	while(i<r){
		if(a[i]>r){
			val=0;
			return;
		}
		build(i,a[i],ql,ql+a[i]-i);
		ql=ql+a[i]-i;
		i=a[i];
	}
}

void solve(){
	val=1;
	int n;
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) if(a[i]!=-1) a[i]--;
	{
		bool f=1;
		REP(i,n) if(a[i]!=-1) f=0;
		if(f){
			REP(i,n) cout<<i+1<<' ';
			cout<<'\n';
			return;
		}
	}

	if(a[0]==-1) a[0]=1;
	for(int i=1;i<n;i++){
		if(a[i]==-1){
			a[i]=a[i-1];
			if(a[i]==i) a[i]=i+1;
		}
	}

	int pt=0;
	while(pt<n){
		build(pt,a[pt],pt,a[pt]);
		pt=a[pt];
		if(!val) break; 
	}
	if(!val){
		cout<<"-1\n";
		return;
	}
	REP(i,n) cout<<ans[i]+1<<" \n"[i==n-1];
	return;
}

int main(){
	IOS;
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}