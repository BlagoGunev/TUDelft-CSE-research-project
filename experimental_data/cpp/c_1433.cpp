#pragma warning(disable:4996)

#include<iostream>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_map>
#include<numeric>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<sstream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include <assert.h>
#define pb push_back
#define INF 0x3F3F3F3F //int 下较大值
#define inf 0x3F3F3F3F3F3F3F3F  // ll 下较大值 
#define moD 1000000003
#define pii pair<int,int>
#define eps 1e-10
#define equals(a,b) (fabs(a-b)<eps)
#define bug puts("bug")
#define re  register
#define fi first
#define se second
typedef  long long ll;
typedef unsigned long long ull;
const ll MOD = 998244353;
const ll Mod = 998244352;
const int maxn = 1e6 + 5;
const double Inf = 10000.0;
const double PI = acos(-1.0);
using namespace std;


int bitcount(int x) {
    return x == 0 ? 0 : bitcount(x / 2) + (x & 1);
}

int _popcount(int x) {
    int cnt = 0;
    for (int i = 0; i < 32; i++)
        if (x & (1 << i)) cnt++;
    return cnt;
}


ll mul(ll a, ll b, ll m) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res % m;
}

ll quickPower(ll a, ll b, ll m) {
    ll base = a;
    ll ans = 1ll;
    while (b) {
        if (b & 1) ans = mul(ans, base, m);
        base = mul(base, base, m);
        b >>= 1;
    }
    return ans;
}

ll ksm(ll a, ll b, ll m) {
    ll base = a % m;
    ll ans = 1ll;
    while (b) {
        if (b & 1) ans *= base, ans %= m;
        base *= base, base %= m;
        b >>= 1;
    }
    return ans;
}



ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll Lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int readint() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

ll readll() {
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

ull readull() {
    ull x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void Put(ll x) {
    if (x < 0) putchar('-'), x *= -1;
    if (x > 9) Put(x / 10);
    putchar(x % 10 + '0');
}

int a[300005];

void solve() {
    int n = readint();
    for (int i = 1; i <= n; i++)
        a[i] = readint();
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) cnt++;
    }
    if (cnt == n) {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) {
            if ((i - 1 && a[i] > a[i - 1]) || (i < n && a[i] > a[i + 1])) {
                printf("%d\n", i);
                break;
            }
        }
    }
}

int main() {
    int T = readint();
    while (T--)
        solve();
}