#include <bits/stdc++.h>

using namespace std;
constexpr int N = 4e5 + 9, INF = 1e9;
int n, k, m, M;
set<pair<int, int>> pos;
multiset<int> val;
struct node {
int sm, mx;
friend node operator+(const node& a, const node& b) {
return {a.sm + b.sm, max(b.mx, a.mx + b.sm)};
}
} zkw[1 << 20];
void pushup(int x) { zkw[x] = zkw[x << 1] + zkw[x << 1 | 1]; }
void update(int x, int v) {
zkw[x += M].sm += v, zkw[x].mx += v;
while (x >>= 1) pushup(x);
}
int query(int l, int r) {
node L{0, -INF}, R{0, -INF};
for (l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
if (~l & 1) L = L + zkw[l ^ 1];
if (r & 1) R = zkw[r ^ 1] + R;
}
return (L + R).mx;
}
int main() {
cin.tie(nullptr)->sync_with_stdio(false);
cin >> n >> k >> m, M = 1 << (__lg(n + m) + 1);
for (int i = 1; i <= n + n; ++i) zkw[i + M] = {-1, -1};
for (int i = M - 1; i; --i) pushup(i);
for (int x, y, p, ans; m; --m) {
cin >> x >> y, p = y + abs(x - k);
auto it = pos.find({x, y});
if (it == pos.end())
pos.emplace(x, y), val.insert(p), update(p, 1);
else
pos.erase(it), val.erase(val.find(p)), update(p, -1);
if (ans = 0; !val.empty()) {
int w = max(*val.rbegin(), n);
ans = max(ans, w + query(1, w) - n);
}
cout << ans << '\n';
}
return cout << flush, 0;
}