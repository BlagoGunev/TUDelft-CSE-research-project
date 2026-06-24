#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;

template <class I>
inline void read(I &z)
{
    z=0;
    char c=getchar();int base=1;
    while (!isdigit(c) && c!='-') c=getchar();
    if (c=='-') c=getchar(),base=-1;
    while (isdigit(c)) z=z*10+c-'0',c=getchar();
    z*=base;
}

const int N=200010;

int T,a[N],b[N],n,m,da,db,ans,c[N],d[N],dp[N];

int work(int lc,int ld)
{
    fill(dp+1,dp+ld+1,0);
    int curc=0,curd=0;
    for (int i=1;i<=ld;++i)
    {
        while (curc+1<=lc && c[curc+1]<=d[i]) ++curc;
        while (d[i]-d[curd]+1>curc && curd<i) ++curd;
        dp[i]=max(dp[i-1]+(c[curc]==d[i]),i-curd+(curc!=0));
    }
    return dp[ld];
}

int main(int argc, char const *argv[])
{
    read(T);
    while (T--)
    {
        read(n),read(m);
        da=0,db=0;
        for (int i=1;i<=n;++i)
        {
            read(a[i]);
            if (a[i]<0) da=i;
        }

        for (int i=1;i<=m;++i)
        {
            read(b[i]);
            if (b[i]<0) db=i;
        }

        ans=0;
        fill(c+1,c+n-da+1,0);
        fill(d+1,d+m-db+1,0);
        for (int i=da+1;i<=n;++i) c[i-da]=a[i];
        for (int i=db+1;i<=m;++i) d[i-db]=b[i];
        if (n-da && m-db) ans+=work(n-da,m-db);

        //reverse

        fill(c+1,c+da+1,0);
        fill(d+1,d+db+1,0);
        for (int i=da;i;--i) c[da+1-i]=-a[i];
        for (int i=db;i;--i) d[db+1-i]=-b[i];
        if (da && db) ans+=work(da,db);
        printf("%d\n",ans);
    }
    return 0;
}