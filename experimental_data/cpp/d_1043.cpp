#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int a[12][N],to[12][N],Rank[N];
bool vis[N];
inline int read() {
	int x=0;
	char e=getchar();
	for (; e<'0'||e>'9'; e=getchar());
	for (; e>='0'&&e<='9'; e=getchar()) x=(x<<1)+(x<<3)+(e^48);
	return x;
}
int n,m;
inline bool check(int x) {
	for (int j=2; j<=m; j++)
		if (a[j][to[j][x]+1]==0||a[j-1][to[j-1][x]+1]==0||a[j][to[j][x]+1]!=a[j-1][to[j-1][x]+1]) return false;
	return true;
}
int main () {
	n=read(),m=read();
	for (int j=1; j<=m; j++)
		for (int i=1; i<=n; i++)
			a[j][i]=read(),to[j][a[j][i]]=i;
	long long ans=0;
	for (int i=1; i<=n; i++) {
		if (vis[i]) continue;
		int now=i,cnt=1;
		while (now<=n&&!vis[now]) {
			vis[now]=true;
			if (!check(a[1][now])) break;
			now++;
			if (now<=n) cnt++;
		}
		ans+=1ll*cnt*(cnt+1)>>1;
	}
	printf ("%I64d",ans);
	return 0;
}