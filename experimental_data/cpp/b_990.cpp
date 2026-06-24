/****************
Keep your dreams.
	 by Darkness_
****************/

#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 200005
#define INF 0X3F3F3F3F
#define MOD 1000000007
#define QWQ puts("QWQ")

using namespace std;

int read(int &x) {
	x=0;
	int f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-')
			f=-f;
		if (ch==EOF)
			return -1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=x*10+ch-48;
		ch=getchar();
	}
	x*=f;
	return 0;
}

int n,k,ans,a[MAXN];

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	read(k);
	for (int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1);
	ans=n;
	int j=n-1;
	for (int i=n;i>=2;i--) {
		j=min(i-1,j);
		while (a[i]>a[j]&&a[i]<=a[j]+k&&j>=1) {
			ans--;
			j--;
		}
	}
	printf("%d\n",ans);
	return 0;
}