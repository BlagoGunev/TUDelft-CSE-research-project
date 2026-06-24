#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

#define N 100010

typedef long long ll;

struct Point{

    int x,y;

}p1[N],p2[N];

bool cmp1(Point &a,Point &b)

{

    return a.x<b.x||a.x==b.x&&a.y<b.y;

}

bool cmp2(Point &a,Point &b)

{

    return a.y<b.y||a.y==b.y&&a.x<b.x;

}

struct rec{

    int s,t,mid,ls,rs,cnt;

    void init(int l,int r)

    {

        s=l;t=r;mid=s+t>>1;

        ls=rs=cnt=0;

    }

}seg[N*20];

int xx[N],yy[N],a[10],b[10],root[N];

int n,cnt=0,zx,zy,x1,x2,y1,y2;

void build(int &x,int s,int t)

{

    if(!x) x=++cnt;

    seg[x].init(s,t);

    if(s!=t)

    {

        build(seg[x].ls,s,seg[x].mid);

        build(seg[x].rs,seg[x].mid+1,t);

    }

}

void updata(int &x,int rot,int id,int w)

{



    if(!x)

    {

        x=++cnt;

        seg[x].init(seg[rot].s,seg[rot].t);

    }

    if(seg[x].s==seg[x].t)

    {

        seg[x].cnt=seg[rot].cnt+w;

        return;

    }

    if(id<=seg[x].mid)

    {

        seg[x].rs=seg[rot].rs;

        updata(seg[x].ls,seg[rot].ls,id,w);

    }

    else

    {

        seg[x].ls=seg[rot].ls;

        updata(seg[x].rs,seg[rot].rs,id,w);

    }

    seg[x].cnt=seg[seg[x].ls].cnt+seg[seg[x].rs].cnt;

}

int query(int x,int l,int r)

{

    if(l>r) return 0;

    if(l<=seg[x].s&&seg[x].t<=r) return seg[x].cnt;

    int q=0;

    if(l<=seg[x].mid) q+=query(seg[x].ls,l,r);

    if(seg[x].mid<r) q+=query(seg[x].rs,l,r);

    return q;

}

bool solve()

{

    int sum=0;

    for(int i=1;i<=3;++i)

        sum+=a[b[i]];

    if(p1[sum+1].x==p1[sum].x) return false;

    x1=p1[sum].x;

    for(int i=4;i<=6;++i)

        sum+=a[b[i]];

    if(p1[sum+1].x==p1[sum].x) return false;

    x2=p1[sum].x;

    sum=0;

    for(int i=0;i<3;++i)

        sum+=a[b[i*3+1]];

    if(p2[sum+1].y==p2[sum].y) return false;

    y1=p2[sum].y;

    for(int i=0;i<3;++i)

        sum+=a[b[i*3+2]];

    if(p2[sum+1].y==p2[sum].y) return false;

    y2=p2[sum].y;

    if(query(root[x1],1,y1)!=a[b[1]]) return false;

    if(query(root[x1],y1+1,y2)!=a[b[2]]) return false;

    if(query(root[x2],1,y1)-query(root[x1],1,y1)!=a[b[4]]) return false;

    if(query(root[x2],y1+1,y2)-query(root[x1],y1+1,y2)!=a[b[5]]) return false;

    return true;

}

int main()

{

    scanf("%d",&n);

    for(int i=1;i<=n;++i)

    {

        scanf("%d%d",&p1[i].x,&p1[i].y);

        xx[i]=p1[i].x;yy[i]=p1[i].y;

    }

    sort(xx+1,xx+n+1);

    sort(yy+1,yy+n+1);

    zx=unique(xx+1,xx+n+1)-xx-1;

    zy=unique(yy+1,yy+n+1)-yy-1;

    for(int i=1;i<=n;++i)

    {

        p1[i].x=lower_bound(xx+1,xx+zx+1,p1[i].x)-xx;

        p1[i].y=lower_bound(yy+1,yy+zy+1,p1[i].y)-yy;

        p2[i].x=p1[i].x;p2[i].y=p1[i].y;

    }

    build(root[0],1,zy);

    sort(p1+1,p1+n+1,cmp1);

    sort(p2+1,p2+n+1,cmp2);

    int last=root[0],tmp;

    for(int i=1;i<=n;++i)

    {

        tmp=0;

        updata(tmp,last,p1[i].y,1);

        root[p1[i].x]=last=tmp;

    }

    for(int i=1;i<=9;++i)

    {

        scanf("%d",&a[i]);

        b[i]=i;

    }

    bool flag=false;

    do

    {

        if(solve())

        {

            flag=true;

            break;

        }

    }while(next_permutation(b+1,b+10));

    if(flag)

    {

        printf("%.8f %.8f\n",(xx[x1]+xx[x1+1])/2.0,(xx[x2]+xx[x2+1])/2.0);

        printf("%.8f %.8f\n",(yy[y1]+yy[y1+1])/2.0,(yy[y2]+yy[y2+1])/2.0);

    }

    else printf("-1\n");

    return 0;

}