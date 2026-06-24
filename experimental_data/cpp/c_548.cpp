#include <cstring>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iomanip>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v)                                        \
  for (int X = 0; X < v.size(); X++) cout << v[X] << " "; \
  cout << endl;
#define grid(v)                                                   \
  for (int X = 0; X < v.size(); X++) {                            \
    for (int Y = 0; Y < v[X].size(); Y++) cout << v[X][Y] << " "; \
    cout << endl;                                                 \
  }
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef vector<vector<ii> > vvii;
const int MOD = 1e9 + 7;
int m;
ii calc(ll x, ll h, ll y, ll a)
{
  ii info;
  info.first = -1;
  info.second = -1;
  for (int i = 1; i <= m; i++) {
    h = (h * x + y) % m;
    if (h == a) {
      info.first = i;
      break;
    }
  }
  if (info.first == -1) return info;
  for (int i = 1; i <= m; i++) {
    h = (h * x + y) % m;
    if (h == a) {
      info.second = i;
      break;
    }
  }
  return info;
}
//A.second <- sair de a e voltar pra a;
//A.first <- sair do estado inicial a chegar no estado a;
//automatos :) 
void solve()
{
  ll h1, a1, x1, y1, h2, a2, x2, y2;
  cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
  ii A1 = calc(x1, h1, y1, a1);
  ii A2 = calc(x2, h2, y2, a2);
  if (A1.first == -1 or A2.first==-1) {
    puts("-1");
    return;
  }
  bool flag = false;
  for (int i = 1; i <= 2 * m; i++) {
    if (A1.first == A2.first) {
      cout << A1.first << endl;
      return;
    }
    else if (A1.first > A2.first) {
      A2.first += A2.second;
    }
    else {
      A1.first += A1.second;
    }
  }
  puts("-1");
}
int main()
{
  solve();
  return 0;
}