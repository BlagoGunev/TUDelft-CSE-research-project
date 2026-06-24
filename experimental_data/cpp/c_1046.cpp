/*By DennyQi 2018*/
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define  r  read()
using namespace std;
typedef long long ll;
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
int N,D,Ans,st;
int s[MAXN],p[MAXN];
inline bool judge(int k){
//	printf("k = %d\n",k);
	int res = D, u=2;
	for(int i = D-1; i > 0; --i){
		while(s[i] + p[u] > s[D] + p[1] && u <= N){
			++u;
		}
		if(u > N) break;
//		printf("s[%d] <-> p[%d]\n",i,u);
		--res;
		++u;
		if(res <= k) return 1;
	}
	return 0;
}
int main(){
//	freopen(".in","r",stdin);
	N = r, D = r;
	if(D == 1){
		printf("1");
		return 0;
	}
	for(int i = 1; i <= N; ++i){
		s[i] = r;
	}
	for(int i = 1; i <= N; ++i){
		p[i] = r;
	}
/*	for(int i = 2; i <= N; ++i){
		if(s[D-1] + p[i] <= s[D] + p[1]){
			st = i;
			break;
		}
	}*/
	Ans = D;
	int L = 1, R = N, Mid;
	while(L <= R){
		Mid = (L + R) / 2;
		if(judge(Mid)){
			R = Mid - 1;
			Ans = Mid;
		}
		else{
			L = Mid + 1;
		}
	}
	printf("%d", Ans);
	return 0;
}