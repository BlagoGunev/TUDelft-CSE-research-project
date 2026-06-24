#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
char s[N];
int n;
long long del[N], add[N][26];
struct ST {
    int logn[N], mi[21][N];
    void init(int* a, int n) {
        for (int i = 2; i <= n; i++) logn[i] = logn[i >> 1] + 1;
        for (int i = 1; i <= n; i++) mi[0][i] = a[i];
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                mi[j][i] = min(mi[j - 1][i], mi[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int rmq(int l, int r) {
        int k = logn[r - l + 1];
        return min(mi[k][l], mi[k][r - (1 << k) + 1]);
    }
};
struct SA {
    int id[N], c[N], sa[N], rk[N], ht[N];
    // sa[i] 表示排名为 i 的后缀 s[sa[i], n] 的原始位置 (sa[rk[i]] = i)
    // rk[i] 表示原始后缀 s[i, n] 在后缀数组中的排名 rk (rk[sa[i]] = i)
    // ht[i] 表示排名为 i 的后缀 s[sa[i], n] 与排名为 i-1 的后缀 s[sa[i-1], n] 的 LCP
    ST st;
    template <typename T>
    void getsa(T s, int n, int m = 100) {
        for (int i = 1; i <= n; ++i) rk[i] = s[i] - '0' + 1, id[i] = i;
        for (int i = 0; i <= m; ++i) c[i] = 0;
        for (int i = 1; i <= n; ++i) c[rk[i]]++;
        for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
        for (int i = n; i >= 1; --i) sa[c[rk[id[i]]]--] = id[i];
        for (int w = 1, p = 0; p < n; m = p, w <<= 1) {
            p = 0;
            for (int i = 1; i <= w; ++i) id[++p] = n - w + i;
            for (int i = 1; i <= n; ++i) if (sa[i] > w) id[++p] = sa[i] - w;
            for (int i = 0; i <= m; ++i) c[i] = 0;
            for (int i = 1; i <= n; ++i) c[rk[i]]++;
            for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
            for (int i = n; i >= 1; --i) sa[c[rk[id[i]]]--] = id[i];
            for (int i = 1; i <= n; ++i) id[i] = rk[i];
            rk[sa[1]] = p = 1;
            for (int i = 2; i <= n; ++i)
                rk[sa[i]] = (id[sa[i - 1]] == id[sa[i]] && id[sa[i - 1] + w] == id[sa[i] + w]) ? p : ++p;
        }
        for (int i = 1, k = 0; i <= n; ++i) {
            if (rk[i] == 0) continue;
            if (k) --k;
            while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
            ht[rk[i]] = k;
        }
        for (int i = 1; i <= n; ++i) id[i] = 0;
    }
    void debug(int n) {
        for (int i = 1; i <= n; ++i) {
            cout << "sa[" << i << "]=" << sa[i] << " rk[" << i << "]=" << rk[i] << " ht[" << i << "]=" << ht[i] << "\n";
        }
    }
    // 字符串 s 是以 1 下标开头的字符串，长度为 n
    template <typename T>
    void init(T s, int n, int m = 100) {
        getsa(s, n, m); // 求 sa，rk，height
        st.init(ht, n); // height 初始化 st 表
    }
    // 求任意两个后缀的 LCP：LCP(s[a, n], s[b, n])
    // LCP(LCP(s[l], s[l + 1]) ... LCP(s[r - 1], s[r]))
    // min(ht[l + 1] ... ht[r]) = rmq(l + 1, r)
    int lcp(int a, int b) {
        if (a > b)swap(a, b);
        if (a == 0 || b == 2 * n + 2)return 0;
        int l = rk[a], r = rk[b];
        if (l > r) swap(l, r);
        return st.rmq(l + 1, r);
    }
} sa;

vector<int> manacher(string& s) {

    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) r[i]++;

        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string t; cin >> n >> t;

    for (int i = 1; i <= n; i++)s[i] = s[2 * n + 2 - i] = t[i - 1];
    s[n + 1] = 'a' - 1;
    auto d = manacher(t);
    //cerr << s + 1 << endl;
    sa.init(s, 2 * n + 1);

    //#s[1]#s[2]
    for (int i = 0; i < d.size(); i++)
    {
        //右端点 (i+d[i]-1+1)/2
        //左端点 (i-d[i]+1)/2+1
        int l = (i - d[i] + 1) / 2 + 1, r = (i + d[i]) / 2;
        if (l > 1 && r < n) {
            int val = sa.lcp(r + 2, 2 * n - l + 4);
            add[l - 1][s[r + 1] - 'a'] += val + 1;
            add[r + 1][s[l - 1] - 'a'] += val + 1;
            //cout << l - 1 << ' ' << r + 1 << ' ' << val + 1 << endl;
        }
        if (l <= r) {

            del[l]++, del[(i + 1) / 2 + 1]--, del[i / 2 + 2]--, del[r + 2]++;
        }
    }

    for (int i = 1; i <= n; i++)del[i] += del[i - 1];
    for (int i = 1; i <= n; i++)del[i] += del[i - 1];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)if (j != s[i] - 'a')add[i][j] += d[2 * i - 1] / 2;

    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (s[i] - 'a' == j)continue;
            res = max(res, add[i][j] - del[i]);
        }
    }

    vector<array<int, 3>>v;
    bool ok = 0;

    for (int i = 1; i <= n && !ok; i++)
    {
        for (int j = 0; j < s[i] - 'a' && !ok; j++)
        {
            if (res == add[i][j] - del[i]) {
                s[i] = char(j + 'a'), ok = 1;
            }
        }
    }
    ///cout << add[6]['y' - 'a'] << endl;
    ok |= (res == 0);
    for (int i = n; i && !ok; i--)
    {
        for (int j = s[i] - 'a' + 1; j < 26 && !ok; j++)
        {
            if (res == add[i][j] - del[i]) {
                s[i] = char(j + 'a'), ok = 1;
                break;
            }
        }
    }

    string st;
    for (int i = 1; i <= n; i++)st += s[i];
    d = manacher(st);
    long long sum = 0;
    for (int i = 0; i < d.size(); i++)
    {
        //右端点 (i+d[i]-1+1)/2
        //左端点 (i-d[i]+1)/2+1
        int len = d[i] - 1;
        sum += (len + 1) / 2;
    }

    cout << sum << '\n';
    for (int i = 1; i <= n; i++)cout << s[i];
    return 0;
}