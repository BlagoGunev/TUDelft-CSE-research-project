#include "bits/stdc++.h"



#define fi first

#define se second

#define pb push_back

#define sz(x) (int)x.size()

#define all(x) (x).begin(),(x).end()



using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

template <class T> inline void maxi(T &x,T y) {if (y > x) x = y;}

template <class T> inline void mini(T &x,T y) {if (y < x) x = y;}



const int N = 5e2 + 5, B = 0x7fffffff;

int dp[N][N];

int a[N];

int n;



int main(){

  scanf("%d", &n);

  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++){

    for (int j = 1; j <= i; j++){

      dp[j][i] = dp[j][i - 1] + 1;

      for (int k = j; k < i; k++){

        if (a[k] == a[i]){

          mini(dp[j][i], dp[j][k - 1] + max(dp[k + 1][i - 1], 1));

        }

      }

    }

  }

  printf("%d\n", dp[1][n]);  

  return !!0;

}