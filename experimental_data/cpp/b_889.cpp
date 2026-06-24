#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int adj[30][30], in[30], out[30];

bool vis[30], need[30], cycle;
string chain;
void dfs(int u) {
    if (vis[u]) {
        cycle = 1;
        return;
    }
    vis[u] = 1;
    chain += char('a'+u);
    forn(v,30) if (adj[u][v]) dfs(v);
}

void no() {
    cout << "NO\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        for (char c : s) need[c-'a'] = 1;
        forn(i,si(s)-1) {
            int u = s[i]-'a', v = s[i+1]-'a';
            if (!adj[u][v]) {
                adj[u][v]++;
                out[u]++;
                in[v]++;
            }
        }
    }

    bool ok = 1;
    forn(u,30) ok &= (in[u] <= 1 && out[u] <= 1);
    if (!ok) no();

    vector<string> ans;
    forn(u,30) if (!in[u] && need[u]) {
        chain = ""; cycle = 0;
        dfs(u);
        ans.pb(chain);
    }

    forn(u,30) if (!vis[u] && need[u]) ok = 0;
    if (!ok) no();

    sort(all(ans));
    string res;
    for (auto &x : ans) res += x;
    cout << res << endl;

    return 0;
}