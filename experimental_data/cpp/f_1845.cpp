// LUOGU_RID: 155244747
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define md(a) a=(a%mod+mod)%mod
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)

bool ST;

const int N=400005,M=800005,mod=1e9+7;const double pi=acos(-1);
int m=4e5,L,T,n,a[N],v[M],g[2][N],f[2][N],Ans;
inline void add(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
inline void dec(int &x,const int &y){x-=y;if(x<0)x+=mod;}
int mu[N],pr[N],vst[N],upd,tmp[2][N];vector<int>inc[N];
void init()
{
	upd=N-5,mu[1]=1;
	for(int i=2;i<=upd;i++)
	{
		if(!vst[i])pr[++pr[0]]=i,mu[i]=-1;
		for(int j=1;i*pr[j]<=upd&&j<=pr[0];j++){vst[i*pr[j]]=1;if(i%pr[j]==0)break;mu[i*pr[j]]=-mu[i];}
	}for(int i=1;i<=upd;i++)if(mu[i]<0)mu[i]+=mod;
}
int l=0,lim=1,rev[M];
struct cox
{
	double x,y;
	inline cox friend operator +(const cox &a,const cox &b){return {a.x+b.x,a.y+b.y};}
	inline cox friend operator -(const cox &a,const cox &b){return {a.x-b.x,a.y-b.y};}
	inline cox friend operator *(const cox &a,const cox &b){return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
	inline cox friend operator /(const cox &a,const double &d){return {a.x/d,a.y/d};}
}A[M],B[M];int val[M];
inline void FFT(cox *A,int type)
{
	for(int i=0;i<lim;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int p=1;p<=l;p++)
	{
		int m=(1<<p);cox wm={cos(pi/(m/2)),type*sin(pi/(m/2))};
		for(int i=0;i<lim;i+=m)
		{
			cox w={1,0};
			for(int j=0;j<m/2;j++,w=w*wm){cox u=A[i+j],t=w*A[i+j+m/2];A[i+j]=u+t,A[i+j+m/2]=u-t;}
		}
	}
}
inline void Merge(bool op)
{
	l=0,lim=1;while(lim<=m)lim<<=1,l++;for(int i=0;i<lim;i++)rev[i]=((rev[i>>1]>>1)|((i&1)<<(l-1)));FFT(A,1),FFT(B,1);
	for(int i=0;i<lim;i++)A[i]=A[i]*B[i];FFT(A,-1);for(int i=0;i<lim;i++)A[i]=A[i]/lim;
	for(int i=1;i<=n;i++){if(!op)A[a[i]+a[i]].x--;else A[m/2].x--;}
	for(int i=0;i<lim;i++)val[i]=(int)(A[i].x+0.5);
}

bool ED;

signed main()
{
    int time_st=clock();
	cerr<<(&ST-&ED)/1024.0/1024<<endl;ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>L>>T>>n;L*=2;for(int i=1;i<=n;i++)cin>>a[i];init();
	for(int j=1;j<=m;j++)for(int i=j;i<=m;i+=j)inc[i].push_back(j);
	for(int i=0;i<M;i++)A[i]=B[i]={0,0};for(int i=1;i<=n;i++)A[a[i]]=B[a[i]]={1,0};
	Merge(0);for(int i=0;i<=m;i++)if(val[i])v[i]=1;
	for(int i=0;i<M;i++)A[i]=B[i]={0,0};for(int i=1;i<=n;i++)A[a[i]]=B[m/2-a[i]]={1,0};
	Merge(1);for(int i=0;i<=m;i++)if(val[m/2+i])v[i]=1;
	for(int i=1;i<=m;i++)if(v[i])
	{
		for(int t=0;t<2;t++)for(int j:inc[i])add(tmp[t^1][j],f[t][j]);for(int j:inc[i])add(tmp[1][j],1);
		for(int j:inc[i])add(f[0][j],tmp[0][j]),add(f[1][j],tmp[1][j]),tmp[0][j]=tmp[1][j]=0;
	}
	for(int j=1;j<=m;j++)for(int i=j;i<=m;i+=j)for(int t=0;t<2;t++)add(g[t][j],mu[i/j]*f[t][i]%mod);
	for(int t=0;t<2;t++)for(int i=1;i<=m;i++)
	{
		int s=T*i;s/=L;
		if(t&1)add(Ans,g[t][i]*s%mod);
		else dec(Ans,g[t][i]*s%mod);
	}
	cout<<Ans<<'\n';
	cerr<<(clock()-time_st)/1e6<<endl;return 0;
}