#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<map>
#define llg int
using namespace std;
inline void getint(llg &x);
#define maxn 1100101
#define yyj(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);

llg n,m,rouP,a[maxn],x[maxn],y[maxn],z[maxn],t[maxn];
map<llg,llg>TU;

llg SJH(){ return (rand()<<15^rand())&(~0u>>1); }

llg gcd(const llg &a,const llg &b){ return b?gcd(b,a%b):a;}

void getllg(llg &x)
{
	char c;
	while(c=getchar(),c<'0'||c>'9'); x=c-'0'; 
	while(c=getchar(),c>='0'&&c<='9') x=x*10+c-'0';
}

inline void init() 
{
	getllg(n),
	getllg(m); 
	rouP=n; 
	x[0]=n;
	for(llg i=1;i<=m;i++) getllg(x[i]);	
	sort(x+1,x+m+1);
	for(llg i=1;i<=m;i++) 
		rouP=gcd(rouP,x[i]-x[1]);
	if(m==1) 
		{ 
			printf("%d 1\n",x[1]);
			 exit(0);
	    }
	if(m==n/rouP)
		 { 
					printf("%d %d\n",x[1],rouP); 
					exit(0); 
		}
	for(llg i=1;i<=m;i++) a[i]=x[i]/rouP;
}
/*
	for(int i=1;i<=N;i++)
		readi(crow[i].first),readi(crow[i].second);
	sort(crow+1,crow+N+1);
	double low=0,high=4e9,mid;
	while(low+1e-4<high)
	{
		mid=(low+high)*.5;
		for(int i=1;i<=N;i++)
			pos[i]=crow[i].first+crow[i].second*mid;
		if(LIS()>=N-K)low=mid;
		else high=mid;
	}*/
inline llg work(llg *x,llg n,llg m,llg TIM=0) 
{
	if(TIM>40)
		return -1;

	if(m<=50) 
{
		TU.clear();
		for(llg i=1;i<=m;i++) 
		{
			for(llg j=1;j<=m;j++) 
			{
				if(i!=j)
				{
					llg d;
					d=(x[i]-x[j]+n)%n;
					if(gcd(d,n)==1 && ++TU[d]==m-1) return d;
				}
			}
		}
		return -1;
	}

	if(m==n-1) return 1; 
	
	llg w=x[SJH()%m+1],my=0,mz=0,mt=0;
	
	if(w*2<n) {
		for(llg i=1;i<=m;i++)
 {
			if(w*2-x[i]<0) y[++my]=w*2-x[i]+n;
			else z[++mz]=w*2-x[i];
		}
	}
	else
 {
		for(llg i=1;i<=m;i++) {
			if(w*2-x[i]<n)
				y[++my]=w*2-x[i];
			else 
				z[++mz]=w*2-x[i]-n;
		}
	}

	llg i=1; llg j=my; llg k=mz;
	for(;i<=m;i++)	
{
		while(j && y[j]<x[i]) j--;
		while(k && z[k]<x[i]) k--;
		if( (!j||x[i]!=y[j]) && (!k||x[i]!=z[k]) )
			t[++mt]=x[i];
	}
	if(mt>1) 
	{ 
		memcpy(x,t,mt+1<<2); 
		return work(x,n,mt,TIM+1);
	}
	return work(x,n,m,TIM+1);
}

/*
void dfs(llg x,llg fa)
{
	llg w=a[x].size();
	++dfsn;
	lc[x]=dfsn;
	c[dfsn]=col[x];
	for (llg i=0;i<w;i++)
	{
		llg v=a[x][i];
		if (v==fa) continue;
		dfs(v,x);
	}
	rc[x]=dfsn;
	}*/

void work()
{
	llg d=work(a,n/rouP,m); 
	if(d==-1)
	{ 
		puts("-1"); return;
	} 
	d*=rouP; 
	llg s=x[1],JS=0;
	for(llg i=1;i<=m;i++) if(!binary_search(x+1,x+m+1,(x[i]+d)%n)) { JS++; s=x[i]; }
	if(JS<=1) printf("%d %d\n",s,(n-d)%n);
	else puts("-1");
}

llg main()
{		
//	yyj("E");
	init();  
	work();
	return 0;
}