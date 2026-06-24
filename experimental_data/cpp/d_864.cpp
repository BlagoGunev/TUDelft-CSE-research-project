#include<cstdio>
#include<iostream>

#define N 200010
#define For(a, b, c) for(int a = b; a <= c; ++a)
using namespace std;
int n, a[N], cnt[N], now, ans;
bool p[N];

inline int read(){
	int u = 0;
	char x = getchar();
	while(!isdigit(x)) x = getchar();
	while(isdigit(x)) u = (u << 3) + (u << 1) + (x ^ 48), x = getchar();
	return u;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("cf.in", "r", stdin);
	freopen("cf.out","w",stdout);
#endif
	n = read();
	For(i, 1, n){
		++cnt[a[i] = read()];
		if(cnt[a[i]] > 1) ++ans;
	}
	now = 1;
	For(i, 1, n){
		while(cnt[now]) ++now;
		if(cnt[a[i]] > 1){
			if(now < a[i] || p[a[i]]) --cnt[a[i]], ++cnt[a[i] = now];
			else p[a[i]] = 1;
		}
	}
	printf("%d\n", ans);
	For(i, 1, n) printf("%d ", a[i]);
	return 0;
}