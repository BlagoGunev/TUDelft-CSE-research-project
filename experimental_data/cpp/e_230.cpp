// In the name of God
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const int maxN = 1000000 + 10;
ll n , m;
ll d[maxN];
ll ans;


void get()
{
  cin >> n >> m;
  for (int i=0 ; i<m ; i++)
    {
      int u , v;
      cin >> u >> v;
      d[u] ++ ;
      d[v] ++;
    }
  ans = n*(n-1) * (n-2) / 6;
}

void solve()
{
  ll q = m * (n-2);
  
  for (int i=1 ; i<= n ; i++)
    {
      q -= (d[i] * (d[i] -1)) / 2;
    }
  ans -= q;
}

int main()
{
  ios:: sync_with_stdio(false);
  get ();
  solve ();
  cout << ans << endl;
  return 0;
}