#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#define LL __int64
#define mod 2015
#define N 200008

using namespace std;
struct node
{
    int x,y,dif;
    bool operator <(const node& xx)const
    {
        return dif<xx.dif;
    }
};
set <node> ss;
set <node> ::iterator it;
int y[100008],w[100008];
struct node2
{
    int x,y;
}ans[100008];
int main()
{
    int n,i,ymax=-1;
    scanf("%d",&n);
    memset(y,-1,sizeof(y));
    for(i=0;i<n;i++)
    {
        int xx,yy;
        scanf("%d%d",&xx,&yy);
        ymax=max(ymax,yy);
        y[yy]=max(y[yy],xx);
    }
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    ss.clear();ss.insert((node){y[ymax],ymax,ymax-y[ymax]});
    for(i=ymax-1;i>=0;i--)
        if(y[i]>y[i+1])
            ss.insert((node){y[i],i,i-y[i]});
    for(i=n-1;i>=0;i--)
    {
        it=ss.lower_bound((node){0,0,w[i]});
        if(it!=ss.end()&&(*it).dif==w[i])
        {
            ans[i].x=(*it).x;
            ans[i].y=(*it).y;
            //printf("%d %d\n",(*it).x,(*it).y);
            ss.erase(it);--y[ans[i].y];
            if(ans[i].x>0&&ans[i].x-1>y[ans[i].y+1])
                ss.insert((node){ans[i].x-1,ans[i].y,ans[i].y-ans[i].x+1});
            if(ans[i].y>0&&ans[i].x==y[ans[i].y-1])
                ss.insert((node){ans[i].x,ans[i].y-1,ans[i].y-1-ans[i].x});
        }
        else    break;
    }
    if(i>=0)    puts("NO");
    else
    {
        puts("YES");
        for(i=0;i<n;i++)
            printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}