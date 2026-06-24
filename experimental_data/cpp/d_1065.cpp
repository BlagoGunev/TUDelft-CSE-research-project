#include<bits/stdc++.h>
using namespace std;
int a[20][20],n;
int w,xx[12]={0,1,1,-1,-1,2,2,-2,-2};
int yy[12]={0,2,-2,2,-2,1,-1,1,-1};
struct dataa
{
    int x,y;
}ch[110];
struct data2
{
    int x,cnt;
    bool operator<(const data2&r)const
    {
        if(x==r.x) return cnt<r.cnt;
        return x<r.x;
    }
}d[110][5];
dataa arr[1000];
void pro(int sx,int sy,int ex,int ey)
{
    int w2=0,sw111=0,i,j,kx,ky,sw1=0,sw2=0,sw3=0,sw12=0,sw23=0,sw31=0,sw21=0,sw32=0,sw13=0,sw11=0,sw22=1,sw33=0;
    //1
    if(abs(sx-ex)==1 && abs(sy-ey)==2) sw1=1;
    if(abs(sx-ex)==2 && abs(sy-ey)==1) sw1=1;
    if(sx==ex || sy==ey) sw2=1;
    if(abs(sx-ex)==abs(sy-ey)) sw3=1;
    for(i=1;i<=8;i++)
    {
        kx=sx+xx[i]; ky=sy+yy[i];
        if(kx<1 || ky<1 || kx>n || ky>n) continue;
        for(j=1;j<=8;j++)
        {
            w2++;
            arr[w2].x=kx+xx[j]; arr[w2].y=ky+yy[j];
        }
        if(abs(kx-ex)==1 && abs(ky-ey)==2) sw11=1;
        if(abs(kx-ex)==2 && abs(ky-ey)==1) sw11=1;
        if(kx==ex || ky==ey) sw12=1;
        if(abs(kx-ex)==abs(ky-ey)) sw13=1;
    }
    for(i=-10;i<=10;i++)
    {
        kx=sx+i; ky=sy;
        if(kx<1 || ky<1 || kx>n || ky>n) continue;
        if(abs(kx-ex)==1 && abs(ky-ey)==2) sw21=1;
        if(abs(kx-ex)==2 && abs(ky-ey)==1) sw21=1;
        if(kx==ex || ky==ey) sw22=1;
        if(abs(kx-ex)==abs(ky-ey)) sw23=1;
    }
    for(i=-10;i<=10;i++)
    {
        kx=sx; ky=sy+i;
        if(kx<1 || ky<1 || kx>n || ky>n) continue;
        if(abs(kx-ex)==1 && abs(ky-ey)==2) sw21=1;
        if(abs(kx-ex)==2 && abs(ky-ey)==1) sw21=1;
        if(kx==ex || ky==ey) sw22=1;
        if(abs(kx-ex)==abs(ky-ey)) sw23=1;
    }
    for(i=-10;i<=10;i++)
    {
        kx=sx+i; ky=sy+i;
        if(kx<1 || ky<1 || kx>n || ky>n) continue;
        if(abs(kx-ex)==1 && abs(ky-ey)==2) sw31=1;
        if(abs(kx-ex)==2 && abs(ky-ey)==1) sw31=1;
        if(kx==ex || ky==ey) sw32=1;
        if(abs(kx-ex)==abs(ky-ey)) sw33=1;
    }
    for(i=-10;i<=10;i++)
    {
        kx=sx+i; ky=sy-i;
        if(kx<1 || ky<1 || kx>n || ky>n) continue;
        if(abs(kx-ex)==1 && abs(ky-ey)==2) sw31=1;
        if(abs(kx-ex)==2 && abs(ky-ey)==1) sw31=1;
        if(kx==ex || ky==ey) sw32=1;
        if(abs(kx-ex)==abs(ky-ey)) sw33=1;
    }
    if(sw1==1)
    {
        d[w][1]=min(d[w][1],{d[w-1][1].x+1,d[w-1][1].cnt});
        d[w][1]=min(d[w][1],{d[w-1][2].x+2,d[w-1][2].cnt+1});
        d[w][1]=min(d[w][1],{d[w-1][3].x+2,d[w-1][3].cnt+1});
    }
    if(sw2==1)
    {
        d[w][2]=min(d[w][2],{d[w-1][1].x+2,d[w-1][1].cnt+1});
        d[w][2]=min(d[w][2],{d[w-1][2].x+1,d[w-1][2].cnt});
        d[w][2]=min(d[w][2],{d[w-1][3].x+2,d[w-1][3].cnt+1});
    }
    if(sw3==1)
    {
        d[w][3]=min(d[w][3],{d[w-1][1].x+2,d[w-1][1].cnt+1});
        d[w][3]=min(d[w][3],{d[w-1][2].x+2,d[w-1][2].cnt+1});
        d[w][3]=min(d[w][3],{d[w-1][3].x+1,d[w-1][3].cnt});
    }
    if(sw11==1)
    {
        d[w][1]=min(d[w][1],{d[w-1][1].x+2,d[w-1][1].cnt});
        d[w][1]=min(d[w][1],{d[w-1][2].x+3,d[w-1][2].cnt+1});
        d[w][1]=min(d[w][1],{d[w-1][3].x+3,d[w-1][3].cnt+1});
    }
    if(sw21==1)
    {
        d[w][1]=min(d[w][1],{d[w-1][1].x+4,d[w-1][1].cnt+2});
        d[w][1]=min(d[w][1],{d[w-1][2].x+3,d[w-1][2].cnt+1});
        d[w][1]=min(d[w][1],{d[w-1][3].x+4,d[w-1][3].cnt+2});
    }
    if(sw31==1)
    {
        d[w][1]=min(d[w][1],{d[w-1][1].x+4,d[w-1][1].cnt+2});
        d[w][1]=min(d[w][1],{d[w-1][2].x+4,d[w-1][2].cnt+2});
        d[w][1]=min(d[w][1],{d[w-1][3].x+3,d[w-1][3].cnt+1});
    }

    if(sw12==1)
    {
        d[w][2]=min(d[w][2],{d[w-1][1].x+3,d[w-1][1].cnt+1});
        d[w][2]=min(d[w][2],{d[w-1][2].x+4,d[w-1][2].cnt+2});
        d[w][2]=min(d[w][2],{d[w-1][3].x+3,d[w-1][3].cnt+2});
    }
    if(sw22==1)
    {
        d[w][2]=min(d[w][2],{d[w-1][1].x+3,d[w-1][1].cnt+1});
        d[w][2]=min(d[w][2],{d[w-1][2].x+2,d[w-1][2].cnt});
        d[w][2]=min(d[w][2],{d[w-1][3].x+3,d[w-1][3].cnt+1});
    }
    if(sw32==1)
    {
        d[w][2]=min(d[w][2],{d[w-1][1].x+4,d[w-1][1].cnt+2});
        d[w][2]=min(d[w][2],{d[w-1][2].x+4,d[w-1][2].cnt+2});
        d[w][2]=min(d[w][2],{d[w-1][3].x+3,d[w-1][3].cnt+1});
    }

    if(sw13==1)
    {
        d[w][3]=min(d[w][3],{d[w-1][1].x+3,d[w-1][1].cnt+1});
        d[w][3]=min(d[w][3],{d[w-1][2].x+4,d[w-1][2].cnt+2});
        d[w][3]=min(d[w][3],{d[w-1][3].x+4,d[w-1][3].cnt+2});
    }
    if(sw23==1)
    {
        d[w][3]=min(d[w][3],{d[w-1][1].x+4,d[w-1][1].cnt+2});
        d[w][3]=min(d[w][3],{d[w-1][2].x+3,d[w-1][2].cnt+1});
        d[w][3]=min(d[w][3],{d[w-1][3].x+4,d[w-1][3].cnt+2});
    }
    if(sw33==1)
    {
        d[w][3]=min(d[w][3],{d[w-1][1].x+3,d[w-1][1].cnt+1});
        d[w][3]=min(d[w][3],{d[w-1][2].x+3,d[w-1][2].cnt+1});
        d[w][3]=min(d[w][3],{d[w-1][3].x+2,d[w-1][3].cnt});
    }
    for(i=1;i<=w2;i++)
    {
        if(arr[i].x>n || arr[i].y>n || arr[i].x<1 || arr[i].y<1) continue;
        kx=arr[i].x; ky=arr[i].y;
        if(abs(kx-ex)==1 && abs(ky-ey)==2) sw111=1;
        if(abs(kx-ex)==2 && abs(ky-ey)==1) sw111=1;
    }
    if(sw111==1)
    {
        d[w][1]=min(d[w][1],{d[w-1][1].x+3,d[w-1][1].cnt});
        d[w][1]=min(d[w][1],{d[w-1][2].x+4,d[w-1][2].cnt+1});
        d[w][1]=min(d[w][1],{d[w-1][3].x+4,d[w-1][3].cnt+1});
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            ch[a[i][j]].x=i, ch[a[i][j]].y=j;
        }
    }
    for(i=1;i<n*n;i++)
    {
        w++; d[w][1]=d[w][2]=d[w][3]={1000000,0};
        pro(ch[i].x,ch[i].y,ch[i+1].x,ch[i+1].y);
    }
    data2 p={1000000,0};
    p=min(p,d[w][1]);
    p=min(p,d[w][2]);
    p=min(p,d[w][3]);
    printf("%d %d",p.x,p.cnt);
    return 0;
}