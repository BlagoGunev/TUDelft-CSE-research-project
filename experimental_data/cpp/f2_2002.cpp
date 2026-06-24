#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define I ll
#define her1 20081214
#define IV void
#define cht 998244353
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define cp(x,y)memcpy(x,y,sizeof y)
#define mem(x,val)memset(x,val,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(register ll i=j;i>=n;i--)
//#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
//#define FL(i,j,n)for(register ll i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#undef ll
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
const int MAX = 2e7;
using i64 = long long;
const int maxn = 1e6+5;
const int maxm = 2e7+5;
i64 n,m,l,f;
// i64 gcd(i64 x,i64 y){return!y?x:gcd(y,x%y);}
bool vis[maxm];i64 pr[maxm/3],tot,lst[maxm],bk[maxm];
IV init(){
	F(i,2,MAX){
		if(!vis[i])bk[pr[++tot]=i]=i;
		for(register int j=1;i*pr[j]<=MAX&&j<=tot;j++){
			vis[i*pr[j]]=1;bk[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
	F(i,1,MAX){
		if(!vis[i])lst[i]=i;
		else lst[i]=lst[i-1];
	}
	// i64 mx=0;
	// F(i,1,MAX)mx=max(mx,i-lst[i]);
	// cout<<mx;
}
i64 gcd(i64 x,i64 y){
	return!y?x:gcd(y,x%y);
}
set<i64>st;
i64 qwq[23333],qc;
// i64 lcm(i64 x,i64 y){
	
// }
bool ff[505][505];i64 D1,D2;
bool&T(i64 x,i64 y){
	return ff[x-D1][y-D2];
}
bool v2[505][505];
IV solve(){
	n=read();m=read();l=read();f=read();
	if(n<m)swap(n,m),swap(l,f);
	i64 p=lst[n],ans;
	if(p<=n&&p<=m){
		ans=(p-1)*(l+f)+max(l,f);
		i64 now=p-1;st.clear();
		F(i,p+1,n){
			i64 orz=i;
			while(orz!=1){
				st.insert(bk[orz]);
				orz/=bk[orz];
			}
		}
		qc=0;for(auto x:st)qwq[++qc]=x;
		while(now){
			bool flag=1;
			F(i,1,qc)if(now%qwq[i]==0)
				{flag=0;break;}
			if(flag)break;
			now--;
		}
		assert(n-now<=500);
		if(!now){
			F(i,0,n)F(j,0,m)if(v2[i][j])ans=max(ans,l*i+f*j);
			printf("%lld\n",ans);return;
		}
		D1=D2=now-1;
		F(i,0,n-now+1)F(j,0,n-now+1)ff[i][j]=0;
		F(i,now,n)F(j,now,n)if(i>=p||j>=p){
			if(i==now||j==now)T(i,j)=1;
			else{
				if(gcd(i,j)!=1)T(i,j)=0;
				else T(i,j)=(T(i-1,j)||T(i,j-1));
			}
			if(T(i,j)&&i<=n&&j<=m)ans=max(ans,l*i+f*j);
		}
	}
	else{
		ans=p*l+m*f;
		i64 now=m;st.clear();
		F(i,p+1,n){
			i64 orz=i;
			while(orz!=1){
				st.insert(bk[orz]);
				orz/=bk[orz];
			}
		}
		qc=0;for(auto x:st)qwq[++qc]=x;
		while(now){
			bool flag=1;
			F(i,1,qc)if(now%qwq[i]==0)
				{flag=0;break;}
			if(flag)break;
			now--;
		}
		if(!now){
			F(i,0,n)F(j,0,m)if(v2[i][j])ans=max(ans,l*i+f*j);
			printf("%lld\n",ans);return;
		}
		D1=p-1;D2=now-1;
		F(i,0,n-D1)F(j,0,m-D2)ff[i][j]=0;
		F(i,p,n)F(j,now,m)if(i>=p||j>=p){
			if(i==now||j==now)T(i,j)=1;
			else{
				if(gcd(i,j)!=1)T(i,j)=0;
				else T(i,j)=(T(i-1,j)||T(i,j-1));
			}
			if(T(i,j))ans=max(ans,l*i+f*j);
		}
	}
	printf("%lld\n",ans);

}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	init();
	v2[0][0]=1;
	F(i,0,500)F(j,0,500){
		if(i||j)if(gcd(i,j)<=1){
			if(i)v2[i][j]|=v2[i-1][j];
			if(j)v2[i][j]|=v2[i][j-1];
		}
	}
	i64 T=read();
	while(T--)solve();
	return 0;
}