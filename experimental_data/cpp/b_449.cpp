#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 100005
#define MAXM 400008*2
int N,M,K;
struct eList
{
    int Head[MAXN],Pre[MAXM],V[MAXM],W[MAXM],T[MAXM],tot;
    inline void AddEdge(int a,int b,int c,int d)
    {
        ++tot;
        V[tot]=b;W[tot]=c;T[tot]=d;
        Pre[tot]=Head[a];Head[a]=tot;
    }
    inline void AddEdge2(int a,int b,int c,int d)
    {
        AddEdge(a,b,c,d);
        AddEdge(b,a,c,d);
    }
}G;
long long Dist[MAXN];
int Path[MAXN];
int Q[MAXM];
bool inQ[MAXN];
void SPFA()
{
    memset(Dist,60,sizeof(Dist));
    Dist[1]=0;
    int Qh=0,Qt=1;
    inQ[1]=1;
    Q[1]=1;
    while (Qh<Qt)
    {
        ++Qh;if (Qh>=MAXM) Qh=0;
        int now=Q[Qh];
        for (int p=G.Head[now];p;p=G.Pre[p])
        {
            if (Dist[now]+G.W[p]<Dist[G.V[p]])
            {
                Dist[G.V[p]]=Dist[now]+G.W[p];
                Path[G.V[p]]=p;
                if (!inQ[G.V[p]])
                {
                    inQ[G.V[p]]=1;
                    ++Qt;if (Qt>=MAXM) Qt=0;
                    Q[Qt]=G.V[p];
                }
            }
            if (Dist[now]+G.W[p]==Dist[G.V[p]] && (!G.T[p]) && G.T[Path[G.V[p]]])
            {
                Path[G.V[p]]=p;
                if (!inQ[G.V[p]])
                {
                    inQ[G.V[p]]=1;
                    ++Qt;if (Qt>=MAXM) Qt=0;
                    Q[Qt]=G.V[p];
                }
            }
        }
        inQ[now]=0;
    }
}
int main()
{
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1;i<=M;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G.AddEdge2(a,b,c,0);
    }
    for (int i=1;i<=K;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G.AddEdge2(1,a,b,1);
    }
    SPFA();
    int Ans=0;
    for (int i=2;i<=N;++i)
    {
        if (G.T[Path[i]]) Ans++;
    }
    printf("%d\n",K-Ans);
    return 0;
}