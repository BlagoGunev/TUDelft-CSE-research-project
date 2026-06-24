#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = a; i <= b; i ++)
#define REPG(i, x) for(int i = head[x]; i; i = g[i].nxt)

#define clr(x, y) memset(x, y, sizeof(x));

using namespace std;

typedef long long LL;
typedef double LF;

LL Max(LL a, LL b){return a > b ? a : b;}
LL Min(LL a, LL b){return a < b ? a : b;}
LL abs(LL x){return x > 0 ? x : -x;}

const int MAXN = 1e5 + 15;

int a[MAXN], b[MAXN], n, k;

inline int read(){
	int r = 0, z = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') z = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){r = r * 10 + ch - '0'; ch = getchar();}
	return r * z;
}

void work(){
	n = read(), k = read(); int tmp = 0, mx = 0, ans = 0;
	for(int i = 1; i <= n; i ++) a[i] = read();
	for(int i = 1; i <= n; i ++){b[i] = read(); ans += (b[i] ? a[i] : 0);}
	for(int i = 1; i < k; i ++) tmp += (b[i] ? 0 : a[i]);
	for(int i = k; i <= n; i ++){
		if(!b[i - k]) tmp -= a[i - k];
		if(!b[i]) tmp += a[i];
		mx = max(mx, tmp);
	} printf("%d\n", ans + mx);
}

int main(){
	work();
	return 0;
}