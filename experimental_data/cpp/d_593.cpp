#include <bits/stdc++.h>
#include<iostream>

#include<cstring>

#include<cstdio>

#include<cmath>

#include<algorithm>

using namespace std;



#pragma comment(linker, "/STACK:102400000,102400000")

#define ls i<<1

#define rs ls | 1

#define mid ((ll+rr)>>1)

#define pii pair<int,int>

#define MP make_pair



typedef long long LL;

const long long INF = 1e18;

const double Pi = acos(-1.0);

const int N = 2e5+10, M = 5e5+11, inf = 2e9, mod = 998244353;



LL c[N];

int head[N],t = 1, fv[N], f[N], deep[N], n, m, pa[N];

struct edge{int to,next,id;}e[N * 2];

struct Line {

    int x,y;

    LL z;

    Line(int x = 0, int y = 0, int z = 0) : x (x), y (y), z (z) {}

}L[N];

void add(int u,int v,int id) {e[t].next = head[u];e[t].to = v;e[t].id = id; head[u] = t++; }



int finds(int x) {return x == pa[x]? pa[x]:pa[x] = finds(pa[x]);}



void update(int u,int to) {

    fv[to] = fv[u];

    f[to] = f[u];

}

void dfs(int u,int fa) {

        deep[u] = deep[fa] + 1;

        for(int i = head[u]; i; i = e[i].next) {

                int to = e[i].to;

                if(to == fa) continue;

                fv[to] = e[i].id;

                f[to] = u;

                if(c[e[i].id] == 1) {

                    pa[to] = finds(u);

                    update(u,to);

                }



                dfs(to,u);

        }

}



LL Lca(int u,int v,LL res) {

         u = finds(u);

         v = finds(v);

        while(u != v) {

            if(deep[u] < deep[v]) swap(u,v);

           // cout<<deep[u]<<" "<<deep[v]<<" "<<fv[u]<<" "<<c[fv[u]]<<endl;

            res /= c[fv[u]];

            if(res == 0) return res;

            u = finds(f[u]);

        }

        return res;

}

int main() {

        scanf("%d%d",&n,&m);

        for(int i = 0; i <= n; ++i) pa[i] = i;

        for(int i = 1; i < n; ++i) {

            int a,b;

            scanf("%d%d%lld",&a,&b,&c[i]);

            add(a,b,i);add(b,a,i);

            L[i] = Line(a,b,c[i]);

        }



        c[0] = 1;

        fv[1] = 0;

        f[1] = 1;



        dfs(1,0);

        while(m --) {

            int op, x;

            LL z,y;

            scanf("%d%d%lld",&op,&x,&y);

            if(op == 1) {

                scanf("%lld",&z);

                LL res = Lca(x,y,z);

                printf("%lld\n",res);

            }

            else {

                c[x] = y;

                int u = L[x].x;

                int v = L[x].y;

                if(deep[u] < deep[v]) swap(u,v);

                if(c[x] == 1) {

                    pa[finds(u)] = finds(v);

                    update(v,u);

                }

            }

        }

}