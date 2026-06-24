#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cstdlib>
#define MOD1 1000000007
#define MOD2 1000000009
#define MOD  1000000007
#define L1   23
#define L2   29
#define MAXN 1000005
using namespace std;

typedef long long int LL;
int N, M, K, A[MAXN];
char S[MAXN];
LL F1[MAXN], F2[MAXN], B1[MAXN], B2[MAXN];

LL exp(LL p, LL v) {
  if (p == 0) return 1;
  if ( (p%2ll == 1) ) return (v * exp(p-1,v)) % MOD;
  return exp(p/2ll,(v*v)%MOD);
}

bool can(int x,int y) {
  if (y - x >= K) return true;
  else return B1[y-x+1] == F1[K-y+x] && B2[y-x+1] == F2[K-y+x];
}

void print(LL X[]) {
  for (int i=1;i<=K;++i) cout << X[i] << " "; cout << endl;
}

int main () {
  scanf("%d%d %s",&N,&M,S+1);
  K = strlen(S+1);
  for (int i=0;i<M;++i) scanf("%d",&A[i]);
  A[M++] = N+1;
  for (int i=1;i<=K;++i) {
    F1[i] = (F1[i-1] * L1 + S[i]) % MOD1;
    F2[i] = (F2[i-1] * L2 + S[i]) % MOD2;
  }
  LL t1 = 1, t2 = 1;
  for (int i=K;i>=1;--i) {
    B1[i] = (t1 * S[i] + B1[i+1]) % MOD1;
    B2[i] = (t2 * S[i] + B2[i+1]) % MOD2;
    t1 = (t1 * L1) % MOD1;
    t2 = (t2 * L2) % MOD2;
  }
  //print(F1); print(B1); print(F2); print(B2);
  for (int i=1;i<M;++i)
    if (!can(A[i-1],A[i])) {
      printf("0\n");
      return 0;
    }
  LL ans = exp(A[0]-1,26);
  for (int i=1;i<M;++i)
    if (A[i] - A[i-1] > K) {
   //   printf("check %d, %lld\n",A[i]-A[i-1]-K,exp(A[i]-A[i-1] - K,26));
      ans = (ans * exp(A[i]-A[i-1] - K,26)) % MOD;
    }
  cout << ans << endl;
}