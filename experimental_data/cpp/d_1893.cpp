// LUOGU_RID: 155894598
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, m, tot;
int a[MAXN], s[MAXN], d[MAXN];
int cnt[MAXN], len[MAXN], id[MAXN];
int w[MAXN];

vector<int> ans[MAXN], col[MAXN];
priority_queue<pair<int, int>> q;

void init() {
    tot = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        ans[i].clear();
    }
    while (!q.empty()) q.pop();
}

void solve() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &d[i]);
        if (s[i] % d[i]) {
            len[++tot] = s[i] % d[i];
            ans[i].push_back(tot);
        }
        for (int j = 1; j <= s[i] / d[i]; j++) {
            len[++tot] = d[i];
            ans[i].push_back(tot);
        }
    }
    for (int i = 1; i <= tot; i++) {
        id[i] = i;
        col[i].clear();
    }
    sort(id + 1, id + tot + 1, [](int x, int y) {
        return len[x] > len[y];
    });
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) 
            q.push({cnt[i], i});
    }
    for (int i = 1; i <= tot; i++) {
        if ((int)q.size() < len[id[i]]) {
            puts("-1");
            return;
        }
        for (int j = 1; j <= len[id[i]]; j++) {
            auto [c, v] = q.top();
            q.pop();
            col[id[i]].push_back(v);
        }
        for (int x : col[id[i]]) {
            cnt[x]--;
            if (cnt[x]) q.push({cnt[x], x});
        }
    }
    for (int i = 1; i <= m; i++) {
        int lst = 0;
        for (int x : ans[i]) {
            if (!lst) {
                for (int v : col[x]) printf("%d ", v);
                lst = x;
                continue;
            }
            for (int v : col[x]) {
                w[v] = -1;
            }
            for (int j = 0; j < col[lst].size(); j++) {
                w[col[lst][j]] = j;
            }
            sort(col[x].begin(), col[x].end(), [](int a, int b) {
                return w[a] < w[b];
            });
            for (int v : col[x]) printf("%d ", v);
            lst = x;
        }
        puts("");
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    int T = 1;
    scanf("%d", &T);
    while (T--) solve();
}