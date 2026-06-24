#include<bits/stdc++.h>


using namespace std;


typedef long long int lli;
typedef long double ld;



const int MAXN = 82;
const int MAXM = (int)(1e5)+2;



int c[MAXN], r[MAXN];
int memo[MAXM];


int main() {

  int N, M;
  scanf("%d%d", &N, &M);

  
  for (int i = 1 ; i <= N ; i++) {
    scanf("%d%d", &c[i], &r[i]);
  }


  for (int m = M ; m >= 0 ; m--) {
    memo[m] = M-m+1;
    for (int i = 1 ; i <= N ; i++) {
      if (c[i] + r[i] >= m) {
        int cost = max(0, c[i]-r[i]-m);
        memo[m] = min(memo[m], cost + memo[min(c[i]+r[i]+cost+1, M+1)]);
      }
    }
    //cerr << "memo[" << m << "] = " << memo[m] << "\n";
  }

  printf("%d", memo[1]);



  return 0;
}