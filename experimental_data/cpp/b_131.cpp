#include <cstdio>
#include <cstring>
#define LL long long


// -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0  1  2  3  4  5  6  7  8  9  10
// 1   2  3  4  5   6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21
LL cont[31];
int n;

void init()
{
	memset(cont,0,sizeof(cont));
	int i;
	int t;
	for(i = 1;i <= n;i ++)
	{
		scanf("%d",&t);
		cont[t+11] ++;
	}
}

void work()
{
	LL ans = 0;
	LL t;
	int i;
	for(i = 1;i <= 10;i ++)
	{
		t = cont[i] * cont[22 - i];
		ans += t;
//		printf("%lld\n",t);
	}
	
	ans += (cont[11] * (cont[11] - 1)) / 2;
	printf("%I64d\n",ans);
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		init();
		work();
	}	

	return 0;
}