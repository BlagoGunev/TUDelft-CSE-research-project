#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<set>
#include<cmath>
#include<map>
#include<list>
#include<stack>
#include<fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define int long long
const int _ = 4e5 + 7;
//const int INF = (1 << 31) - 1;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const double PI = acos(-1);
#define _for(i,l,r) for(int i=l;i<=r;++i)
#define _rfor(i,r,l) for(int i=r;i>=l;--i)
#define all(x) (x).begin(),(x).end()
template<typename T>
void rd(T& res) {
    res = 0; int f = 1; char ch;
    ch = cin.get();
    while (ch < '0' || ch > '9') { if (ch == '-')f = -1; ch = cin.get(); }
    while (ch >= '0' && ch <= '9') { res = (res << 1) + (res << 3) + (ch ^ 48); ch = cin.get(); }
    res *= f;
}
inline ll ksm(ll a, ll p) { ll res = 1; while (p) { if (p & 1)res *= a; a *= a; p >>= 1; res %= MOD; a %= MOD; }return res; }
ll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a % b); }
int A[_], B[_];
int has[_];
void work() {
    int n; rd(n);
    _for(i, 1, n)rd(A[i]), has[A[i]] = i;
    _for(i, 1, n)rd(B[i]), has[B[i]] = i;
    int ans = INF;
    for (int i = 2; i <= 2 * n; i += 2) {
        if (i - 3 >= 1)
            has[i - 1] = min(has[i - 1], has[i - 3]);
        ans = min(ans, has[i - 1] + has[i] - 2);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; rd(T);
    for (int i = 1; i <= T; ++i) {
        //cout << "Case #" << i << ":\n";
        work();
    }
}