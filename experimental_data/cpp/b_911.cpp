#include<bits/stdc++.h>
using namespace std;
#define loop(I, N) for(int I = 1; I <= N; I++)
#define pool(I, N) for(int I = N; I >= 1; I--)
#define rep(I, N) for(int I = 0; I < N; I++)
#define per(I, N) for(int I = N - 1; I >= 0; I--)
#define FOR(I, L, R) for(int I = L; I <= R; I++)
#define FOD(I, R, L) for(int I = R; I >= L; I--)
#define SET(P, VAL) memset(P, VAL, sizeof(P));

#define reps(I, N, K) for(int I = 0; I < N; I += K)
#define loops(I, N, K) for(int I = 1; I <= N; I+= K)
#define pers(I, N, K) for(int I = N - 1; I >= 0; I -= K)
#define pools(I, N, K) for(int I = N; I >= 1; I -= K)
#define FORS(I, L, R, K) for(int I = L; I <= R; I += K)
#define FODS(I, L, R, K) for(int I = R; i >= L; I -= K)

int n, a, b, l = 1, r, mid;
int main() {
 scanf("%d%d%d", &n, &a, &b);
 pool(i, a + b) if(a / i + b / i >= n && b / i > 0 && a / i > 0) {
  printf("%d\n", i);
  return 0;
 }
 return 0;
}