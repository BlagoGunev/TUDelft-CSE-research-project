#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
#define FOR(i,j,k) for(register int i=j; i<=k; ++i)
#define ROF(i,j,k) for(register int i=j; i>=k; --i)
inline int read (void) {
	register int x = 0, f = 1, ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -f; ch = getchar(); }
	while(isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
// const int maxn = 105;
// int x[maxn], y[maxn], tp[maxn];
// inline bool check (int tota, int totb, int mid) {
// 	long long 
// }
int main (void) {
	int t = read();
	while(t--) {
		int n = read(), a = read(), b = read();
		if(a == 1) {
			if((n - 1) % b == 0) printf("Yes\n");
			else printf("No\n");
			continue;
		} else {
			long long A = 1;
			bool flag = 0;
			while(!flag && A <= n) {
				if((n - A) % b == 0) flag = 1;
				A *= a;
			}
			if(flag) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}