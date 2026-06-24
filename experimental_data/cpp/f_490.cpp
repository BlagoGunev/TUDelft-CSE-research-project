#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tuple>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
using namespace std;
inline int in(){int32_t x ; scanf("%d",&x) ; return x ; }
inline string get(){char ch[1000010] ; scanf("%s",ch) ; return ch;}
const int MAX_LG = 21;
//#define int long long
#define endl "\n"
#define mp make_pair
typedef pair<int , int > pii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
const int maxn = 6e3 + 10;
const int base = 29;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int MOD = 67967;
vector<int> g[maxn];
vector<int> suf[maxn];
vector<int> pref[maxn];
vector<int> childs[maxn];
int a[maxn];
int Par[maxn];
int Down[maxn] , Up[maxn];
int st[maxn] , en[maxn] , n;
int root[maxn][MAX_LG];
int lvl[maxn];
int cur = 0;
inline int get(int v , int kth)
{
    for (int i = MAX_LG - 1 ; i >= 0 ; i--)
    {
        if (kth & (1 << i))
        {
            kth -= (1 << i);
            v = root[v][i];
        }
        
    }
    return v;
}
inline void dfs(int v , int pr = 0)
{
    root[v][0] = pr;
    for (int i = 1 ; i < MAX_LG ; i ++) root[v][i] = root[root[v][i-1]][i-1];
    Par[v] = pr;
    st[v] = cur ++;
    Down[v] = Up[v] = 1;
    for (int i = 0 ; i < g[v].size() ; i ++)
    {
        int u = g[v][i];
        if (u == pr ) continue;
        lvl[u] = lvl[v] + 1;
        childs[v].push_back(u);
        dfs(u,v);
    }
    en[v] = cur;
    sort(childs[v].begin(),childs[v].end());
    pref[v].resize(childs[v].size());
    suf[v].resize(childs[v].size() + 1);
    for (int i = 0 ; i < childs[v].size() ; i ++)
    {
        int u = childs[v][i];
        if (a[u] > a[v]) pref[v][i] = Down[u] + 1;
    }
    for (int i = (int)childs[v].size() - 1 ; i >= 0 ; i --)
    {
        int u = childs[v][i];
        if (a[u] > a[v]) suf[v][i] = Down[u] + 1;
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        if (i == v) continue;
        if (en[v]>= en[i] && st[v] <= st[i] && a[v] < a[i]){
            Down[v] = max(Down[v],Down[i] + 1);
            int Dif = lvl[i] - lvl[v] - 1;
            int u = get(i,Dif);
            int id = lower_bound(childs[v].begin(),childs[v].end(),u)-childs[v].begin();
            pref[v][id] = max(pref[v][id],Down[i] + 1);
            suf[v][id] = max(suf[v][id],Down[i] + 1);
        }
    }
    for (int i = 1 ; i < childs[v].size() ; i ++)
        pref[v][i] = max(pref[v][i],pref[v][i-1]);
    for (int i = (int)childs[v].size() - 1 ; i >= 0 ; i --)
        suf[v][i] = max(suf[v][i],suf[v][i + 1]);
    
}
bool mark[maxn];
inline void dfsUp(int v , int pr = 0)
{
//    memset(mark,0,(n + 1) * sizeof(mark[0]));
    vector<int> vc;
    int V = pr;
    int Last = v;
    while (V)
    {
        vc.push_back(V);
        if (a[V] > a[v])
        {
            Up[v] = max(Up[v],Up[V] + 1);
            int id = lower_bound(childs[V].begin(),childs[V].end(),Last)-childs[V].begin();
            Up[v] = max(Up[v] , max(id ? pref[V][id - 1] + 1 : 0 , suf[V][id + 1] + 1));
        }
        mark[V] = true;
        Last = V;
        V = Par[V];
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        if (i == v) continue;
        if ((en[v]>= en[i] && st[v] <= st[i])) continue;
        if (mark[i]) continue;
        if (a[i] > a[v])
            Up[v] = max(Up[v],Down[i] + 1);
    }
    for (int i = 0 ; i < vc.size() ; i ++) mark[vc[i]] = false;
    for (int i = 0 ; i < g[v].size() ; i ++)
    {
        int u = g[v][i];
        if (u == pr) continue;
        dfsUp(u,v);
    }
}
int res;
int32_t main()
{
    n = in();
    for (int i = 1 ; i <= n ; i ++) a[i] = in();
    for (int i = 0 ; i < n - 1 ; i ++)
    {
        int v = in() , u = in();
        g[v].push_back(u) , g[u].push_back(v);
    }
    dfs(1);
    dfsUp(1);
    for (int i = 1 ; i <= n ; i ++)
        res = max(res,max(Up[i],Down[i]));
    cout << res << endl;
}