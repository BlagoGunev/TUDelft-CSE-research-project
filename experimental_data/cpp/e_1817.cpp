// LUOGU_RID: 165991517
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using pi=pair<int,int>;
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define G(i,a,b) for(int i=(a);i>=(b);i--)
#define ms(a,b) memset(a,b,sizeof(a))
#define si(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define pb push_back

#if 1
template<class A>
void dbg(string s,A a){
	if(si(s)) cout<<'['<<s<<"]: ";
	cout<<a<<'\n';
}
template<class A,class... B>
void dbg(string s,A a,B... b){
	if(si(s)) cout<<'['<<s<<"]: ";
	cout<<a<<' ';
	dbg("",b...);
}
template<class T>
void dbg(string s,T *a,int l,int r){
	cout<<'['<<s<<"]: ";
	F(i,l,r) cout<<a[i]<<" \n"[i==r];
}
template<class T>
void dbg(string s,vector<T> a){
	cout<<'['<<s<<"]: ";
	for(T x:a) cout<<x<<' ';
	cout<<'\n';
}
#else
#define dbg(...)
#endif

const int mod=1e9+7,i2=(mod+1)/2;
struct mint{
	int x;
	mint(int x=0):x(x){}
	mint &operator+=(const mint &a){
		if((x+=a.x)>=mod) x-=mod;
		return *this;
	}
	mint &operator-=(const mint &a){
		if((x-=a.x)<0) x+=mod;
		return *this;
	}
	mint &operator*=(const mint &a){
		x=(ll)x*a.x%mod;
		return *this;
	}
	friend mint operator+(mint a,const mint &b){
		return a+=b;
	}
	friend mint operator-(mint a,const mint &b){
		return a-=b;
	}
	friend mint operator*(mint a,const mint &b){
		return a*=b;
	}
	mint pow(ll b=mod-2){
		mint a=x,res=1;
		for(;b;b>>=1,a*=a) if(b&1) res*=a;
		return res;
	}
};

const int N=1e6+3;
int n,a[N];
mint pw[N];

const int B=1<<30;
struct ds{
	map<int,ll> d;
	void add(ll x,int y){
		d[y]+=x;
		while(1){
			ll t=d[y]/B;
			if(!(d[y]%=B)) d.erase(y);
			if(!t) return;
			d[++y]+=t;
		}
	}
	int sign(){
		if(!si(d)) return 0;
		if(prev(d.end())->se>0) return 1;
		return -1;
	}
};

int slv(int l,int r){
	if(l==r) return l;
	int mid=(l+r)>>1,x=slv(l,mid),y=slv(mid+1,r);
	ds num;
	auto add=[&](ll x,int y){
		num.add(x*(1<<(y%30)),y/30);	
	};
	F(i,x+1,y){
		add(a[i+1]-a[i],n-(n-i));
		add(-(a[i]-a[i-1]),n-(i-1));
	}
	if(num.sign()>0) return y;
	return x; 
}

void slv(){
	cin>>n;
	F(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int k=slv(1,n-1);
//	dbg("a",a,1,n);
//	dbg("k",k);
	pw[0]=1;
	F(i,1,n) pw[i]=pw[i-1]*i2;
	mint ans=0;
	F(i,1,k-1) ans-=a[i]*pw[i];
	F(i,k+2,n) ans+=a[i]*pw[n-i+1];
	ans-=a[k]*pw[k-1];
	ans+=a[k+1]*pw[n-k-1];
	cout<<ans.x<<'\n';
}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) slv();
}