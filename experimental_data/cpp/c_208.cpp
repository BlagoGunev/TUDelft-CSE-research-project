#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define rank krevedka
#define ran rank
using namespace std;

vector<int> e[1005];
int dist[2][1000];
long long ways[2][1000];
int n;
void bfs(int k)
{
    list<int>sp;
    if(k==0)
    {
        dist[k][0] = 1;
        ways[k][0] = 1;
        sp.push_back(0);
    }else
    {
        sp.push_back(n-1);
        dist[k][n-1] = 1;
        ways[k][n-1] = 1;
    }
    while(sp.begin()!=sp.end())
    {
        int u = sp.front();
        sp.pop_front();
        for(int i=0;i<e[u].size();i++)
        {
            int v = e[u][i];
            if(dist[k][v]==0) {dist[k][v] = dist[k][u]+1; sp.push_back(v);}
            if(dist[k][v]==dist[k][u]+1) ways[k][v]+=ways[k][u];
        }
    }
}

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs(0);
    bfs(1);
    long long r = 0;
    for(int i=1;i<n-1;i++)
    if(dist[0][i]-1+dist[1][i]==dist[0][n-1])
    if(ways[0][i]*ways[1][i]>r) r = ways[0][i]*ways[1][i];
    r*=2;
    if(r<=ways[0][n-1]) cout <<1 <<endl; else
        printf("%.10f\n",double(r)/ways[0][n-1]);
    return 0;
}
// lnufkoasjk