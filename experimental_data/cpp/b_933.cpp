#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define rep(i, a, b) for (int (i)=(0);(i)<(n);(i)++)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()

typedef long long ll;

void print(vector<int> v) {
 for (int x: v) printf("%d ", x); printf("\n");
}



int main() {
 ll n, k;
 scanf("%lld %lld", &n, &k);
 k *= -1;
 vi a;
 while (n != 0) {
  ll val = n % k;
  // printf("n = %lld, val = %lld\n", n, val);
  n /= k;
  if (val < 0) n++, val += -k;
  a.pb(val);
 }
 printf("%d\n", SZ(a));
 // reverse(all(a));
 print(a);
 return 0;
}