#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <map>
#include <set>

using namespace std;
int n;
vector<int>cul[400005];
vector<int>adj[400005];
int timp,inf=1e6;
int in[400005];
int out[400005];
int v[400005];
int hard[400005];
int dept[400005];
int bl[22][400005];
int minim[1200000];
void update(int node,int st,int dr,int poz,int val)
{
    if(st>poz || dr <poz)
    {
        return;
    }
    if(st==poz && dr==poz)
    {
        minim[node]+=val;
        return;
    }
    int mij=(st+dr)/2;
    update(node*2,st,mij,poz,val);
    update(node*2+1,mij+1,dr,poz,val);
    minim[node]=min(minim[node*2],minim[node*2+1]);
}
int qr(int node,int st,int dr,int qst,int qdr)
{
    if(st>dr || st>qdr || qst>dr || qst>qdr)
    {
        return 2;
    }
    if(qst<=st && dr<=qdr)
    {
        return minim[node];
    }
    int mij=(st+dr)/2;
    return min(qr(node*2,st,mij,qst,qdr),qr(node*2+1,mij+1,dr,qst,qdr));
}
void build(int node,int st,int dr)
{
    minim[node]=2;
    if(st!=dr)
    {
        int mij=(st+dr)/2;
        build(node*2,st,mij);
        build(node*2+1,mij+1,dr);
    }
}
int fre[400005];
void dfs(int curr,int par)
{
    timp++;
    in[curr]=timp;
    out[curr]=timp;
    bl[0][curr]=par;
    for(int i=1;i<=19;i++)
    {
        bl[i][curr]=bl[i-1][bl[i-1][curr]];
    }
    dept[curr]=dept[par]+1;
    for(auto k:adj[curr])
    {
        if(k!=par)
        {
            dfs(k,curr);
            out[curr]=out[k];
        }
    }
}
void dfshard(int curr,int par)
{
    for(auto k:adj[curr])
    {
        if(k!=par)
        {
            dfshard(k,curr);
            hard[curr]=max(hard[curr],hard[k]);
        }
    }
}
int lca(int a,int b)
{
    if(dept[a]<dept[b])
    {
        swap(a,b);
    }
    for(int i=19;i>=0;i--)
    {
        if(dept[bl[i][a]]>=dept[b])
        {
            a=bl[i][a];
        }
    }
    if(a==b)
    {
        return a;
    }
    for(int i=19;i>=0;i--)
    {
        if(bl[i][a]!=bl[i][b])
        {
            a=bl[i][a];
            b=bl[i][b];
        }
    }
    return bl[0][a];
}
void dfskill(int curr)
{
    fre[curr]=0;
    update(1,1,n,in[curr],inf);
    for(auto x:cul[v[curr]])
    {
        update(1,1,n,in[x],-1);
    }
    for(auto k:adj[curr])
    {
        if(in[k]>in[curr] && fre[k]==1)
        {
            dfskill(k);
        }
    }
}
vector<int>vec;
int solve(int root)
{
    vec.clear();
    int i;
    timp=0;
    dfs(root,0);
    build(1,1,n);
    for(i=1;i<=n;i++)
    {
        fre[i]=1;
        hard[i]=0;
    }
    for(i=1;i<=n/2;i++)
    {
        int lc=lca(cul[i][0],cul[i][1]);
        hard[lc]=1;
    }
    dfshard(root,0);
    for(i=n;i>=1;i--)
    {
        if(fre[i]==1 && hard[i]==0)
        {
            if(qr(1,1,n,in[i],out[i])!=1)
            {
                dfskill(i);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(fre[i]==1)
        {
           vec.push_back(i);
        }
    }
    if(fre[n]==1)
    {
        return 0;
    }
    return 1;
}
signed main()
{
    long long i,j,k,l,z,a,b,t=1,h,poz1,poz2,x,y,c,d,c1,c2,nra,nrc,sol,x2,y2,op,temp,r,nd,u,imp,e,f,g,ramase,m,m2,xr,xiw,last,w,pow;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    t=1;
    char ch;
    long long minim=2*-1e9;
    //cin>>t;
    vector<int>sol1,sol2;
    for(op=1; op<=t; op++)
    {
        cin>>n;
        n=n*2;
        for(i=1;i<=n;i++)
        {
            cin>>v[i];
            cul[v[i]].push_back(i);
        }
        for(i=1;i<n;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int guess;
        for(i=1;i<n;i++)
        {
            if(v[i]==v[n])
            {
                guess=solve(i);
            }
        }
        if(guess==0)
        {
            guess=solve(n);
        }
        cout<<vec.size()<<'\n';
        for(i=0;i<vec.size();i++)
        {
            cout<<vec[i]<<" ";
        }
    }
    return 0;
}