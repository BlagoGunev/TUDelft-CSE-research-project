/*************************************************************************
	> File Name: 2019_12_12_5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月12日 星期四 22时15分12秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstring>
#define MAXN 200003
#define MAXM 400003
using namespace std;

int g[MAXN],a[MAXN],edgesize,step[MAXN];
struct Edge
{
    int f,t;
    void var(int _f,int _t)
    {
        f = _f;
        t = _t;
    }
}edge[MAXM];
struct node
{
    int id,w;
    node (int _id,int _w):id(_id),w(_w){};
    bool operator < (const node &t)const
    {
        return w > t.w;
    }
};
void addedge(int f,int t)
{
    edge[++edgesize].var(g[f],t);
    g[f] = edgesize;
}
priority_queue <node> q;
int main()
{
    int n;
    edgesize = 0;
    memset(g,-1,sizeof(g));
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if(i - a[i] > 0)
            addedge(i - a[i],i);
        if(i + a[i] <= n)
            addedge(i + a[i],i);
    }
    memset(step,-1,sizeof(step));
    for(int i = 1;i <= n;i++)
        if(a[i] % 2)
        {
            for(int j = g[i];~j;j = edge[j].f)
                if(a[edge[j].t] % 2 == 0)
                {
                    step[edge[j].t] = 1;
                    q.push(node(edge[j].t,step[edge[j].t]));
                }
        }
    while(!q.empty())
    {
        node now = q.top();
        q.pop();
        for(int i = g[now.id];~i;i = edge[i].f)
            if(a[edge[i].t] % 2 == 0 && step[edge[i].t] == -1)
            {
                step[edge[i].t] = now.w + 1;
                q.push(node(edge[i].t,step[edge[i].t]));
            }
    }
    for(int i = 1;i <= n;i++)
    if(a[i] % 2 == 0)
    {
        for(int j = g[i];~j;j = edge[j].f)
            if(a[edge[j].t] % 2)
            {
                step[edge[j].t] = 1;
                q.push(node(edge[j].t,step[edge[j].t]));
            }
    }
    while(!q.empty())
    {
        node now = q.top();
        q.pop();
        for(int i = g[now.id];~i;i = edge[i].f)
            if(a[edge[i].t] % 2 && step[edge[i].t] == -1)
            {
                step[edge[i].t] = now.w + 1;
                q.push(node(edge[i].t,step[edge[i].t]));
            }
    }
    for(int i = 1;i <= n;i++)
        printf("%d ",step[i]);
    return 0;
}