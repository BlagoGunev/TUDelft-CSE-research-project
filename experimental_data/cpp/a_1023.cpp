#include<cstdio>
#include<cstring>
#define maxn 200005
using namespace std;

int n , m , ERROR=0 , tp = 0;
char s[maxn] , t[maxn];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='*') tp=1;
	if(tp)
	{
		if(m<n-1){ puts("NO");return 0; }
		int ft = 1 , ed = m;
		for(int i=1;i<=n && s[i]!='*';i++,ft++)
			if(s[i]!=t[i]) ERROR=1;
		for(int i=n;i>=1 && s[i]!='*';i--,ed--)
			if(s[i]!=t[m-(n-i)]) ERROR=1;
		if(ft > ed+1) ERROR=1;
		if(ERROR) puts("NO");
		else puts("YES");
	}
	else
	{
		if(m!=n){ puts("NO");return 0; }
		for(int i=1;i<=n ;i++)
			if(s[i]!=t[i]){ puts("NO");return 0; }
        puts("YES");
	}
}