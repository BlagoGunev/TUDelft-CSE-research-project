#include <stdio.h>
#include <string.h>

const int maxn = 10010;

char s[maxn+1];
int a[maxn+1],b[maxn+1],
    df[maxn+1];
int m,n;
int result;

void init()
{
    int i,j,k,ge,zz,zy,t;
    result=0;
    scanf("%d%d",&m,&n);
    for (i=1; i<=n; ++i)
        df[i]=0;
    for (i=1; i<=m; ++i)
    {
        scanf("%s",s+1);
        zz=zy=-1;
        a[0]=-1;
        for (j=1; j<=n; ++j)
        {
            if (s[j]=='1')
                zy=j;
            a[j]=a[j-1];
            if (s[j]=='1')
                a[j]=j;
        }
        b[n+1]=-1;
        for (j=n; j>=1; --j)
        {
            if (s[j]=='1')
                zz=j;
            b[j]=b[j+1];
            if (s[j]=='1')
                b[j]=j;
        }
        if (zz==-1)
        {
            result=-1;
            return;
        }
        for (j=1; j<=n; ++j)
        {
            t=1000000000;
            if ((a[j]!=-1)&&(j-a[j]<t))
                t=j-a[j];
            if ((b[j]!=-1)&&(b[j]-j<t))
                t=b[j]-j;
            if (zz+n-j<t)
                t=zz+n-j;
            if (n-zy+j<t)
                t=n-zy+j;
            df[j]+=t;
        }
    }
    result=1000000000;
    for (j=1; j<=n; ++j)
        if (df[j]<result)
            result=df[j];
}

void output()
{
    printf("%d\n",result);
}

int main()
{
    init();
    output();
    return 0;
}