#include <bits/stdc++.h>
using namespace std;
int cases(1),t;
using ull = unsigned long long;
#define File(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout)
#define expose(a) for (auto e:a) cout << e << " "; cout << "\n";
#define IOS ios_base::sync_with_stdio(false); cin.tie (0); cout.tie(0);
#define full(x) x.begin(), x.end()
#define hello(x) cout << "THIS IS TEST: "<<x<<"\n";
#define test(x) if (cases == x)
#define fi first
#define int long long
#define se second
#define debugM(x,n,m) cout << "This is Matrix: " << #x << '\n'; for (int i = 0;i < n;i++) {for (int j = 0;j < m;j++) cout << x[i][j] << ' '; cout << '\n';}
#define debugE(x) cout << #x << ":"<<x<<" occur as you guest\n";
#define debug4(x,y,z,t) cout << #x << ": " << x << "   " << #y << ": " << y << "   " << #z << ": " << z << "   " <<  #t << ": " << t; cout << "\n";
#define debug3(x,y,z) cout << #x << ": " << x << "   " << #y << ": " << y << "   " << #z << ": " << z; cout << "\n";
#define debug(x) cout << #x <<": " << x << "\n";
#define debugA(a) for (int i = 0; i < a.size();i++) cout << #a << "["<<i<<"]" << "=" << a[i] << "\t"; cout << "\n";
#define debug2(x,y) cout << #x << ": " << x << "    " << #y << ": " << y << '\n';
#define debugAP(a) for (int i = 0;i < S(a);i++) cout << #a << "["<<i<<"].first: " << a[i].first << "   "; cout <<'\n'; for (int i = 0;i < S(a);i++) cout << #a << "["<<i<<"].second: " << a[i].second << "   "; cout <<'\n';
signed main () {
  IOS;
  for (cin >> t;cases <= t;++cases) {
       int xA,xB,yA,yB,xF,yF;
       cin >> xA >> yA >> xB >> yB >> xF >> yF;
       int c = 0;
       if (xA == xF && xF == xB && ((yF > yA && yF < yB)||(yF > yB && yF < yA))) c = 2;
       else if (yA == yF && yF == yB && ((xF > xA && xF < xB) || (xF > xB && xF < xA))) c = 2;
       cout << abs(xA - xB) + abs(yA - yB) + c<< '\n';
  }
  return 0;
}