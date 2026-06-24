#include<bits/stdc++.h>

using namespace std;

int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

#define N 300005

int T, n, a[N];

bool used[N];

int main()
{
	T = read();
	while(T--)
	{
		int n = read();
		for(int i = 0; i < n; i++)
		{
			a[i] = read();
			used[i] = 0;
		}
		bool flag = 1;
		for(int i = 0; i < n; i++)
		{
			int p = ((i + a[i]) % n + n) % n;
			if(used[p]) flag = 0;
			used[p] = 1;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}