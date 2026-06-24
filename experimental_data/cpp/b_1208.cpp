#include <cstdio>
#include <algorithm>
#define il inline
using namespace std;

int n,num,ans=2001,tot,t;
int a[2001];
struct node
{
	int x,id;
}b[2001];
int con[2001],tuc[2001],tuf[2001];

il int read()
{
	int res=0,sign=1;
	char c;
	
	while ((c=getchar())<'0'||c>'9') if (c=='-') sign=-1;
	
	res=c-'0';
	while ((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
	
	return res*sign;
} 

il bool cmp(node x,node y)
{
	return x.x<y.x;
}

int main()
{
	n=read();
	int i,j,k;
	for (i=1; i<=n; i++)
	{
		a[i]=read(),b[i]=(node){a[i],i};
	}
	
	sort(b+1,b+n+1,cmp);
	for (i=1; i<=n; i++)
	{
		if (b[i].x!=b[i-1].x) num++;
		con[b[i].id]=num,tuc[con[b[i].id]]++;	
	}
	
	for (i=1; i<=num; i++)
	{
		if (tuc[i]>1) tot++;
	}
	
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=num; j++)
		{
			tuf[j]=tuc[j];
		}
		t=tot;
		
		if (!t)
		{
			ans=0;
			break;
		}
		else
		{
			for (j=i; j<=n; j++)
		    {
			    tuf[con[j]]--;
			    if (tuf[con[j]]==1) t--;
			    if (!t) break;
		    }
		    
		    if (!t)
		    ans=min(ans,j-i+1);
		}
	}
	
	printf("%d",ans);
	
	return 0;
}