#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int n1, n2, n, m;
vector<int> sz[c];
bool fix[c], v[c], cut[c];
int szint[c], visz[c];
void dfs(int a) {
    v[a]=true;
    visz[a]=szint[a];
    int db=0;
    for (auto x:sz[a]) {
        if (fix[x]) continue;
        if (!v[x]) {
            //cout << "el " << a << " " << x << "\n";
            szint[x]=szint[a]+1;
            dfs(x);
            visz[a]=min(visz[a], visz[x]);
            if (szint[a]<=visz[x]) {
                db++;
            }
        } else {
            visz[a]=min(visz[a], szint[x]);
        }
    }
    //cout << "dfs " << a << " " << db << " " << szint[a] << "\n";
    if (db>=1 && szint[a]>1 || db>=2 && szint[a]==1) {
        cut[a]=true;
    }
}
void kill() {
    for (int i=1; i<=n; i++) {
        for (auto x:sz[i]) {
            if (i<x) {
                cout << i << "_" << x << ",";
            }
        }
    }
    exit(0);
}
void solve() {
    cin >> n1 >> n2 >> m;
    n=n1+n2;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    fix[1]=1;
    for (int s=1; s<n1; s++) {
        for (int i=1; i<=n; i++) {
            if (!fix[i] && !v[i]) {
                szint[i]=1;
                dfs(i);
            }
        }
        bool kesz=0;
        for (int i=1; i<=n; i++) {
            if (fix[i] || cut[i] || kesz) continue;
            for (auto x:sz[i]) {
                if (fix[x]) {
                    fix[i]=1;
                    kesz=1;
                }
            }
        }
        if (!kesz) {
            cout << "baj_";
            kill();

        }

        for (int i=0; i<=n; i++) {
            szint[i]=0, visz[i]=0, v[i]=0, cut[i]=0;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!fix[i]) {
            dfs(i);
            for (int j=1; j<=n; j++) {
                if (!fix[j] && !v[j]) {
                    kill();
                }
                szint[j]=0, visz[j]=0, v[j]=0, cut[j]=0;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (fix[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    for (int i=1; i<=n; i++) {
        if (!fix[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";

    for (int i=0; i<=n; i++) {
        sz[i].clear();
        fix[i]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
2 5 12
1 2
1 3
2 3
2 5
2 7
3 4
3 5
3 6
3 7
4 5
4 7
5 6
*/
/*
1_2,1_3,2_3,2_5,2_7,3_4,3_5,3_6,3_7,4_5,4_7,5_6,
*/