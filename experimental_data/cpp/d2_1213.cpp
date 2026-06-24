#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 2e5+5;
int vis[MAXN]={0};
int dis[MAXN]={0};
int num[MAXN]={0};
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&dis[i]);
    }
    sort(dis,dis+N);
    for(int i=0;i<N;i++)
    {
        int cnt=0;
        while (dis[i])
        {
            if(vis[dis[i]]<M)
            {
                vis[dis[i]]++;
                num[dis[i]]+=cnt;
            }
            cnt++;
            dis[i]/=2;
        }
    }
    int minn=num[1];
    for(int i=1;i<MAXN;i++)
    {
        if(vis[i]>=M)
        {
            minn=min(minn,num[i]);
        }
    }
    printf("%d\n",minn);
    return 0;
}