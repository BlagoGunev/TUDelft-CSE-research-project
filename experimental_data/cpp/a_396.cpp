#include <bits/stdc++.h>

#include <ext/hash_map>

#include <ext/numeric>

using namespace std;

using namespace __gnu_cxx;



#define EPS      1e-9

#define F        first

#define S        second

#define pi       acos(-1)

#define ll       long long

#define oo       0x3f3f3f3f

#define sz(x)    (int)x.size()

#define sc(x)    scanf("%d",&x)

#define all(x)   x.begin(),x.end()

#define rall(x)  x.rbegin(),x.rend()



int n, a;

map<int, int> pCnt;

const int mod = 1000000007;

int fac[15050];



int pwr(int base, int pw) {

  int res = 1;

  while (pw) {

    if (pw & 1)

      res = (res * 1LL * base) % mod;

    base = (base * 1LL * base) % mod;

    pw >>= 1;

  }

  return res;

}



int nCr(int N, int R) {

  return (fac[N] * 1LL * pwr(fac[R], mod - 2) % mod * 1LL

      * pwr(fac[N - R], mod - 2)) % mod;

}



int main() {

#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin);

//freopen("output.txt", "w", stdout);

#endif

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {

    scanf("%d", &a);

    for (int j = 2; j * j <= a; j++) {

      while (a % j == 0)

        pCnt[j]++, a /= j;

    }

    if (a > 1)

      pCnt[a]++;

  }

  fac[0] = 1;

  for (int i = 1; i < 15050; i++)

    fac[i] = (fac[i - 1] * 1LL * i) % mod;

  int res = 1;

  for (map<int, int>::iterator it = pCnt.begin(); it != pCnt.end(); ++it)

    res = (res * 1LL * nCr(it->second + n - 1, it->second)) % mod;

  cout << res;

}