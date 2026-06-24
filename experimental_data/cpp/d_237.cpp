#include <cstdio>
#include <algorithm>

using namespace std;

struct grana
{
    int p,k;
};

bool com (grana a,grana b)
{
    return a.p<b.p;
}

grana g[200005];

int poc[100005];

int n,a,b;
char visit[100005];
int back[100005];
int num[100005];
int cnt;

void dfs(int v,int oda)
{
    visit[v]=1;
    if (v>1)
        printf("2 %d %d\n",v,oda);
    if (v>1)
    {
        cnt++;
        num[v]=cnt;
        back[cnt]=num[oda];
    }
    for (int i=poc[v]; i<poc[v+1]; i++)
    if (visit[g[i].k]==0)
    dfs(g[i].k,v);
}

int main()
{
    num[1]=1;
    scanf("%d",&n);
    for (a=1; a<n; a++)
    {
        scanf("%d%d",&g[a].p,&g[a].k);
        g[a+n-1].p=g[a].k;
        g[a+n-1].k=g[a].p;
    }
    int gnum=(n-1)*2;
    sort(g+1,g+1+gnum,com);
    for (a=gnum; a>=1; a--)
    poc[g[a].p]=a;
    poc[n+1]=gnum+1;

    printf("%d\n",n-1);
    dfs(1,0);
    for (a=2; a<=n-1; a++)
    printf("%d %d\n",a,back[a]);
}