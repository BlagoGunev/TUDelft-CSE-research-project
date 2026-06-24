#include <cstdio>
#include <cstring> 
#include <algorithm>

using namespace std;

const int maxn=1e5+1e2;

bool isprime[maxn];
int prime[maxn],primesize=0,a[maxn],cnt[maxn]={0};

void getpri(int listsize)
{
	memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])prime[++primesize]=i;
        for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
        {
	        isprime[i*prime[j]]=false;
	        if(i%prime[j]==0)break;
       }
    }
}

int getint()
{
	char ch;int b=1;
	for(ch=getchar();ch>'9'||ch<'0';ch=getchar())if(ch=='-')b=-1;
	int num=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar())num=num*10+ch-'0';
	return num*b;
}

int main()
{
	int n=getint();
	int up=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=getint();
		up=max(up,a[i]);
	}
	getpri(up);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=primesize;j++)
		{
			if(a[i]%prime[j]==0)cnt[prime[j]]++;
			while(a[i]%prime[j]==0)
			{
				a[i]/=prime[j];
			}
			if(a[i]==1)break;
			if(isprime[a[i]])break;
		}
		cnt[a[i]]++;
	}
	int ans=1;
	for(int i=2;i<=up;i++)
	{
		if(isprime[i])ans=max(ans,cnt[i]);
	}
	printf("%d\n",ans);
	return 0;
}