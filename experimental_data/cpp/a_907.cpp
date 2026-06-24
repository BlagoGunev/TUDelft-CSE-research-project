#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;

int v[10],ans[10],l[10],r[10];

inline LL getint()
{
	LL ret = 0,f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
		ret = ret * 10 + c - '0',c = getchar();
	return ret * f;
}

int main()
{
	#ifdef AMC
		freopen("AMC1.txt","r",stdin);
	#endif
	for (int i = 1; i <= 4; i++) v[i] = getint();
	for (ans[1] = v[1]; ans[1] <= v[1] * 2; ans[1]++)
		for (ans[2] = v[2]; ans[2] <= v[2] * 2; ans[2]++)
			for (ans[3] = v[3]; ans[3] <= v[3] * 2; ans[3]++)
			{
				int tmp = 0;
				if (ans[1] <= ans[2] || ans[2] <= ans[3]) continue;
				for (int i = 1; i <= 3; i++)
					tmp += v[4] <= ans[i] && ans[i] <= 2 * v[4];
				if (tmp > 1 || !tmp) continue;
				if (!(v[4] <= ans[3] && ans[3] <= 2 * v[4])) continue;
				for (int i = 1; i <= 3; i++) printf("%d\n",ans[i]);
				return 0;
			}
	printf("-1");
	return 0;
}