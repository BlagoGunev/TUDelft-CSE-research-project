/////////////////////////   _LeMur_
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
//#include <chrono>
//#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 300005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
long long c[N];

vector < pair<int,long long> > g[3][N];

long long dp[N];
long long mn1[N] , mn2[N];

void dfs(int v,int p){
    mn1[v] = c[v];
    mn2[v] = c[v];
    dp[v] = c[v];
    for(int i=0;i<(int)g[0][v].size();i++){
        int to = g[0][v][i].first;
        long long len = g[0][v][i].second + g[1][v][i].second;
        if(to == p)continue;
        dfs(to , v);
        if(mn1[to] + len < mn1[v]){
            mn2[v] = mn1[v];
            mn1[v] = mn1[to] + len;
            continue;
        }
        if(mn1[to] + len < mn2[v]){
            mn2[v] = mn1[to] + len;
        }
    }
}

void dfsup(int v,int p,long long L){
    if(p != -1){
        dp[v] = min(dp[v] , dp[p] + L);
    }
    for(int i=0;i<(int)g[0][v].size();i++){
        int to = g[0][v][i].first;
        long long len = g[0][v][i].second + g[1][v][i].second;
        if(to == p)continue;
        if(mn1[to] + len == mn1[v]){
            dp[to] = min(dp[to] , mn2[v] + len);
        }
        else{
            dp[to] = min(dp[to] , mn1[v] + len);
        }
        dfsup(to , v , len);
    }
}

int q;

bool used[N];
int mn , gag;
int order[N] , nn;

long long DP[N][3][3];

void dfs1(int v,int p){
    ++nn;
    order[v] = 1;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            DP[v][i][j] = inf * 2ll * inf;
        }
    }
    for(int i=0;i<(int)g[0][v].size();i++){
        int to = g[0][v][i].first;
        if(to == p || used[to])continue;
        dfs1(to , v);
        order[v] += order[to];
    }
}

void dfs2(int v,int p){
    int S = nn - order[v];
    for(int i=0;i<(int)g[0][v].size();i++){
        int to = g[0][v][i].first;
        if(to == p || used[to])continue;
        dfs2(to , v);
        S = max(S , order[to]);
    }
    if(mn == -1 || S < mn){
        mn = S;
        gag = v;
    }
}

void root(int v,int p){
    order[v] = 1;
    for(int i=0;i<(int)g[0][v].size();i++){
        int to = g[0][v][i].first;
        if(to == p || used[to])continue;
        ///
        for(int j=0;j<2;j++){
            for(int h=0;h<2;h++){
                DP[to][j][h] = min(DP[to][j][h] , DP[v][j][h] + g[h][v][i].second);
            }
        }
        for(int j=0;j<2;j++){
            for(int h=0;h<2;h++){
                DP[to][j][h] = min(DP[to][j][h ^ 1] + c[to] , DP[to][j][h]);
            }
        }
        ///
        root(to , v);
        order[v] += order[to];
    }
}

struct Q{
    int a1 , b1;
    int a2 , b2;
};

Q mas[2 * N];

long long answ[2 * N];
vector < pair<int,int> > query[N];

int findcenter(int v){
    nn = 0;
    dfs1(v , -1);
    mn = -1;
    dfs2(v , -1);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(i == j)
                DP[gag][i][j] = 0;
            else
                DP[gag][i][j] = c[gag];
        }
    }
    root(gag , -1);
    return gag;
}

bool mark[2 * N] , color[2 * N];
int cnt[2 * N];
vector <int> vec , P;

void solve(int v,int p){
    if(p != -1){
        for(int i=0;i<(int)query[v].size();i++){
            int id = query[v][i].second;
            if(color[id] || mark[id])continue;
            mark[id] = true;
            vec.push_back(id);
            P.push_back(id);
        }
    }
    for(int i=0;i<(int)g[0][v].size();i++){
        int to = g[0][v][i].first;
        if(to == p || used[to])continue;
        solve(to , v);
        if(p == -1){
            for(int j=0;j<(int)vec.size();j++){
                int id = vec[j];
                ++cnt[id];
                mark[id] = false;
            }
            vec.clear();
        }
    }
}

void upd(int id){
    int v1 = mas[id].b1;
    int v2 = mas[id].b2;
    int x1 = mas[id].a1;
    int x2 = mas[id].a2;
    answ[id] = inf * 2ll * inf;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            long long L = DP[v1][i][x1] + DP[v2][j][x2];
            if(i != j) L += c[gag];
            answ[id] = min(answ[id] , L);
        }
    }
}

void centroid(){
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        v = findcenter(v);
        ///
        for(int i=0;i<(int)query[v].size();i++){
            int id = query[v][i].second;
            if(color[id])continue;
            ++cnt[id];
            P.push_back(id);
        }
        solve(v , -1);
        for(int i=0;i<(int)P.size();i++){
            int id = P[i];
            if(cnt[id] == 2){
                color[id] = true;
                upd(id);
            }
            cnt[id] = 0;
        }
        P.clear();
        ///
        used[v] = true;
        for(int i=0;i<(int)g[0][v].size();i++){
            int to = g[0][v][i].first;
            if(used[to])continue;
            q.push(to);
        }
    }
}

int main() {
    //mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=1;i<n;i++){
        int a , b;
        long long c , d;
        scanf("%d%d%lld%lld",&a,&b,&c,&d);
        g[0][a].push_back(make_pair(b , c));
        g[0][b].push_back(make_pair(a , c));
        g[1][a].push_back(make_pair(b , d));
        g[1][b].push_back(make_pair(a , d));
    }
    ///
    dfs(1 , -1);
    dfsup(1 , -1 , 0);
    ///
    for(int i=1;i<=n;i++){
        c[i] = min(dp[i] , mn1[i]);
    }
    ///
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int a , b;
        scanf("%d%d",&a,&b);
        int a1 = (a + 1) % 2 , b1 = (a + 1) / 2;
        int a2 = (b + 1) % 2 , b2 = (b + 1) / 2;
        ///
        mas[i].a1 = a1;
        mas[i].a2 = a2;
        mas[i].b1 = b1;
        mas[i].b2 = b2;
        ///
        query[b1].push_back(make_pair(a1 , i));
        query[b2].push_back(make_pair(a1 , i));
    }
    centroid();
    for(int i=1;i<=q;i++){
        printf("%lld\n",answ[i]);
    }
    return 0;
}