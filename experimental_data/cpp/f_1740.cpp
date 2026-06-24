// LUOGU_RID: 99511459
#include<bits/stdc++.h>

#define ll long long

#define LL __int128

#define dd double

using namespace std;

char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}

//#define getchar gc

ll read()

{

	char c;

	ll w=1;

	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;

	ll ans=c-'0';

	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';

	return ans*w;

}

void pc(char c,int op)

{

	static char buf[1<<16],*s=buf,*t=buf+(1<<16);

	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);

}

void wt(int x)

{

	if(x>9)wt(x/10);

	pc('0'+x%10,0);

}

void wts(int x,char op)

{

	if(x<0)pc('-',0),x=-x;

	wt(x);pc(op,0);

}

namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}



ll jiec[xx],ni[xx];

ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}

void pre()

{

	jiec[0]=1;

	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;

	ni[xx-1]=ksm(jiec[xx-1],mod-2);

	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;

}

	

int prim[xx],mn[xx],Cnt;

void pre(int n)

{

	for(int i=2;i<=n;i++)

	{

		if(!mn[i])mn[i]=i,prim[++Cnt]=i;

		for(int j=1;j<=Cnt;j++)

		{

			if(prim[j]*i>n)break;

			mn[i*prim[j]]=prim[j];

			if(i%prim[j]==0)break;

		}

	}

}





int lb(int x){return x&-x;}

ll sum[xx];

void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}

ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}



struct nod{int next,to;}e[xx<<1];

int cnt,h[xx];

void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}



random_device R;

mt19937 G(218);

int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}



}



int gcd(int a,int b){return !b?a:gcd(b,a%b);}

//上面的数组，要用就co下来再用。 

const int xx=1e6+5,mod=998244353;

//注意mod是1e9+7还是998！！！ 



ll ksm(ll a,ll b)

{

	ll ans=1;

	while(b)

	{

		if(b&1)ans*=a,ans%=mod;

		a*=a,a%=mod,b>>=1;

	}

	return ans;

}



#define Pr pair<int,int>

#define fi first

#define se second

int n,m,k,q,a[xx],b[xx];

char s[xx];

int t[xx];

int f[2][2005][2005];

int suf[xx];

void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}

void ad(int &a,ll b){(a=(a+b)%mod);}

int red(int x){return x>=mod?x-=mod:x;}

int lim[xx];

int main(){

	n=read();

	for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;

	sort(t+1,t+n+1,[&](int a,int b){return a>b;});

	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+t[i];

	f[0][0][n]=1;

	for(int i=1;i<=n+1;i++)

		lim[i]=upper_bound(t+1,t+n+1,i,[&](int a,int b){return a>b;})-t;

	//第一个小于的位置 

	int ans=0;

	for(int i=0;i<=n;i++)

	{

		for(int j=0;j<=n;j++)

		{

			for(int w=(n/max(i,1));w>=1;w--)

			{

				if(!f[i&1][j][w])continue;

//				cerr<<i<<" "<<j<<" "<<w<<" "<<f[i&1][j][w]<<"$\n";

				int v=f[i&1][j][w];

				if(w!=1)ad(f[i&1][j][w-1],v);

				int A=j;

				A-=min(w,(lim[i]-1))*i;

				int rem=suf[min(lim[i],w+1)]-A;//rem 能否填补这个 i+1 层。  

				assert(rem>=0);

				if(rem>=max(0,w-lim[i+1]+1))

					ad(f[(i+1)&1][j+w][w],v);

				if(w==1&&j==n)ad(ans,f[i&1][n][1]);

				f[i&1][j][w]=0;

			}

		}

	}

	cout<<ans<<"\n";

	pc('1',1);

	return 0;

}