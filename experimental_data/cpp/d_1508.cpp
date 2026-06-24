#include<bits/stdc++.h>

using namespace std;

const int N=2022;

typedef long long ll;

ll n,a[N],x[N],y[N];

int p[N],tot;

int f[N];

vector<pair<int,int>>ans;

int find(int x){return x==f[x]?x:f[x]=find(f[x]);}

bool mg(int x,int y){

    int fx=find(x),fy=find(y);

    if(fx==fy)return 0;

    return f[fy]=fx,1;

}

void doit(int x,int y){swap(a[x],a[y]),ans.push_back({x,y});}

int main(){

    cin>>n;iota(f,f+n+1,0);

    for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>a[i];

    for(int i=1;i<=n;i++)if(a[i]!=i)p[++tot]=i,mg(i,a[i]);

    if(!tot)return cout<<0<<'\n',0;

    sort(p+1,p+tot+1,[](int a,int b){return x[a]==x[b]?y[a]<y[b]:x[a]<x[b];});

    for(int i=2;i<=tot;i++)x[p[i]]-=x[p[1]],y[p[i]]-=y[p[1]];

    sort(p+2,p+tot+1,[](int a,int b){return x[a]*y[b]>y[a]*x[b];});

    for(int i=2;i<tot;i++)if(mg(p[i+1],p[i]))doit(p[i+1],p[i]);

    while(a[p[1]]!=p[1])doit(p[1],a[p[1]]);

    cout<<ans.size()<<'\n';for(auto[x,y]:ans)cout<<x<<' '<<y<<'\n';

}