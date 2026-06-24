#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int r[4000010],w[4000010];

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline void add2(int &x,int y)
{
	x+=y;
	if(x<0) x+=MOD;
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline void init()
{
	for(int i=1;i<22;i++){
		int wn=my_pow(3,(MOD-1)/(1<<i)),now=1;
		for(int j=0;j<(1<<(i-1));j++){
			w[(1<<(i-1))+j]=now;
			now=1ll*now*wn%MOD;
		}
	}
}

inline void NTT(vector<int> &a)
{
	int n=a.size();
	int p=1,k=0;
	while(p<n) p*=2,k++;
	for(int i=1;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(int i=1;i<=k;i++){
		for(int j=0;j<(1<<k);j+=(1<<i)){
			int off=(1<<(i-1));
			for(int l=j;l<j+off;l++){
				int x=a[l],y=1ll*a[l+off]*w[off+l-j]%MOD;
				a[l]=(x+y)>=MOD?(x+y-MOD):(x+y);
				a[l+off]=(x-y)<0?(x-y+MOD):(x-y);
			}
		}
	}
}

inline vector<int> convolution(vector<int> a,vector<int> b)
{
	int n=a.size(),m=b.size();
	int k=1;
	while(k<n+m) k*=2;
	a.resize(k);b.resize(k);
	NTT(a);NTT(b);
	for(int i=0;i<k;i++) a[i]=1ll*a[i]*b[i]%MOD;
	NTT(a);
	reverse(a.begin()+1,a.end());
	a.resize(n+m-1);
	int rev=my_pow(k,MOD-2);
	for(int i=0;i<n+m-1;i++) a[i]=1ll*a[i]*rev%MOD;
	return a;
}

int f[400010],g[400010],pw[400010],rev[400010];

inline int calc(int x,int y)
{
	if(x<y) return 0;
	return 1ll*pw[x]*rev[y]%MOD*rev[x-y]%MOD;
}

inline void solve(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	solve(l,mid);
	vector<int> v1,v2,v3;
	for(int i=l;i<=mid;i++) v1.push_back(f[i]);
	for(int i=1;i<=r-l;i++) v2.push_back(g[i]);
	v3=convolution(v1,v2);
	for(int i=mid+1;i<=r;i++){
		add2(f[i],-v3[i-l-1]);
	}
	solve(mid+1,r);
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		int a,b,c;cin>>a>>b>>c;
		int n=a+c+5;
		pw[0]=1;
		for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*i%MOD;
		rev[n]=my_pow(pw[n],MOD-2);
		for(int i=n-1;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
		int tot=1ll*calc(n,a+5)*calc(a+5,5)%MOD;
		int ans=tot,sum=c-a-5;
		for(int i=0;i<=a+c+5;i++){
			f[i]=0;
			int j=-5;
			if(i-j>=0&&(i-j)%2==0){
				int u=(i-j)/2;
				if(u>a+5) continue;
				if(u>i) continue;
				add2(f[i],-calc(i,u));
			}
		}
		for(int i=1;i<=a+c+5;i++){
			g[i]=0;
			if(i%2==0) g[i]=calc(i,i/2);
		}
		solve(0,a+c+5);
		for(int i=1;i<=a+c+5;i++){
			int j=sum+5;
			if(i-j>=0&&(i-j)%2==0){
				int u=(i-j)/2;
				if(u>a+5) continue;
				if(u>i) continue;
				for(int k=1;k<=5;k++){
					add1(ans,1ll*calc(i,u)*calc(u,k)%MOD*calc(a+5-u,5-k)%MOD*f[a+c+5-i]%MOD);
				}
			}
		}
		ans=1ll*ans*my_pow(tot,MOD-2)%MOD;
		cout<<ans<<'\n';
	}
	return 0;
}