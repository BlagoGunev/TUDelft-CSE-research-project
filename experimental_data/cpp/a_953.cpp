#include <bits/stdc++.h>

using namespace std;

#define sz(c)  (int)((c).size())
#define all(c) ((c).begin()),((c).end())

typedef long long ll;
typedef pair<int, int> pii;

const int oo = (int)1e9+10;

int main()
{

 ll s, e;
 scanf("%lld %lld", &s, &e);

 int ans = 0;

 for (ll i = 1; i <= e; i *= 2)
  for (ll j = 1; j <= e; j *= 3)
   if (i*j >= s && i*j <= e)
    ++ans;

 printf("%d", ans);

 return 0;
}