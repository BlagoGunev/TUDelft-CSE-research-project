// LUOGU_RID: 170937653
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

const int N = 4e5 + 5, inf = 1e8;

struct BasicSubstringStructure {
    int total;

    vector<int> H[N], L[N];
    int cnt[N];
    pr pos[N];

    struct SAM {
        struct node {
            int nxt[26], son[26];
            int len, link, posr, posl, cnt;
        } tr[N];

        node& operator [](int &x) {
            return tr[x];
        }

        vector<int> v[N];
        int id[N];
        int siz, lst, n;

        string s;

        void init() {
            siz = 1;
            lst = 0;
            tr[0].link = -1;
            tr[0].len = 0;
            tr[0].posl = inf;
        }

        void add(int x) {
            int cur = siz++;
            tr[cur].len = tr[lst].len + 1;
            int p = lst;
            while (p != -1 && !tr[p].nxt[x]) {
                tr[p].nxt[x] = cur;
                p = tr[p].link;
            }
            if (p == -1) {
                tr[cur].link = 0;
            }
            else {
                int q = tr[p].nxt[x];
                if (tr[q].len == tr[p].len + 1) {
                    tr[cur].link = q;
                }
                else {
                    int clone = siz++;
                    tr[clone].posl = inf;
                    tr[clone].len = tr[p].len + 1;
                    tr[clone].link = tr[q].link;
                    for (int i = 0; i < 26; i++) tr[clone].nxt[i] = tr[q].nxt[i];
                    while (p != -1 && tr[p].nxt[x] == q) {
                        tr[p].nxt[x] = clone;
                        p = tr[p].link;
                    }
                    tr[q].link = tr[cur].link = clone;
                }
            }
            lst = cur;
            tr[cur].posr = tr[cur].posl = tr[cur].len - 1;
            tr[cur].cnt = 1;
        }

        int Son(int ro, int len, int c) {
            if (tr[ro].len == len) return tr[ro].son[c];
            return ro;
        }

        void dfs(int ro) {
            for (auto u : v[ro]) {
                dfs(u);
                tr[ro].posr = max(tr[ro].posr, tr[u].posr);
                tr[ro].posl = min(tr[ro].posl, tr[u].posl);
                tr[ro].cnt += tr[u].cnt;
            }

            if (ro) {
                int fa = tr[ro].link;
                int x = s[tr[ro].posr - tr[fa].len] - 97;
                tr[fa].son[x] = ro;
            }
        }

        void init(string t) {
            s = t;
            n = s.size();
            init();
            for (int i = 0; i < s.size(); i++) {
                add(s[i] - 97);
            }
            for (int i = 1; i < siz; i++) {
                v[tr[i].link].pb(i);
            }
            dfs(0);
        }

        void update() {
            for (int i = siz - 1; i > 0; i--) {
                if (id[i]) continue;
                for (int j = 0; j < 26; j++) {
                    int x = tr[i].nxt[j];
                    if (!x) continue;
                    if (tr[x].len == tr[i].len + 1) id[i] = id[x];
                }
            }
        }
    } Tr1, Tr2;

    string s;
    int n;

    void Dfs(int ro, int Ro) {
        if (Tr1[ro].len == Tr2[Ro].len) {
            Tr1.id[ro] = Tr2.id[Ro] = ++total;
            cnt[total] = Tr1[ro].cnt;
            pos[total] = {n - 1 - Tr2[Ro].posr, Tr1[ro].posl};
        }

        for (int i = 0; i < 26; i++) {
            int x = Tr1[ro].nxt[i], y = Tr2.Son(Ro, Tr1[ro].len, i);
            if (Tr1[x].len == Tr1[ro].len + 1 && y) Dfs(x, y);
        }
    }

    void build(string t) {
        s = t;
        n = s.size();
        Tr1.init(s);
        reverse(s.begin(), s.end());
        Tr2.init(s);
        reverse(s.begin(), s.end());
        total = 0;
        Dfs(0, 0);
        Tr1.update();
        for (int i = 1; i < Tr1.siz; i++) {
            H[Tr1.id[i]].pb(Tr1[i].len - Tr1[Tr1[i].link].len);
        }
        Tr2.update();
        for (int i = 1; i < Tr2.siz; i++) {
            L[Tr2.id[i]].pb(Tr2[i].len - Tr2[Tr2[i].link].len);
        }
    }

    ll S[N];

    ll calc() {
        ll ans = 0, res = 0;
        for (int i = 1; i <= total; i++) {
            int m = H[i].size(), k = L[i].size();
            ll sum = 0;
            for (int j = 0; j < m; j++) {
                sum += H[i][j];
                S[j + pos[i].second - m + 1] = sum;
            }
            res += sum * cnt[i];
            for (int j = 0; j < k; j++) {
                int x = pos[i].first + k - 1 - j;
                if (x) ans += 1ll * S[min(x - 1, pos[i].second)] * L[i][j];
            }
            for (int j = 0; j < m; j++) {
                S[j + pos[i].second - m + 1] = 0;
            }
        }
        return ans;
    }
} A;

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    A.build(s);
    cout << A.calc() << '\n';
}