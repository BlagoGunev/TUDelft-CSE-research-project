#include <cstdio>

#include <cctype>

#include <cstring>

#include <algorithm>

#define repu(i,x,y) for (int i=x; i<=y; ++i)

using namespace std;



int n,clk,dfn[2010],low[2010];

struct edge

{

    int v;

    edge *nxt;

} pool[4000100],*tp=pool,*fst[2010];



int getint()

{

    char ch;

    while (!isdigit(ch=getchar()));

    int x=ch-'0';

    for (; isdigit(ch=getchar()); x=x*10+ch-'0');

    return x;

}



void dfs(int x)

{

    dfn[x]=low[x]=++clk;

    for (edge *i=fst[x]; i; i=i->nxt)

        if (dfn[i->v])

            low[x]=min(low[x],dfn[i->v]);

        else

            dfs(i->v),low[x]=min(low[x],low[i->v]);

    if (x>1 && dfn[x]==low[x])

    {

        puts("NO");

        exit(0);

    }

}



int main()

{

    n=getint();

    repu(i,1,n)

        repu(j,1,n)

            if (getint())

                *tp=(edge){j,fst[i]},fst[i]=tp++;

    dfs(1);

    repu(i,1,n)

        if (!dfn[i])

        {

            puts("NO");

            return 0;

        }

    puts("YES");

    return 0;

}