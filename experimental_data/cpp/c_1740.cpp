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
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &&x : v)
    cin >> x;
  sort(all(v));
  int ans=v[n-1]-v[0];
  for(int i=0;i<n;i++){
    int d1=max(v[n-1]-v[i],v[i]-v[0]);
    int d2=0;
    if(i!=0) d2=v[i]-v[i-1];
    if(i!=n-1) d2=max(d2,v[i+1]-v[i]);
    ans=max(ans,d1+d2);
  }
  ct(ans);
  //for(auto x:v) cout<<x<<' ';
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