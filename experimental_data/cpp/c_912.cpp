#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair <int, pair <int,int> > a[400004],e[100004];
int n,m,bo,i,d,j,ma,t,r,nr,x,h,s[100004],re[100004],l[100004];
long long z,Max;
bool ok,b[100004];
int main()
{
    scanf ("%d %d", &n, &m);
    scanf ("%d %d %d", &bo, &i, &d);
    ok=true;
    for (j=1;j<=n;j++)
    {
        scanf ("%d %d %d", &ma, &s[j], &re[j]);
        if (ma<=d)
            ok=false;
    }
    if (ok==false && i>=1)
        printf ("%d\n", -1);
    else
    {
        nr=0;
        for (j=1;j<=n;j++)
            l[j]=2000000010;
        r=0;
        for (j=1;j<=n;j++)
        {
            if (s[j]>d)
                b[j]=false;
            else
            {
                b[j]=true;
                r++;
                if (re[j]==0)
                    l[j]=2000000009;
                else
                {
                    t=(d-s[j])/re[j];
                    l[j]=t;
                }
            }
        }
        for (j=1;j<=m;j++)
            scanf ("%d %d %d", &e[j].first, &e[j].second.first, &e[j].second.second);
        sort (e+1,e+m+1);
        for (j=1;j<=m;j++)
        {
            t=e[j].first;
            x=e[j].second.first;
            h=e[j].second.second;
            if (l[x]<t)
            {
                a[++nr].first=l[x];
                a[nr].second.first=2;
                a[nr].second.second=x;
            }
            if (h>d)
                l[x]=t-1;
            else
            {
                a[++nr].first=t;
                a[nr].second.first=1;
                a[nr].second.second=x;
                if (re[x]==0)
                    l[x]=2000000009;
                else
                {
                    t=((d-h)/re[x])+t;
                    l[x]=t;
                }
            }
        }
        for (j=1;j<=n;j++)
        {
            if (l[x]<2000000010)
            {
                a[++nr].first=l[j];
                a[nr].second.first=2;
                a[nr].second.second=j;
            }
        }
        sort (a+1,a+nr+1);
        Max=(1LL)*r*bo;
        for (j=1;j<=nr;j++)
        {
            x=a[j].second.second;
            z=(1LL)*r*((0LL)+bo+(1LL)*a[j].first*i);
            if (z>Max)
                Max=z;
            if (a[j].second.first==2 && b[x]==true)
            {
                b[x]=false;
                r--;
            }
            else if (a[j].second.first==1 && b[x]==false)
            {
                b[x]=true;
                r++;
            }
            z=(1LL)*r*((0LL)+bo+(1LL)*a[j].first*i);
            if (z>Max)
                Max=z;
            if (a[j].first==2000000009)
                ok=false;
        }
        if (ok==false && i>=1)
            printf ("%d\n", -1);
        else
            printf ("%I64d\n", Max);
    }
    return 0;
}