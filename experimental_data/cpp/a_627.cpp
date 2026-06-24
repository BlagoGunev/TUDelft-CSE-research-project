#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()

#define rep(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))

#define rev(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))

typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;

const int INF = INT_MAX/2, MOD = 1000000007, N = (int)2e5 + 10; const ll INFL = LLONG_MAX/2;

template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }

template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

ll s,x;

int main() {

#ifdef Srinu73

      freopen("in.txt","r",stdin);

#endif

      scanf("%lld%lld",&s,&x);

      ll tp = x;

      ll cnt = 0;

      ll cur = (s - x) / 2;

      if(cur*2LL + x != s || (cur&x) != 0 || x > s) {

            puts("0");

            return 0;

      }

      while(tp) {

            cnt += (1&tp);

            tp >>= 1;

      }

      ll ans = (1LL<<cnt);

      if(s == x) ans -= 2;

      printf("%lld\n",ans);

      return 0;

}