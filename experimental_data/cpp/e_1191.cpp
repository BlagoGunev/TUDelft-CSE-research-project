#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,i,vf,mi[2],mx[2],u,v;
char s[100005];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	n=strlen(s);mi[0]=mi[1]=1000000000;
	for(i=0;i<n;i++)
	{
		vf=s[i]-'0';
		if(mi[vf]==1000000000)mi[vf]=i;
		mx[vf]=i;
		//printf("%d %d %d %d\n",mi[0],mi[1],mx[0],mx[1]);
	}
	u=mx[0]-mi[0]+1;
	v=mx[1]-mi[1]+1;
	//printf("%d %d\n",u,v);
	if(u<=k||v<=k)
	{
		printf("tokitsukaze\n");
		return 0;
	}
	if(s[0]==s[n-1])
	{
		printf("once again\n");
		return 0;
	}
	if(u>k+1||v>k+1)
	{
		printf("once again\n");
		return 0;
	}
	if(2*k+2==n)
	{
		printf("once again\n");
		return 0;
	}
	printf("quailty\n");
	return 0;
}