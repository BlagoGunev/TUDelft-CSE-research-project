#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 20;
long long k;
struct seg {
    int l, r;
};
int n;
long long f[N];
long long ans;
vector<pair<seg, seg> > sg;
bool isbit(long long x, int i) {
    if ((x & (1ll << i)) != 0) return true;
    return false;
}
vector<pair<seg, seg> > nsg;
void solve(int h) {
    if (h == -1) return;
    long long cur = 0;
    nsg.clear();
    for (auto it: sg) {
        int cnt1a = 0;
        for (int j = it.first.l; j <= it.first.r; j++)
            if (isbit(f[j], h)) cnt1a++;
        int cnt0a = it.first.r - it.first.l + 1 - cnt1a;
        int cnt1b = 0;
        for (int j = it.second.l; j <= it.second.r; j++)
            if (isbit(f[j], h)) cnt1b++;
        int cnt0b = it.second.r - it.second.l + 1 - cnt1b;
        cur += 1ll * cnt1a * cnt1b + 1ll * cnt0a * cnt0b;
    }
    if (cur < k) {
        ans += (1ll << h);
        k -= cur;
        for (auto it: sg) {
            int cnt1a = 0;
            for (int j = it.first.l; j <= it.first.r; j++)
                if (isbit(f[j], h)) cnt1a++;
            int cnt0a = it.first.r - it.first.l + 1 - cnt1a;
            int cnt1b = 0;
            for (int j = it.second.l; j <= it.second.r; j++)
                if (isbit(f[j], h)) cnt1b++;
            int cnt0b = it.second.r - it.second.l + 1 - cnt1b;
            if (cnt0a > 0 && cnt1b > 0) {
                nsg.push_back(make_pair((seg){it.first.l, it.first.l + cnt0a - 1}, (seg){it.second.r - cnt1b + 1, it.second.r}));
            }
            if (cnt1a > 0 && cnt0b > 0) {
                nsg.push_back(make_pair((seg){it.first.r - cnt1a + 1, it.first.r}, (seg){it.second.l, it.second.l + cnt0b - 1}));
            }
        }
    }
    else {
        for (auto it: sg) {
            int cnt1a = 0;
            for (int j = it.first.l; j <= it.first.r; j++)
                if (isbit(f[j], h)) cnt1a++;
            int cnt0a = it.first.r - it.first.l + 1 - cnt1a;
            int cnt1b = 0;
            for (int j = it.second.l; j <= it.second.r; j++)
                if (isbit(f[j], h)) cnt1b++;
            int cnt0b = it.second.r - it.second.l + 1 - cnt1b;
            if (cnt0a > 0 && cnt0b > 0) {
                nsg.push_back(make_pair((seg){it.first.l, it.first.l + cnt0a - 1}, (seg){it.second.l, it.second.l + cnt0b - 1}));
            }
            if (cnt1a > 0 && cnt1b > 0) {
                nsg.push_back(make_pair((seg){it.first.r - cnt1a + 1, it.first.r}, (seg){it.second.r - cnt1b + 1, it.second.r}));
            }
        }
    }
    sg = nsg;
    solve(h - 1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int p;
        long long z;
        cin >> p >> z;
        f[i] = f[p] ^ z;
    }
    sort(f + 1, f + n + 1);
    sg.push_back(make_pair((seg){1, n}, (seg){1, n}));
    solve(61);
    cout << ans << "\n";
    return 0;
}