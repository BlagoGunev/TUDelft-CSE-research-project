#include <cstdio>

using namespace std;
int n,i,j,u,b[200004];
long long t,y,a[200004],m[200004],v[200004];
bool ok;
int main()
{
    scanf ("%d %I64d", &n, &t);
    for (i=1;i<=n;i++)
        scanf ("%I64d", &a[i]);
    for (i=1;i<=n;i++)
        scanf ("%d", &b[i]);
    for (i=1;i<=n;i++)
        m[i]=(0LL)+a[i]+t;
    for (i=1;i<=n;i++)
        v[i]=(1LL)*3*1000000000*1000000000;
    ok=true;
    b[0]=0;
    m[0]=0LL;
    u=1;
    for (i=1;i<=n;i++)
    {
        if (m[i-1]>=m[i])
            m[i]=(0LL)+m[i-1]+1;
        if (b[i]<i)
        {
            ok=false;
            break;
        }
        else if (b[i]<b[i-1])
        {
            ok=false;
            break;
        }
        else if ((b[i]!=b[i-1]) && (b[i]!=i))
        {
            for (j=u;j<b[i];j++)
            {
                y=(0LL)+a[j+1]+t;
                if (y>m[j])
                    m[j]=(0LL)+y;
            }
            u=b[i];
        }
        if (i==b[i])
            u=b[i]+1;
    }
    for (i=1;i<=n;i++)
    {
        if ((b[i]!=i) && (b[i]<n))
            v[b[i]]=(0LL)+a[b[i]+1]+t-1;
    }
    for (i=1;i<=n;i++)
    {
        if (m[i]>v[i])
        {
            ok=false;
            break;
        }
    }
    if (ok==false)
        printf ("No\n");
    else
    {
        printf ("Yes\n");
        for (i=1;i<=n;i++)
            printf ("%I64d ", m[i]);
        printf ("\n");
    }
    return 0;
}