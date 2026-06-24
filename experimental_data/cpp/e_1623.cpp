#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<cstdlib>
#include<utility>
using namespace std;
int fa[200000+5],chain[200000+5],dep[200000+5];
char s[200000+5];
int p[200000+5],l[200000+5],r[200000+5],m;
void dfs(int u)
{
    if (!u) return;
    if (l[u])
    {
        fa[l[u]]=u;dep[l[u]]=dep[u]+1;
        chain[l[u]]=chain[u];
    }
    dfs(l[u]);
    p[++m]=u;
    if (r[u])
    {
        fa[r[u]]=u;dep[r[u]]=dep[u]+1;
        chain[r[u]]=r[u];
    }
    dfs(r[u]);
}
bool vis[200000+5],minn[200000+5];
int main()
{
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for (i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    chain[1]=dep[1]=1;fa[1]=0;
    vis[0]=true;
    dfs(1);
    for (i=n-1;i>=1;i--)
        if (s[p[i]]<s[p[i+1]])
            minn[i]=true;
        else if (s[p[i]]==s[p[i+1]])
            minn[i]=minn[i+1];
    for (i=1;i<=n;i++)
    {
        if (minn[i])
        {
            if (dep[p[i]]-dep[chain[p[i]]]+1<=k&&vis[fa[chain[p[i]]]]&&!vis[p[i]])
            {
                int u=p[i];
                while (u==l[fa[u]]&&!vis[u])
                    vis[u]=true,k--,u=fa[u];
                if (!vis[u])
                    vis[u]=true,k--;
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("%c",s[p[i]]);
        if (vis[p[i]])
            printf("%c",s[p[i]]);
    }
    printf("\n");
}