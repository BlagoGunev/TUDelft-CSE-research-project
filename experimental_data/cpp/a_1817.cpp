#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010], b[200010];
int main()
{
   ios::sync_with_stdio(0);
   int n, q; cin >> n >> q;
   a[n+1] = 0x3f3f3f3f;
   for(int i = 1; i <= n; ++i)
      cin >> a[i];
   for(int i = 1; i <= n; ++i)
      if(a[i-1] >= a[i] && a[i] >= a[i+1])
         b[i] = true;
   for(int i = 1; i <= n; ++i)
      b[i] += b[i-1];
   while(q--)
   {
      int l, r; cin >> l >> r;
      if(r-l+1 <= 2) cout << r-l+1 << '\n';
      else cout << (r-l+1)-(b[r-1]-b[l]) << '\n';
   }
   return 0;
}