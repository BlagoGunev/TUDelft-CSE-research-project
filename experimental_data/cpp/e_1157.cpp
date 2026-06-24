#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctype.h>
#include<cstring>
#include<queue>
#include<map>
#include<iostream>
#include<iterator>
#define INF 0x3f3f3f3f
  
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int maxn = 200100;
int a[maxn], b[maxn], c[maxn], d[maxn], e[maxn];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d", &b[i]);
		d[i] = (i+1)%n;
	}
	sort(b, b+n);
	memset(e, 0, sizeof(e));
	for(i=0;i<n;i++)
	{
		j = (n - a[i]%n)%n;
		int k = lower_bound(b, b+n, j)-b;
		if(k == n)k = 0;
		int kk = k; 
		while(e[k] == 1)
			k = d[k];
		c[i] = (a[i] + b[k]) % n;
		d[kk] = d[k];
		e[k] = 1;
	}
	printf("%d", c[0]);
	for(i=1;i<n;i++)
		printf(" %d", c[i]);
	return 0;
}