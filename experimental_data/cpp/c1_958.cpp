#include<cstdio>
#define Rint register int
#define MAXN 100001
using namespace std;
int n, p, a[MAXN], ans;
inline int max(int a, int b){
	return a < b ? b : a;
}
int main(){
	scanf("%d%d", &n, &p);
	for(Rint i = 1;i <= n;i ++){
		scanf("%d", a + i);
		a[i] = (a[i] + a[i - 1]) % p;
	}
	for(Rint i = 1;i < n;i ++)
		ans = max(ans, a[i] + (a[n] + p - a[i]) % p);
	printf("%d", ans);
}