#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define INF 105

using namespace std;
struct MIR {
    int l,r,n;
}   T[INF],F[INF];
int L[2],R[2],cel=0,flo=0;
int X[4]={0,0,1,1};
int Y[4]={0,1,0,1};
int Z[4]={0,100,100,0};
bool cmp(MIR a,MIR b)
{
    return a.l<b.l;
}
int LL_(int ll,double x0,double l)
{
    double x=ll-x0;
    return ceil(x/l-1e-8);
}
int RR_(int r,double x0,double l)
{
    double x=r-x0;
    return ceil(x/l+1e-8);
}
int Hx(double x)
{
    for (int i=1;i<=flo;i++)
        if (F[i].l<=x && F[i].r>=x)
            return 0;
    return 1;
}
int Hy(double y)
{
    for (int i=1;i<=cel;i++)
        if (T[i].l<=y && T[i].r>=y)
            return 0;
    return 1;
}
int main()
{
    int i,n,m,t,x,y,now,ans=0,big=0;
    char str[10];
    double l,x0,y0,tmp,x1,y1;
    for (i=1,scanf("%d%d%d",&L[0],&R[0],&n);i<=n;i++)
    {
        if (scanf("%d%s%d%d",&m,str,&x,&y),str[0]=='T')
            ++cel,T[cel].l=x,T[cel].r=y,T[cel].n=m;
        else ++flo,F[flo].l=x,F[flo].r=y,F[flo].n=m;
        big=max(y-x,big);
    }
    L[1]=100-L[0],R[1]=100-R[0];
    //sort(T+1,T+cel+1,cmp);
    //sort(F+1,F+flo+1,cmp);
    for (int h=0;h<4;h++)
    {
        for (t=0;true;t++)
        {
            int fl=0;
            l=200.0/(double)(t*200+L[X[h]]+R[Y[h]]+Z[h]);
            l*=100000.0;
            if (l*2.0<=big) break;
            x0=l/200.0*L[X[h]],y0=x0+l/2.0;
            if (h>1) tmp=x0,x0=y0,y0=tmp;
            for (x1=x0;x1<=100000.0;x1+=l)
                if (Hx(x1)) {
                    fl=1; break;
                }
            if (fl) continue;
            for (y1=y0;y1<=100000.0;y1+=l)
                if (Hy(y1)) {
                    fl=1; break;
                }
            if (fl) continue;
            for (now=0,i=1;i<=flo;i++)
            {
                x=LL_(F[i].l,x0,l),y=RR_(F[i].r,x0,l);
                if (y-x>1) fl=1;
                if (fl) break;
                if (y-x==1) now+=F[i].n;
            }
            if (fl) continue;
            for (i=1;i<=cel;i++)
            {
                x=LL_(T[i].l,y0,l),y=RR_(T[i].r,y0,l);
                if (y-x>1) fl=1;
                if (fl) break;
                if (y-x==1) now+=T[i].n;
            }
            if (fl) continue;
            //if (now>ans) {
            //    printf("x0=%lf l=%lf :\n",x0,l);
            //    printf("y0=%lf l=%lf :\n",y0,l);
            //}
            ans=max(ans,now);
            //printf("%d\n",ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
80 72 9
15 T 8210 15679
10 F 11940 22399
50 T 30600 44789
50 F 32090 36579
5 F 45520 48519
120 F 49250 55229
8 F 59700 80609
35 T 61940 64939
2 T 92540 97769
*/