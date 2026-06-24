#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 100005;
const int inf = 10000005;
int fa[MAXN],v[MAXN],dp[MAXN],dp2[MAXN],Q[MAXN];
int F[MAXN],N[MAXN * 2],V[MAXN * 2];
int n,m,d,tot;
bool mk[MAXN];
void add(int a,int b)
{
    ++tot;
    V[tot] = b;
    N[tot] = F[a];
    F[a] = tot;
}
void up(int x,int y)
{
    if (y > dp[x]) dp2[x] = dp[x], dp[x] = y;
    else if (y > dp2[x]) dp2[x] = y;
}
int solve()
{
    int hd = 0,tl = 1;
    for (int i = 0; i < n; i ++)
        fa[i] = -1, v[i] = 0;
    v[0] = 1,Q[1] = 0;
    while (hd != tl)
    {
        int nw = Q[++hd],nx;
        for (int p = F[nw]; p > 0; p = N[p])
            if (!v[nx = V[p]])
                v[nx] = 1,Q[++tl] = nx,fa[nx] = nw;
    }
    for (int i = 0; i < n; i ++)
        dp[i] = dp2[i] = -inf;
    for (int i = n; i > 0; i --)
    {
        int nw = Q[i],nx;
        if (mk[nw]) up(nw,0);
        for (int p = F[nw]; p > 0; p = N[p])
            if((nx = V[p]) != fa[nw])
                up(nw,dp[nx] + 1);
    }
//    for (int i = 0; i < n; i ++)
//        printf("first round i = %d dp = %d dp2 = %d\n",i,dp[i],dp2[i]);
    for (int i = 1; i <= n; i ++)
    {
        int nw =  Q[i],nx;
        for (int p  =F[nw]; p > 0; p = N[p])
            if (fa[nw] != (nx = V[p]))
            {
                int x = (dp[nw] == dp[nx] + 1) ? dp2[nw] : dp[nw];
                up(nx,x + 1);
            }
    }
//    for (int i = 0; i < n; i ++)
//        printf("i = %d dp = %d fm = %d\n",i,dp[i],dp2[i]);
    int res = 0;
    for (int i = 0; i < n; i ++)
        res += (dp[i] <= d);
    return res;
        
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&d);
    int x;
    for (int i = 0; i < n; i ++)
        mk[i] = 0;
    for (int i = 0; i < m; i ++)
        scanf("%d",&x), mk[--x] = 1;
        
    tot = 0; int a,b;
    for (int i = 0; i < n - 1 ; i ++)
        scanf("%d%d",&a,&b),
        add(--a,--b),add(b,a);
    
    printf("%d\n",solve());
    return 0;
}