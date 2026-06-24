#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
inline int read()
{
	int x = 0; bool op = 0;
	char c = getchar();
	while(!isdigit(c))op |= (c == '-'), c = getchar();
	while(isdigit(c))x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return op ? -x : x;
}

const int N = 55;
int n;
int w[N], f[N * 2], num[N];

int main()
{
	int t = read();
	while(t--)
	{
		memset(num, 0, sizeof(num));
		n = read();
		for(int i = 1; i <= n; i++)
		{
			int w = read();
			num[w]++;
		}
		int maxi = 0;
		for(int s = 2; s <= n * 2; s++)
		{
			int ans = 0;
			for(int i = 1; i <= s / 2; i++)
			{
				if(i * 2 == s)
					ans += num[i] / 2;
				else 
					ans += min(num[i], num[s - i]);
			}
			maxi = max(maxi, ans);
		}
		printf("%d\n", maxi);
	}
	return 0;
}
/*
1
9
1 2 3 4 5 6 7 8 9
*/