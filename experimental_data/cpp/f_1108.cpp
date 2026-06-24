#include <bits/stdc++.h>

#define endl '\n'
#define left aba
#define right abc
#define oo if(LOG)
#define pb push_back
#define FIO ios_base::sync_with_stdio(0); cin.tie(0)

#ifdef LOCAL
#define LOG 1
#else
#define LOG 0
#endif

using namespace std;

const int N = (int)2e5 + 3;

struct edge {
    int from, to, w, used;
};

int n, m, a, b, c, ans;
int parent[N];
vector<edge> v;

int parentOf(int n)
{
    if(n == parent[n])
    {
        return n;
    }
    return parent[n] = parentOf(parent[n]);
}

struct Compare {
    bool operator()(edge aa, edge bb) {
        if(aa.w == bb.w) {
            return aa.used > bb.used;
        } return aa.w > bb.w;
    }
};

int main() {
    FIO;

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        v.pb({a, b, c, 0});
    }
    for(int i = 1; i <= n; ++i) parent[i] = i;
    for(int i = 0; i < m; ++i) v[i].used = 0;
    sort(v.begin(), v.end(), [](edge aa, edge bb) {
        return aa.w < bb.w;
    });
    int selected = n - 1;
    for(int i = 0; i < m && selected; ++i) {
        int p = parentOf(v[i].from), q = parentOf(v[i].to);
        if(p != q) {
            parent[p] = q;
            v[i].used = 1;
            selected--;
        }
    }
    for(int i = 1; i <= n; ++i) parent[i] = i;
    selected = n - 1;
    priority_queue<edge, vector<edge>, Compare> Q;
    for(int i = 0; i < m; ++i) {
        Q.push(v[i]);
    }
    //int b = 0;
    while(!Q.empty() && selected > 0) {
        edge top = Q.top();
        Q.pop();
        //b ++;
        //cout << top.from << " " << top.to << ' ' << top.w << endl;
        //if(b >15) break;
        int p = parentOf(top.from), q = parentOf(top.to);
        if(p != q) {
            if(top.used == 0) {
                //cout << top.from << " " << top.to << " " << Q.size() << endl;
                top.w++;
                ans++;
                Q.push(top);
                continue;
            }
            parent[p] = q;
            selected--;
        }
    }
    cout << ans << endl;

    oo cout << "Time: " << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}