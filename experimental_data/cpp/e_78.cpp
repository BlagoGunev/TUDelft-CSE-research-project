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
inline string get(){char ch[1001000] ; scanf("%s",ch) ; return ch;}
template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }
#define mp make_pair
#define EPS 1e-9
//#define int long long
typedef pair<int , int > pii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
const int maxn = 1e5 + 10;
const int base = 29;
const int MAX_LG = 21;
const int mod = 1e9 + 7;
const int INF = 1e18;
int n , t;
string a[30] , b[30];
int dist1[30][30] , dist2[30][30];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
struct edge
{
    int a , b , cap , flow;
};
int di[maxn];
int ptr[maxn];
int q[maxn];
vector<edge> e;
vector<int> g[maxn];
int whereX , whereY;
int source , sink;
inline void add(int a , int b , int cap)
{
    edge e1 = {a,b,cap,0};
    edge e2 = {b,a,0,0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    
    e.push_back(e2);
}
inline bool ok(int x , int y){return (x >= 0 && x < n && y >= 0 && y < n);}
inline void BFS1(int x = whereX , int y = whereY)
{
    queue<pii> q;
    q.push({x,y});
    for (int i = 0 ; i <= 20 ; i ++)
        for (int j = 0 ; j <= 20 ; j ++)
            dist1[i][j] = 1e9;
    dist1[x][y] = 0;
    while (!q.empty())
    {
        int x = q.front().first , y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i ++)
        {
            int x2 = x + dx[i] , y2 = y + dy[i];
            if (ok(x2,y2) && dist1[x2][y2] >= 1e9 && b[x2][y2] != 'Y')
            {
                dist1[x2][y2] = dist1[x][y] + 1;
                q.push({x2,y2});
            }
        }
    }
    
}
inline bool bfs()
{
    memset(di,-1,n * sizeof di[0]);
    int qh = 0 , qt = 0;
    q[qt ++] = source;
    di[source] = 0;
    while (qh < qt && di[sink] == -1)
    {
        int v = q[qh ++];
        for (int pt = 0 ; pt < g[v].size() ; pt ++)
        {
            int id = g[v][pt] , to = e[id].b;
            if (di[to] == -1 && e[id].flow < e[id].cap)
            {
                q[qt ++] = to;
                di[to] = di[v] + 1;
            }
        }
    }
    return di[sink] != -1;
}
inline int dfs(int v , int flow)
{
    if (!flow) return 0;
    if (v == sink) return flow;
    for ( ; ptr[v] < g[v].size() ; ptr[v] ++)
    {
        int id = g[v][ptr[v]] , to = e[id].b;
        if (di[to ] != di[v] + 1) continue;
        int pushed = dfs(to , min(flow , e[id].cap - e[id].flow));
        if (pushed)
        {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
inline int max_flow()
{
    int flow = 0;
    while (true)
    {
        if (!bfs()) break;
        memset(ptr,0,n * sizeof ptr[0]);
        while (int pushed = dfs(source , 1e9))
        {
            flow += pushed;
        }
    }
    return flow;
}
inline void BFS2(int x , int y)
{
    queue<pii> q;
    q.push({x,y});
    for (int i = 0 ; i <= 20 ; i ++)
        for (int j = 0 ; j <= 20 ; j ++)
            dist2[i][j] = 1e9;
    dist2[x][y] = 0;
    while (!q.empty())
    {
        int x = q.front().first , y = q.front().second;
        q.pop();
        if (dist2[x][y] >= dist1[x][y]) continue;
        for (int i = 0 ; i < 4 ; i++)
        {
            int x2 = x + dx[i] , y2 = y + dy[i];
            if(ok(x2,y2) &&  dist2[x2][y2] >= 1e9 && a[x2][y2] != 'Y' && dist2[x][y] + 1 <= dist1[x2][y2])
            {
                dist2[x2][y2] = dist2[x][y] + 1;
                q.push({x2,y2});
            }
        }
    }
}
int32_t main()
{
    n = in() , t = in();
    for (int i = 0 ; i < n ; i ++)
        a[i] = get();
    for (int i = 0 ; i < n ; i ++)
    {
        b[i] = get();
        for (int j = 0 ; j < n ; j ++)
        {
            if (b[i][j] == 'Z')
            {
                b[i][j] = a[i][j] = 'Y';
                whereX = i , whereY = j;
            }
        }
    }
    BFS1();
    source = 0 , sink = 2 * n * n + 1;
    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            if (a[i][j] == 'Y') continue;
            int what = i * n + j + 1;
            int what2 = n * n + i * n + j + 1;
            add(source,what,a[i][j]-'0');
            add(what2,sink,b[i][j]-'0');
            BFS2(i , j);
            for (int ptx = 0 ; ptx < n ; ptx ++)
            {
                for (int pty = 0 ; pty < n ; pty ++)
                {
                    if (b[ptx][pty] == 'Y' || dist2[ptx][pty] > t) continue;
                    add(what,n * n + ptx * n + pty + 1 , a[i][j] - '0');
                }
            }
        }
    }
    n = 2 * n * n + 5;
    
//    printf("%d\n",max_flow());
    cout << max_flow() << endl;
}