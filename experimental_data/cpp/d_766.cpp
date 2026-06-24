#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> mp;
const int N = 1e5+5;
char str[30];

int parent[N];
int height[N];
int add[N];


inline pair<int, int> find(int v) {
    if(parent[v]==v)    return {v,0};
    pair<int, int> temp=find(parent[v]);
    parent[v] = temp.first;add[v]+=temp.second;
    return {parent[v],add[v]};
}
inline void union_s(int u, int v, int x)   {
    if(height[u]<height[v]) swap(u, v),x*=-1;
    add[v]+=x,height[u] = max(height[u],1+height[v]),parent[v]=u;
}
inline int vl(int x)   {
    x%=2;
    if(x<0) x+=2;
    return x;
}
inline bool un(int a, int b, int x) {
    pair<int,  int> temp1 = find(a);
    pair<int, int> temp2 = find(b);
    int v1 = temp1.second+add[temp1.first],v2 = temp2.second+add[temp2.first];
    if(temp1.first==temp2.first)    return vl(v1+x)!=vl(v2);
    else    union_s(temp1.first, temp2.first, x+v1-v2);
    return 0;
}


int main() {
    int n,m,q,t,x,y;scanf("%d %d %d",&n,&m,&q);
    for (int i=1; i<=n; i++) {
        scanf("%s",str);
        mp[str]=i;
    }
        for (int i=1; i<=n; i++)    add[i]=height[i]=0,parent[i]=i;

    for (int i=1; i<=m; i++) {
        scanf("%d",&t);
        scanf("%s",str); x= mp[str];
        scanf("%s",str); y=mp[str];
        if(un(x,y,t-1)) printf("NO\n");
        else    printf("YES\n");
    }
    
    while (q--) {
        scanf("%s",str); x= mp[str];
        scanf("%s",str); y=mp[str];
        pair<int,  int> temp1 = find(x);
        pair<int, int> temp2 = find(y);
        int v1 = temp1.second+add[temp1.first],v2 = temp2.second+add[temp2.first];
        if(temp1.first!=temp2.first)    printf("3\n");
        else if(vl(v1)==vl(v2)) printf("1\n");
        else    printf("2\n");
    }
    return 0;
}