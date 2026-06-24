#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

const int N=2000000;
struct word{int l,r,sum;}g[N];

int i,j,n,m,k,s0,s1,ans,len,x,y,z,cur,curans,tot,tot2,res,tp;
int v[N],a[N],b[N],d[N],f[N],pre[N],h[N];

void init()
{
    for (;;)
    {
        char ch=getchar();k=0;
        if (ch==',') k=3;
        else if (ch>='0'&&ch<='9') k=2; else
            if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) k=1;
        if (k==0) break;
        a[++n]=ch;b[n]=k;
    }
    for (i=1;i<=n;i=j+1)
    {
        j=i;
        while (j!=n&&b[j+1]==b[j]) j++;
        if (b[i]==3) continue;
        if (b[i]==1)
        {
            m++;g[m].l=i;g[m].r=j;
            continue;
        }
        if (b[i]==2)
        {
            cur=0;
            for (k=i;k<=j;k++) cur=cur*10+a[k]-48;
            g[m].sum=cur;
        }
    }
    ans=1;
    for (i=1;i<=m;i++)
    {
        while (tp!=0&&g[d[tp]].sum==0) tp--;
        if (tp==0) {d[++tp]=i;f[i]=1;continue;}
        g[d[tp]].sum--;d[++tp]=i;f[i]=tp;
        if (tp>ans) ans=tp;
    }
    printf("%d\n",ans);
    
    for (i=m;i>=1;i--){pre[i]=h[f[i]];h[f[i]]=i;}
    for (i=1;i<=ans;i++)
    {
        for (int p=h[i];p>0;p=pre[p])
        {
            for (j=g[p].l;j<=g[p].r;j++) printf("%c",a[j]);
            if (pre[p]==0) printf("\n");else printf(" ");
        }
    }
    //for (i=1;i<=m;i++) printf("%d %d %d %d\n",g[i].l,g[i].r,g[i].sum,f[i]);
}
void work()
{
    
}
int main()
{
    //freopen("1.in","r",stdin);
    
    init();
    work();
    return 0;
}