#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if(c > a || c > b) {
    printf("-1\n");
    return 0;
  }

  int t = a - c + b - c + c;
  if(t > n) {
    printf("-1\n");
    return 0;
  }

  if(n - t < 1) {
    printf("-1\n");
    return 0;
  }

  printf("%d\n", n - t);
  return 0;
}