// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//

#include<iostream>

#include<unordered_map>

#include<algorithm>

#include<iomanip>

#include<sstream>

#include<cstring>

#include<string>

#include<vector>

#include<deque>

#include<queue>

#include<cmath>

#include<stack>

#include<map>

#include<set>

#define ul unsigned long long

#define ll long long

using namespace std;

//欧拉筛

vector<ll>PRIME;//存储素数

bool VIS[100005];//标记不是素数的值

inline void euler() {

    memset(VIS, 0, sizeof(VIS));

    VIS[1] = 1;

    for (ll i = 2; i <= 100000; i++) {

        if (!VIS[i])PRIME.push_back(i);

        for (unsigned int j = 0; i * PRIME[j] <= 100000; j++) {

            VIS[i * PRIME[j]] = 1;

            if (i % PRIME[j] == 0)break;

        }

    }

}

//非递归gcd

ll gcd_(ll n, ll m) {

    while (n ^= m ^= n ^= m %= n);

    return m;

}

//快速幂运算

ll MOD = 1000000007;

inline ll qmi(ll x, ll y) {

    ll ans = 1;

    while (y) {

        if (y & 1)ans = (ans * x) % MOD;

        x = (x * x) % MOD;

        y >>= 1;

    }

    return ans;

}

//组合数

ll jie[200005], inv[200005];

void get_jie() {

    jie[0] = 1;

    for (int i = 1; i <= 200003; i++)jie[i] = (jie[i - 1] * i) % MOD;

    return;

}

void get_inv() {

    inv[200003] = qmi(jie[200003], MOD - 2);

    for (int i = 200002; i >= 0; i--)inv[i] = (inv[i + 1] * (i + 1)) % MOD;

    return;

}

ll C(int m, int n) {

    if (m < 0 || n < 0 || m < n)return 0;

    ll ans = 0;

    ans = jie[m] * inv[n] % MOD * inv[m - n] % MOD;

    return ans;

}

//快读 

inline int read()

{

    int w = 1, a = 0;

    char ch = getchar();

    while (ch < '0' || ch>'9') { if (ch == '-')w = -1; ch = getchar(); }

    while (ch >= '0' && ch <= '9') { a = a * 10 + ch - '0'; ch = getchar(); }

    return w * a;

}

int fa[2005];

int fin(int x) {

    if (fa[x] == x || fa[x] == -1)return x;

    fa[x] = fin(fa[x]);

    return fa[x];

}

int n;

vector<ll>rec;

int mlb[2005];

bool ct;

bool check() {

    memset(fa, -1, sizeof(fa));

    for (int i = 0; i <= 31; i++) {

        int last = -1;

        for (int j = 0; j < n; j++) {

            if ((1ll << i) & rec[j]) {

                if (ct && mlb[j] == -1)mlb[j] = i;

                if (last == -1)last = j;

                else {

                    if (fin(j) != fin(last))fa[fin(j)] = fin(last);

                }

            }

        }

    }

    for (int i = 1; i < n; i++) {

        if (fin(i) != fin(0))return false;

    }

    return true;

}

int main() {

    std::ios::sync_with_stdio(false);//这个和上面的read函数只能用其中一个！！！

    cin.tie(0);

    int _;

    cin >> _;

    //_ = 1;

    while (_--) {

        cin >> n;

        rec.clear();

        memset(mlb, -1, sizeof(mlb));

        ct = true;

        int ans = 0;

        ll a;

        for (int i = 0; i < n; i++) {

            cin >> a;

            if (a == 0)ans++, a = 1;

            rec.push_back(a);

        }

        if (check()) {

            cout << ans << "\n";

            for (int i = 0; i < n; i++) {

                if (i != 0)cout << " ";

                cout << rec[i];

            }

            cout << "\n";

            continue;

        }

        ct = false;

        int mmlb = -1;

        for (int i = 0; i < n; i++) {

            mmlb = max(mmlb, mlb[i]);

        }

        int coun = 0;

        if (coun == 1) {

            cout << ans + 1 << "\n";

            for (int i = 0; i < n; i++) {

                if (i != 0)cout << " ";

                if (mlb[i] == mmlb)cout << rec[i] - 1;

                else cout << rec[i];

            }

            cout << "\n";

            continue;

        }

        bool cc = false;

        for (int i = 0; i < n; i++) {

            rec[i]--;

            if (mlb[i]==mmlb&&check()) {

                cc = true;

                break;

            }

            rec[i] += 2;;

            if (check()) {

                cc = true;

                break;

            }

            rec[i]--;

        }

        if (cc) {

            cout << ans + 1 << "\n";

            for (int i = 0; i < n; i++) {

                if (i != 0)cout << " ";

                cout << rec[i];

            }

            cout << "\n";

            continue;

        }

        cout << ans + 2 << "\n";

        int gg = 0;

        for (int i = 0; i < n; i++) {

            if (i != 0)cout << " ";

            if (mlb[i] == mmlb) {

                gg++;

                if (gg == 1)cout << rec[i] - 1;

                else if (gg == 2)cout << rec[i] + 1;

                else cout << rec[i];

            }

            else cout << rec[i];

        }

        cout << "\n";

    }

}