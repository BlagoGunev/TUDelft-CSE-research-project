#include<cstring>
#include<cstdio>
using namespace std;
int a[100010], b[100010];
int main()
{
	int n, l, r;
	while(~scanf("%d%d%d", &n, &l, &r))
	{
		for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
		for(int i=1;i<=n;i++)
		scanf("%d", &b[i]);
		
		bool flag = 1;
		for(int i=1;i<l;i++)
		if(a[i] != b[i])
		flag = 0;
		
		for(int i=r+1;i<=n;i++)
		if(a[i] != b[i])
		flag = 0;
		
		if(flag)
		printf("TRUTH\n");
		else 
		printf("LIE\n");
	}
	return 0;
}