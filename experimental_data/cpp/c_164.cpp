/*
 * File: C.cpp
 * Author: wym510 
 * Email: <wym6110@gmail.com>
 * Create Date: 2012-4-9 0:10:37
*/

#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define S size()
#define B begin()
#define E end()
#define P push_back
#define fu(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=b-1;i>=a;--i)
typedef long long int64;
using namespace std;


const int MaxN=10000;

map <int,int> cnt;

struct node
{
    int s,e,c;
}t[MaxN];

struct edge
{
    int vj,f,c;
    edge *next,*back;
}da[MaxN*5],*g[MaxN];
int tot=0;

void add(int u,int v,int f,int c)
{
    da[tot].vj=v;
    da[tot].f=f;
    da[tot].c=c;
    da[tot].back=da+(tot^1);
    da[tot].next=g[u];
    g[u]=da+tot++;

    da[tot].vj=u;
    da[tot].f=0;
    da[tot].c=-c;
    da[tot].back=da+(tot^1);
    da[tot].next=g[v];
    g[v]=da+tot++;
}

edge *fa[MaxN];
int q[MaxN*10],dis[MaxN];
bool vis[MaxN];

void spfa(int V)
{
    int ff=MaxN*5,rr=MaxN*5;

    for(int i=0;i<=V;i++) dis[i]=(int)-1e9;
    dis[0]=0;q[rr++]=0;
    fa[0]=NULL;vis[0]=true;
    while(ff<rr)
    {
        int u=q[ff++];

        vis[u]=false;
        for(edge *p=g[u];p!=NULL;p=p->next)
            if(p->f)
            {
                if(dis[u]+p->c>dis[p->vj])
                {
                    dis[p->vj]=dis[u]+p->c;
                    fa[p->vj]=p;
                    if(!vis[p->vj])
                    {
                        vis[p->vj]=true;
                        if(ff<rr && dis[q[ff]]<dis[p->vj]) 
                            q[--ff]=p->vj;
                        else 
                            q[rr++]=p->vj;
                    }
                }
            }
    }

    int no=V;
    
    while(no)
    {
        fa[no]->f--;
        fa[no]->back->f++;
        no=fa[no]->back->vj;
    }
}

void flow(int k,int V)
{
    for(int i=0;i<k;i++) spfa(V);
}

int main()
{
    int n,k;

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&t[i].s,&t[i].e,&t[i].c);
        t[i].e+=t[i].s;
        cnt[t[i].s]=cnt[t[i].e]=1;
    }
    
    int V=0;

    for(map<int,int>::iterator i=cnt.B;i!=cnt.E;i++) 
        i->second=++V;
    for(int i=0;i<n;i++) add(cnt[t[i].s],cnt[t[i].e],1,t[i].c);
    for(int i=0;i<V;i++) add(i,i+1,k,0);

    flow(k,V);
    
    for(int i=0;i<n;i++)
        printf("%d%c",!da[i*2].f,i==n-1?'\n':' ');

    return 0;
}

/* vim: set ts=4 sw=4: */