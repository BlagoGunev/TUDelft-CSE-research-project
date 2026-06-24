#include<cstdio>
#include<cstring>
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
int read()
{
	int x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch&15);
		ch=gc();
	}
	return x*f;
}
int s[500100],sz[500100];
int Find(int x)
{
	if(s[x]==x)
		return x;
	return s[x]=Find(s[x]);
}
void Union(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y)
		return;
	sz[x]+=sz[y];
	s[y]=x;
}
int main()
{
#ifdef wjyyy
	freopen("a.in","r",stdin);
#endif
	int n=read();
	int m=read(),k,u,lst;
	for(int i=1;i<=n;++i)
		s[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i)
	{
		k=read();
		lst=0;
		for(int j=1;j<=k;++j)
		{
			u=read();
			if(lst)
				Union(lst,u);
			lst=u;
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d ",sz[Find(i)]);
	return 0;
}