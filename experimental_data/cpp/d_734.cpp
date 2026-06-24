#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=500050;
int dis[8];
char tp[8];
int main()
{
    int n,x,y,X,Y;
    char t;
    scanf("%d",&n);
    scanf("%d%d",&X,&Y);
    for(int i=0;i<8;i++)tp[i]='N';
    for(int i=0;i<8;i++)dis[i]=2e9+1;
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%c%d%d",&t,&x,&y);
        getchar();
        x-=X,y-=Y;
        if(x==y)
        {
            if(x>0)
            {
                if(dis[0]>x)
                {
                    dis[0]=x;
                    tp[0]=t;
                }
            }
            else
            {
                if(dis[4]>-x)
                {
                    dis[4]=-x;
                    tp[4]=t;
                }
            }
        }
        else if(x==-y)
        {
            if(x>0)
            {
                if(dis[2]>x)
                {
                    dis[2]=x;
                    tp[2]=t;
                }
            }
            else
            {
                if(dis[6]>y)
                {
                    dis[6]=y;
                    tp[6]=t;
                }
            }
        }
        else if(!x)
        {
            if(y>0)
            {
                if(dis[7]>y)
                {
                    dis[7]=y;
                    tp[7]=t;
                }
            }
            else
            {
                if(dis[3]>-y)
                {
                    dis[3]=-y;
                    tp[3]=t;
                }
            }
        }
        else if(!y)
        {
            if(x>0)
            {
                if(dis[1]>x)
                {
                    dis[1]=x;
                    tp[1]=t;
                }
            }
            else
            {
                if(dis[5]>-x)
                {
                    dis[5]=-x;
                    tp[5]=t;
                }
            }
        }
    }
    bool ck=false;
    for(int i=0;i<8;i+=2)if(tp[i]=='B'||tp[i]=='Q')ck=true;
    for(int i=1;i<8;i+=2)if(tp[i]=='R'||tp[i]=='Q')ck=true;
    puts(ck? "YES":"NO");
	return 0;
}