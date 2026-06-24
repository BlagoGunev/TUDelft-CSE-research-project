#include <stdio.h>

#include <algorithm>

#include <math.h>

#include <vector>

#include <set>

using namespace std;

#define eps 1e-10

const double pi=acos(-1.0);

int sgn(double x)

{

    if(x>eps)return 1;

    else if(x<-eps)return -1;

    return 0;

}

int ma[400010],ld[400010];

void pur(int i,int x)

{

    ma[i]+=x;

    ld[i]+=x;

}

void pushd(int i)

{

    if(ld[i]==0)return;

    pur(i*2,ld[i]);

    pur(i*2+1,ld[i]);

    ld[i]=0;

}

void build(int i,int l,int r)

{

    ma[i]=ld[i]=0;

    if(l+1==r)return;

    int m=(l+r)>>1;

    build(i*2,l,m);

    build(i*2+1,m,r);

}

void modify(int i,int l,int r,int L,int R,int x)

{

    if(R<=l||r<=L)return;

    if(L<=l&&r<=R)

    {

        pur(i,x);

        return;

    }

    int m=(l+r)>>1;pushd(i);

    modify(i*2,l,m,L,R,x);

    modify(i*2+1,m,r,L,R,x);

    ma[i]=max(ma[i*2],ma[i*2+1]);

}

void add(int l,int r,int m,int z)

{

    if(l<=r)modify(1,1,m+1,l,r+1,z);

    else

    {

        modify(1,1,m+1,l,m+1,z);

        modify(1,1,m+1,1,r+1,z);

    }

}

double toz(double x)

{

    if(sgn(-pi-x)>=0)x+=pi*2;

    if(sgn(x-pi)>0)x-=pi*2;

    return x;

}

void jiao(int ox,int oy,int x,int y,double r,double&L,double&R)

{

    x-=ox;y-=oy;

    double d=sqrt(1ll*x*x+1ll*y*y);

    double a=acos(d/2/r),b=atan2(y,x);

    L=toz(b-a);R=toz(b+a);

}

struct SJd

{

    double z;int i,x;SJd(){}

    SJd(double Z,int I,int X)

    {z=Z;i=I;x=X;}

}px[100010];

bool operator<(const SJd&a,const SJd&b)

{

    return a.z<b.z;

}

int X[50010],Y[50010],N,K;

double getdis(int a,int b)

{

    int dx=X[a]-X[b],dy=Y[a]-Y[b];

    return sqrt(1ll*dx*dx+1ll*dy*dy);

}

int wl[50010],wr[50010];set<int> se[1002][1002];

double si;

void getxy(double x,double y,int&X,int&Y)

{

    x+=1e8;y+=1e8;

    X=x/si;Y=y/si;

}

bool check(int u,int l,double r)

{

    vector<int> ve;

    int wx,wy;getxy(X[u],Y[u],wx,wy);

    for(int i=-1;i<=1;i++)

    {

        for(int j=-1;j<=1;j++)

        {

            int x=wx+i,y=wy+j;

            if(x>=0&&y>=0)

                for(int z:se[x][y])

                    if(z!=u&&sgn(getdis(u,z)-r*2)<=0)ve.push_back(z);

        }

    }

    sort(ve.begin(),ve.end());

    int s=ve.size();

    if(s==0)return false;

    for(int i=0;i<s;i++)

    {

        double L,R;

        jiao(X[u],Y[u],X[ve[i]],Y[ve[i]],r,L,R);

        px[i]=SJd(L,i,0);px[i+s]=SJd(R,i,1);

    }

    sort(px,px+s*2);int m=0;

    for(int i=0;i<s*2;i++)

    {

        if(i==0||sgn(px[i].z-px[i-1].z)>0)m+=1;

        if(px[i].x==0)wl[px[i].i]=m;

        else wr[px[i].i]=m;

    }

    build(1,1,m+1);

    for(int i=0,j=0;i<s;i++)

    {

        while(j<s&&ve[j]<=ve[i]+l)

        {

            add(wl[j],wr[j],m,1);

            j+=1;

        }

        if(ma[1]>=K-1)return true;

        add(wl[i],wr[i],m,-1);

    }

    return false;

}

int main()

{

    int T,n,m;

    scanf("%d",&T);

    while(T--)

    {

        scanf("%d%d%d",&n,&m,&K);

        N=n;m-=1;

        for(int i=1;i<=n;i++)

            scanf("%d%d",&X[i],&Y[i]);

        si=2e8*sqrt(double(K)/(m+1));

        double R=si;

        for(int i=1,j=1;i<=n;i++)

        {

            if(i-m-1>=1)

            {

                int w=i-m-1,x,y;

                getxy(X[w],Y[w],x,y);

                se[x][y].erase(w);

            }

            while(j<=n&&j<=i+m)

            {

                int x,y;

                getxy(X[j],Y[j],x,y);

                se[x][y].insert(j++);

            }

            if(!check(i,m,R))continue;

            double L=0;

            for(int s=0;s<50;s++)

            {

                double M=(L+R)/2;

                if(check(i,m,M))R=M;

                else L=M;

            }

        }

        printf("%.10lf\n",R);

        for(int i=1;i<=n;i++)

        {

            int x,y;getxy(X[i],Y[i],x,y);

            se[x][y].clear();

        }

    }

    return 0;

}