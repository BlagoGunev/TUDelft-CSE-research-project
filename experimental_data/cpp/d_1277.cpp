#include <cstdio>
#include <cstring>
#define abs(a) (a<0?-(a):a)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

const int MAXN=20*10086,MAXM=400*10086;
struct node
{
	int s[2],id;
	void clean(){s[0]=s[1]=id=0;}
}t[MAXM];
char ch[MAXM];
int n,ntot,a[5],ty[MAXN],at,bt;
bool cr[MAXN];
void work()
{
	register int i,j,u,x;
	
	memset(a,0,sizeof(a));
	scanf("%d%*c",&n),at=bt=ntot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		x=strlen(ch+1);
		ty[i]=(ch[1]-'0')+((ch[x]-'0')<<1);
		for(j=x,u=0;j&&(j==x||u);j--)
		{
			u=t[u].s[ch[j]-'0'];
		}//printf("u=%d###\n",u);
		if(t[u].id)
		{
			cr[i]=1,cr[t[u].id]=1;//puts("awa");
			if(ty[i]==0||ty[i]==3)at++;
			else bt++;
		}
		for(j=1,u=0;j<=x;j++)
		{
			if(!t[u].s[ch[j]-'0'])t[u].s[ch[j]-'0']=++ntot;
			u=t[u].s[ch[j]-'0'];
		}//printf("u=%d###\n",u);
		t[u].id=i;
		a[ty[i]]++;
//		for(int i=0;i<=ntot;i++)printf("%d:(%d,%d):%d\n",i,t[i].s[0],t[i].s[1],t[i].id);
	}
//	printf("ntot=%d\n",ntot);
//	for(i=1;i<=n;i++)printf("%d:type=%d,cannotchange?=%d\n",i,ty[i],cr[i]);
	if(a[2]||a[1])
	{
		x=abs(a[2]-a[1])/2;
		if(max(a[1],a[2])-bt<x)puts("-1");
		else
		{
			printf("%d\n",x);
			for(i=1;x&&i<=n;i++)if((a[1]<a[2])==ty[i]-1&&!cr[i])
				x--,printf("%d ",i);puts("");
		}
	}
	else
	{
		if(a[0]*a[3]!=0)puts("-1");
		else puts("0");
	}
	for(i=0;i<=ntot;i++)t[i].clean();
	for(i=0;i<=n;i++)cr[i]=ty[i]=0;
}
int main()
{
	register int t;
	
	for(scanf("%d",&t);t--;work());
	return 0;
}