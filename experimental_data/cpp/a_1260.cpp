#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int n,c,s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c,&s);
		if(s<=c)printf("%d\n",s);
		else{
			int x=s/c,y=s%c;
			long long ans=1ll*x*x*(c-y)+1ll*(x+1)*(x+1)*y;
			printf("%lld\n",ans);
		}
	}
}