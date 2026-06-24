#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <ctime>
#include <vector>
#define ls id<<1
#define rs id<<1|1
//#define mid (l+r>>1)
#define Mid (L+R>>1)
#define ll long long
//#define Vector Point
#define mul(a,b) (1ll*(a)*(b)%mod)
const int N=200010;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int mod=1000000007;
const double pi=acos(-1);
const double eps=1e-7;
const int SIZE=1<<21;
char ibuf[SIZE],*iS,*iT;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),iS==iT?EOF:*iS++):*iS++)
//#define gc() getchar()
template <class T>
void read(T &x)
{
	int f=0;x=0;char c=gc();
	while(!isdigit(c)) f|=c=='-',c=gc();
	while(isdigit(c)) x=x*10+c-'0',c=gc();
	if(f) x=-x;
}
template <class T>
T plus(T a,T b){return a+b>=mod?a+b-mod:a+b;}
template <class T>
T Abs(T x){return x>0?x:-x;}
template <class T> 
inline void ckmax(T &x,T y){x=x>y?x:y;}
template <class T> 
void ckmin(T &x,T y){x=x<y?x:y;}
template <class T>
T GCD(T a,T b){return b?GCD(b,a%b):a;}
int qp(int a,int b){int r=1;for(;b;a=mul(a,a),b>>=1) if(b&1) r=mul(r,a);return r;}
int pri[N],is[N],Id[N],iid[N],cnt;
void init()
{
	for(int i=2;i<=N-10;i++)
	{
		Id[i-1]=1;
		if(!is[i]) {pri[++cnt]=i;iid[i]=cnt;}
		for(int t=i*2;t<=N-10;t+=i)
			is[t]=1;
	}
}
int GCD(int x,int y){return y?GCD(y,x%y):x;}
int n,q,a[N],gcd,sum[20000],tmp[N];
std::unordered_map <int,int> ct[N];
void work()
{
	read(n),read(q);
	for(int i=1;i<=n;i++) 
		read(a[i]);
	int gcd=a[1];
	for(int i=2;i<=n;i++) gcd=GCD(gcd,a[i]);
	for(int i=1;i<=n;i++) 
	{
		a[i]/=gcd;
		for(int j=1;j<=cnt&&pri[j]*pri[j]<=a[i];j++)
		{
			while(a[i]%pri[j]==0)
			{
				//puts("Dew");
				a[i]/=pri[j];
				//sum[j][++ct[i][j]]++;
				if(++ct[i][j]==Id[j]) ++sum[j];
			}
		}
		if(a[i]!=1)
		{
			int j=iid[a[i]];
			if(++ct[i][j]==Id[j]) ++sum[j];
		}
	}
	//for(int i=1;i<=5;i++) printf("%d ",sum[i]);puts("");
	//printf("%d\n",cnt);
	//printf("%d\n",sum[1]);
	for(int id,x,i=1;i<=q;i++)
	{
		read(id),read(x);
		/*if(!is[x])
		{
			++ct[iid[x]][j];
			continue;
		}*/
		for(int j=1;j<=cnt&&pri[j]*pri[j]<=x;j++)
		{
			int flg=0;
			while(x%pri[j]==0)
			{
				flg=1;
				x/=pri[j];
				//if(ct[id][j]<=49)
				//	sum[j][++ct[id][j]]++;
				++ct[id][j];
				if(ct[id][j]==Id[j]) ++sum[j];
				/*if(ct[id][j]==Id[j])
				{
					++sum[j];
					if(sum[j]==n)
					{
						Id[j]++;
						gcd=1ll*gcd*pri[j]%mod;
						sum[j]=0;
						for(int k=1;k<=n;k++)
							if(ct[k][j]>=Id[j])
								++sum[j];
					}
				}*/
			}
			if(flg)
			{
				if(sum[j]==n)
				{
					int mi=1e9;
					sum[j]=0;
					for(int k=1;k<=n;k++)
					{
						tmp[k]=ct[k][j];
						//if(mi<=tmp) ++sum[j];
						//else sum[j]=1,mi=tmp;
						ckmin(mi,ct[k][j]);
					}
					//printf("%d\n",mi);
					for(int k=1;k<=mi+1-Id[j];k++) gcd=1ll*gcd*pri[j]%mod;
					Id[j]=mi+1;
					for(int k=1;k<=n;k++)
						if(Id[j]<=tmp[k])
							++sum[j];
				}
			}
		}
		if(x!=1)
		{
			int j=iid[x];
			if(++ct[id][j]==Id[j]) ++sum[j];
			if(sum[j]==n)
			{
				sum[j]=0;
				gcd=1ll*gcd*pri[j]%mod;
				++Id[j];
				for(int k=1;k<=n;k++)
					if(Id[j]<=ct[k][j])
						++sum[j];
			}
		}
		printf("%d\n",gcd);
	}
}
int main()
{
	srand(time(0));
	init();
	int T=1;
	//read(T);
	//scanf("%d",&T);
	while(T--) work();
	return 0;
}