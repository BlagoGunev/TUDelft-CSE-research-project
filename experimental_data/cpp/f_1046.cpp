/*By DennyQi 2018*/
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define  r  read()
using namespace std;
typedef long long ll;
#define int ll
const int MAXN = 200010;
const int INF = 1061109567;
inline int Max(const int a, const int b){ return (a > b) ? a : b; }
inline int Min(const int a, const int b){ return (a < b) ? a : b; }
inline int read(){
    int x = 0; int w = 1; register char c = getchar();
    for(; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if(c == '-') w = -1, c = getchar();
    for(; c >= '0' && c <= '9'; c = getchar()) x = (x<<3) + (x<<1) + c - '0'; return x * w;
}
int N,x,f,ans;
int a[MAXN];
#undef int
int main(){
#define int ll
//	freopen(".in", "r", stdin);
	N = r;
	for(int i = 1; i <= N; ++i){
		a[i] = r;
	}
	x = r, f = r;
	for(int i = 1; i <= N; ++i){
		if(a[i] <= x) continue;
/*		if(a[i] < (x+f)){
			++ans;
			printf("+1\n");
			continue;
		}*/
		ans += a[i] / (x+f);
		if(a[i] % (x+f) > x){
			++ans;
		}
//			printf("+%d\n",(a[i] / (x+f)) + ((a[i] % (x+f))!=0));
/*		while(a[i] > x){
			a[i] -= x;
			a[i] -= f;
			++ans;
		}*/
	}
	printf("%I64d", ans * f);
	return 0;
}