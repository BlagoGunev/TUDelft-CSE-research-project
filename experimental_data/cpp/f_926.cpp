#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
#define mp make_pair
#define pb push_back

using namespace std;

int main() 
{
 int n;
 long long p, m;
 scanf("%d%lld%lld", &n, &p, &m);
 long long curd = 1;
 long long curb = 0;
 long long sum = 0;
 for (int i = 0; i<n; ++i) {
  long long d, v;
  scanf("%lld%lld", &d, &v);
  long long tpos = 0;
  if (curb > 0)
   tpos = curb/p;
  //cerr << "tpos " << tpos << '\n';
  if (curd + tpos < d) {
   //cerr << d << ' ' << curd << '\n';
   sum+= d-curd-tpos;
   //cerr << "sum " << sum << '\n';
  }
  curb = curb - (d-curd)*p + v;
  curd = d;
  //cerr << "curb " << curb << '\n';
 }
 long long tpos = 0;
 if (curb > 0)
  tpos = curb/p;
 if (curd + tpos <= m) {
  sum+= m+1-curd-tpos;
 }
 printf("%lld\n", sum);
 return 0;
}