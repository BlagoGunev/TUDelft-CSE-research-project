#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <map>
#include <iterator>
#include <queue>
#include <cstring>
#include <set>
#include <stack>
#define mp make_pair
#define pb push_back
#define nfor(i, x, y) for (int i = x; i < y; i++)
#define si(n) scanf("%d", &n)
#define spii(n) scanf("%d%d", &n.first, &n.second)
#define sii(n, m) scanf("%d%d", &n, &m)
#define pi(n) printf("%d ", n)
#define sl(n) scanf("%I64d", &n)
#define pl(n) printf("%I64d", n)
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

const long long mod = 1000000007;
const int maxn = 1e5 + 1;
long long inf = 1LL << 60;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<int, bool> mib;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector <pii> vpii;

inline void read(int &n)
{
 int x = 0, f = 1; char ch = getchar();
 while (ch<'0' || ch>'9'){ if (ch == '-')f = -1; ch = getchar(); }
 while (ch >= '0'&&ch <= '9'){ x = 10 * x + ch - '0'; ch = getchar(); }
 n = x*f;
}
inline void read(ll &n)
{
 ll x = 0, f = 1; char ch = getchar();
 while (ch<'0' || ch>'9'){ if (ch == '-')f = -1; ch = getchar(); }
 while (ch >= '0'&&ch <= '9'){ x = 10ll * x + ch - '0'; ch = getchar(); }
 n = x*f;
}

int a[maxn];
int dp[maxn];
int rdp[maxn];

int main()
{
 ios_base::sync_with_stdio(0);
#ifdef _DEBUG
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
#endif
 int n;
 read(n);
 nfor(i, 1, n + 1)
 {
  read(a[i]);
 }
 dp[0] = 0;
 nfor(i, 1, n + 1)
 {
  dp[i] = min(dp[i - 1] + 1, a[i]);
 }
 rdp[n + 1] = 0;
 for (int i = n; i > 0; i--)
 {
  rdp[i] = min(rdp[i + 1] + 1, a[i]);
  dp[i] = min(dp[i], rdp[i + 1] + 1);
 }
 int ans = 0;
 nfor(i, 1, n + 1)
 {
  ans = max(ans, dp[i]);
 }
 pi(ans);
 return 0;
}