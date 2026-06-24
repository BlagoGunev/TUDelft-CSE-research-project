#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int n,m,Min;
int c[100100];
struct Node
{
    int id,x;
}haha[100100],hehe[100100];
bool cmp(Node a,Node b)
{
    if(a.x==b.x) return a.id<b.id;
    else return a.x>b.x;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        Min=100100;
        memset(haha,0,sizeof(haha));
        for(int i=1;i<=100010;i++)
        haha[i].id=i;
        for(int i=1;i<=n;i++)
        {scanf("%d",&c[i]);Min=min(Min,c[i]);}
        int a,b;
        hehe[0].id=hehe[0].x=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            a=c[a];
            b=c[b];
            if(a>b) swap(a,b);
            hehe[i].x=a;
            hehe[i].id=b;
        }
        sort(hehe+1,hehe+m+1,cmp);
        for(int i=1;i<=m;i++)
        {
            //printf("%d %d\n",hehe[i].x,hehe[i].id);
            if((hehe[i].x!=hehe[i-1].x)||(hehe[i].id!=hehe[i-1].id))
            {
                if(hehe[i].x!=hehe[i].id)
                {
                    a=hehe[i].x;
                    b=hehe[i].id;
                    haha[a].x++;
                    haha[b].x++;
                }
            }
        }
        //for(int i=1;i<=10;i++)
        //printf("%d %d\n",haha[i].id,haha[i].x);
        sort(haha+1,haha+100010,cmp);
        if(haha[1].x==0)
        printf("%d\n",Min);
        else
        printf("%d\n",haha[1].id);
    }
    return 0;
}