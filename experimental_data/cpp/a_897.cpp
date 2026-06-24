#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,len,l,r;
char s[105],c1,c2,tmp,tmp2;
void work()
{
	int i;
	for(i=l-1;i<r;i++)
	  if(s[i]==c1) s[i]=c2;
	return;
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	len=strlen(s);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%c%c%c%c",&l,&r,&tmp,&c1,&tmp2,&c2);
		work();
	}
	printf("%s",s);
	return 0;
}