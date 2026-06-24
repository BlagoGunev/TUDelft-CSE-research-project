#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int Read() {
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch) && ch != '-')  ch = getchar();
    if(ch == '-')  f = -1, ch = getchar();
    while(isdigit(ch))  x = x * 10 + ch - '0', ch = getchar();
    return x * f;  
}
const int N = 1e5 + 5;
int a[N], du[N], col[N], sz[N], cnt;
vector<int> edg[N];
void dfs(int u) {
    if(col[u])
        return ;
    ++sz[cnt], col[u] = cnt;
    for(auto v : edg[u])
        dfs(v);
}
signed main() {
    int T = Read();
    while(T--) {
        int n = Read(), k = Read();
        memset(col + 1, 0, sizeof(int) * n);
        memset(du + 1, 0, sizeof(int) * n);
        for (int i = 1; i <= n; i++)
            edg[i].clear();
        for (int i = 1; i <= n; i++) {
            ++du[a[i] = Read()];
            edg[a[i]].push_back(i);
            edg[i].push_back(a[i]);
        }
        if(k == 1) {
            int flag = 1;
            for(int i = 1; i <= n; i++)
                if(a[i] != i)
                    flag = 0;
            puts(flag ? "YES" : "NO");
            continue;
        }
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if(col[i])
                continue ;
            sz[++cnt] = 0;
            dfs(i);
        }
        // cout << cnt << endl;
        queue<int> q;
        for(int i = 1; i <= n; i++)
            if(!du[i])
                q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            --du[a[u]];
            --sz[col[u]];
            if(!du[a[u]])
                q.push(a[u]);
        }
        int flag = 1;
        for (int i = 1; i <= cnt; i++) {
            // cout << sz[i] << endl;
            if(sz[i] != k)
                flag = 0;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}