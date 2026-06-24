#include<bits/stdc++.h>
using namespace std;

const int N = 45;

bool flag[N], a[N][N];
int ans, cnt[N], group[N], n, m, vis[N];
bool ls[N];
int tcnt = 1;
map<string, int> mp;

int getid(const string &s) {
    if(!mp.count(s)) return mp[s] = tcnt++;
    else return mp[s];
}

bool dfs( int u, int pos ) {
    int i, j;
    for (i = u + 1; i <= m; i++) {
        if (cnt[i] + pos <= ans) return 0;
        if (a[u][i]) {
            for (j = 0; j < pos; j++) if (!a[i][vis[j]]) break;
            if (j == pos) {
                vis[pos] = i;
                if (dfs(i, pos + 1)) return 1;
            }
        }
    }
    if (pos > ans) {
        for (i = 0; i < pos; i++)
            group[i] = vis[i];
        ans = pos;
        return 1;
    }
    return 0;
}
void get_ans() {
    ans = -1;
    for (int i = m; i > 0; i--) {
        vis[0] = i;
        dfs(i, 1);
        cnt[i] = ans;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int k; string s;
        cin >> k;
        if(k == 1){
            vector<int> V;
            for(int j = 1; j <= m; j++) if(ls[j]) V.push_back(j);
            for(int x : V) {
                for(int y : V) a[x][y] |= 1;
            }
            memset(ls, false, sizeof(ls));
        }
        else {
            cin >> s;
            ls[getid(s)] = true;
        }
    }
    vector<int> V;
    for(int j = 1; j <= m; j++) if(ls[j]) V.push_back(j);
    for(int x : V) {
        for(int y : V) a[x][y] = true;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if (i == j) a[i][j] = false;
            else a[i][j] ^= 1;
    get_ans();

    if (ans < 0) ans = 0;
    cout << ans << endl;
}