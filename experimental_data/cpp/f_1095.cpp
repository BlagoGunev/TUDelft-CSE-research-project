#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(2e5 + 10);
ll a[N];

struct edge{
    int u, v;
    ll w;

    bool operator < (edge &other){
        return this->w < other.w;
    }
};

vector< edge > edges;
int ft[N];
ll total_cost = 0LL;

int find(int x){
    if(ft[x] == x){
        return x;
    }

    return ft[x] = find(ft[x]);
}

void join(int u, int v, ll w){
    int x = find(u);
    int y = find(v);

    if(x != y){
        if(x < y){
            ft[y] = x;
        }else{
            ft[x] = y;
        }
        
        total_cost += w;
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    int indi = -1;
    ll mni = 1e18;

    for(int i = 1 ; i <= n ; i++){
        ft[i] = i;
        scanf("%lld", &a[i]);

        if(a[i] < mni){
            indi = i;
            mni = a[i];
        }
    }

    for(int i = 0 ; i < m ; i++){
        int x, y;
        ll w;

        scanf("%d %d %lld", &x, &y, &w);

        edges.push_back({x, y, w});
    }

    for(int i = 1 ; i <= n ; i++){
        edges.push_back({indi, i, mni + a[i]});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0 ; i < edges.size() ; i++){
        join(edges[i].u, edges[i].v, edges[i].w);
    }

    printf("%lld\n", total_cost);

    return 0;
}