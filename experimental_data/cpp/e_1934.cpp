#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <vector>
#include <random>
#include <cstring>
#include <ctime>
#include <cmath>
#include <assert.h> 
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define LL long long
#define pp pair<int,int>
#define mp make_pair 
#define ull unsigned long long
namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
	//	return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
		return getchar();
	}
	template<class T> void gi(T& x){
		x=0; int f=1;char c=gc();
		if(c=='-')f=-1;
		for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
		x=x*f;
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='\n'){
		if(x<0)pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f; 
}
using IO::gi;
using IO::pi;
using IO::pc;
const int mod=998244353;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int dec(int x,int y){
	return x-y<0?x-y+mod:x-y;
}
inline int mul(int x,int y){
	return 1ll*x*y%mod;
}
inline int qkpow(int a,int b){
	if(b<0)return 0;
	int ans=1,base=a%mod;
	while(b){
		if(b&1)ans=1ll*ans*base%mod;
		base=1ll*base*base%mod;
		b>>=1;
	}
	return ans;
}
int fac[1000005],inv[1000005],Invn[600005];
inline int binom(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void init_C(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod; 
	inv[0]=1;
	inv[n]=qkpow(fac[n],mod-2);
	for(int i=n-1;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	Invn[0]=Invn[1]=1;
	for(int i=1;i<=200000;i++)Invn[i]=(LL)(mod-mod/i)*Invn[mod%i]%mod;
}
int t,n,p[25];
inline bool check(int x,int y,int z){
	int s=__gcd(x,__gcd(y,z));
	if(__gcd(x,y)!=s||__gcd(x,z)!=s||__gcd(y,z)!=s)return 0;
	return 1;
}
vector<array<int,3> >G;
inline void solve(){
	gi(n);
	if(n<=20){
		for(int i=1;i<=n;i++)p[i]=i;
		while(1){
			random_shuffle(p+1,p+n+1);
			bool fl=1;
			for(int i=n;i%3;i--)if(2*p[i]>n){
				fl=0;
				break;
			}
			for(int i=1;i<=n;i+=3){
				if(i+2<=n&&!check(p[i],p[i+1],p[i+2])){
					fl=0;
					break;
				}
			}
			if(fl){
				pi(n/3);
				for(int i=1;i<=n;i+=3){
					if(i+2>n)break;
					pi(p[i],' ');
					pi(p[i+1],' ');
					pi(p[i+2]); 
				}
				break;
			}
		}
		return ;
	}
	G.clear();
	if(n%4==3)G.push_back({n-2,n-1,n}),n-=3;
	if(n%4==0)G.push_back({1,n-1,n}),n-=2;
	for(int i=(n-1)/4*4+1;i*2>n;i-=4)G.push_back({i-2,i-1,i});
	for(int i=(n-2)/4*4+2;2*i>n;i-=12)G.push_back({i-8,i-4,i});
	pi(G.size());
	for(auto x:G)pi(x[0],' '),pi(x[1],' '),pi(x[2]);
}
signed main(){
	srand(time(0));
	gi(t);
	while(t--)solve();
	return 0;
}
/*
*/