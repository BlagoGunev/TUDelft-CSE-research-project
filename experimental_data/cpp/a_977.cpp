#include<cstdio>
#define maxn 200005
using namespace std;
int n,s;
int main()
{
	scanf("%d%d",&n,&s);
	while(s--)
	{
		if(n%10)n--;
		else n/=10;
	}
	printf("%d",n);
	return 0;
}