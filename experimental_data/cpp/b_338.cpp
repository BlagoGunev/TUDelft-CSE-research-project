#pragma comment(linker,"/STACK:204800000,204800000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define mod 1000000009
#define oo 0x3f3f3f3f
#define mxn 100005
#define mxe 200005

int first[mxn], vv[mxe], nxt[mxe], e, n, m, d;
bool can[mxn], is[mxn];
int up[mxn], down[mxn];

void add(int u, int v) {
    vv[e] = v; nxt[e] = first[u]; first[u] = e++;
}

void dfs( int u, int p, int c ) {
    can[u] = true;
    up[u] = c; down[u] = -200000;
    if( is[u] ) up[u] = max(0, c), down[u] = 0;
    for( int i = first[u]; i != -1; i = nxt[i] ) {
        int v = vv[i];
        if( v == p ) continue;
        dfs(v, u, up[u] + 1);
        down[u] = max( down[u], down[v] + 1 );
    }
}

int dm[mxn], mx[mxn], sx[mxn];

void dfs2( int u, int p, int c ) {
    mx[u] = -200000, sx[u] = -200000;
    dm[u] = -1;
    up[u] = max(up[u], c);
    mx[u] = up[u]; sx[u] = up[u];
    for( int i = first[u]; i != -1; i = nxt[i] ) {
        int v = vv[i];
        if( v == p ) continue;
        if( down[v] + 1 > mx[u] ) {
            sx[u] = mx[u];
            dm[u] = v; mx[u] = down[v] + 1;
        }
        else if( down[v] + 1 > sx[u] ) {
            sx[u] = down[v] + 1;
        }
    }
    for( int i = first[u]; i != -1; i = nxt[i] ) {
        int v = vv[i];
        if( v == p ) continue;
        if( v == dm[u] )
            dfs2( v, u, sx[u] + 1 );
        else dfs2( v, u, mx[u] + 1 );
    }
}

int main()
{
    memset( first, -1, sizeof(first) );
    cin >> n >> m >> d;
    int x, u, v;
    for( int i = 0; i < m; ++i ) {
        scanf( "%d", &x );
        is[x] = true;
    }
    for( int i = 1; i < n; ++i ) {
        scanf( "%d%d", &u, &v );
        add(u, v); add(v, u);
    }
    dfs(1, -1, -200000);
    dfs2(1, -1, -200000);
    int ans = 0;
    for( int i = 1; i <= n; ++i ) {
        if( up[i] > d || down[i] > d )
            ++ans;
    }
    cout << n - ans << endl;
    return 0;
}