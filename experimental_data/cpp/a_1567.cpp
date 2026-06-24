#include<cstdio>
#include<algorithm>
#define MAXN 106
using namespace std;
char s[MAXN];
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='U') s[i]='D';
			else if(s[i]=='D') s[i]='U';
		printf("%s\n",s+1);
	}
}