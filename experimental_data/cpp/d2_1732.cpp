// LUOGU_RID: 99993362
/**
 * @file:           codeforces
 * @author:         yaoxi
 * @time:           
*/
// #pragma GCC optimize ("O2")
// #pragma GCC optimize ("Ofast", "inline", "-ffast-math")
// #pragma GCC target ("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
using namespace std;
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
#define debug(fmt, ...) \
    fprintf(stderr, "[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
template <class _Tp>
inline _Tp& read(_Tp& x) {
    bool sign = false; char ch = getchar(); double tmp = 1.0;
    for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
    for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
    if (ch == '.') for (ch = getchar(); isdigit(ch); ch = getchar())
        tmp /= 10.0, x += tmp * (ch ^ 48);
    return sign ? (x = -x) : x;
}
template <class _Tp>
inline void write(_Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar((x % 10) ^ 48);
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define testcases int cas; read(cas); while (cas--)
#define skipcase(...) { __VA_ARGS__; continue; }
int q;
unordered_set<ll, custom_hash> st;
unordered_map<ll, ll, custom_hash> ans;
unordered_map<ll, set<ll>, custom_hash> ers;
unordered_map<ll, vector<ll>, custom_hash> use;
signed main() {
    read(q);
    st.insert(0);
    st.reserve(q), ans.reserve(q), ers.reserve(q), use.reserve(q);
    while (q--) {
        char buf[5]; ll x;
        scanf("%s%lld", buf, &x);
        if (buf[0] == '+') {
            st.insert(x);
            if (use.find(x) == use.end()) continue;
            for (auto p : use[x]) ers[p].erase(x);
        } else if (buf[0] == '-') {
            st.erase(x);
            if (use.find(x) == use.end()) continue;
            for (auto p : use[x]) ers[p].insert(x);
        } else {
            ll cur = ans[x];
            if (ers.find(x) != ers.end() && !ers[x].empty()) {
                printf("%lld\n", *ers[x].begin());
            } else {
                while (st.find(cur) != st.end())
                    use[cur].push_back(x), cur += x;
                printf("%lld\n", ans[x] = cur);
            }
        }
    }
    return 0;
}