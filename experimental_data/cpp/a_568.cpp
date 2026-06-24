#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1200000;
bool notprime[N];
bool hw[N];
int xu[15];
int getint()
{
	int res=0;
	char ch=getchar();
	while(ch<'0' || ch>'9')
		ch=getchar();
	while('0'<=ch && ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int main()
{
	int i,j;
	int p=getint();
	int q=getint();
	notprime[1]=1;
	for(i=2;i<N;i++)
	{
		if(!notprime[i] && i<10000)
		{
			for(j=i*i;j<N;j+=i)
				notprime[j]=1;
		}
	}
	for(i=1;i<N;i++)
	{
		xu[0]=0;
		j=i;
		while(j)
		{
			xu[++xu[0]]=j%10;
			j/=10;
		}
		for(j=1;j<=xu[0];j++)
		{
			if(xu[j]!=xu[xu[0]-j+1])
				break;
		}
		if(j<=xu[0])
			hw[i]=0;
		else
			hw[i]=1;
	}
	int ans=0;
	int totp=0,toth=0;
	for(i=1;i<N;i++)
	{
		if(!notprime[i])
			totp++;
		if(hw[i])
			toth++;
		if((long long)(totp)*q<=(long long)(p)*toth)
			ans=i;
	}
	printf("%d\n",ans);
	return 0;
}