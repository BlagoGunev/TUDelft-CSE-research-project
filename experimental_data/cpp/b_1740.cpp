#include <bits/stdc++.h>

using namespace std;

/*固定型define*/
#define case (num) printf("Case #%lld: ", ++num)
#define IOS                    \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0)

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define mem(s) memset(s, 0, sizeof(s))
#define endl '\n'
#define reset(a, b) memset(a, b, sizeof(a))
#define all(x) (x).begin(), (x).end()
#define fout freopen("output.txt", "w", stdout)
#define dg(x) cout << #x << "=" << x << endl
#define dd cout << "do" << endl;
#define PAII pair<int, int>

/*调节型define*/
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define int long long
#define inf 0x3f3f3f3f
#define bob cout << "Bob" << endl;
#define ass cout << "Alice" << endl;
#define ct(x) cout << x << endl
#define double long double
#define N 350000

typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

void solve()
{
  int ans=0;
   int n;cin>>n;
   vector<PAII>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
    if(v[i].first<v[i].second)
    swap(v[i].first,v[i].second);
    ans+=v[i].second;
   }
   sort(all(v),greater<PAII>());
   ans+=v[0].first;
   ct(ans*2);


}

signed main()
{
  IOS;

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
  }
  return 0;
}