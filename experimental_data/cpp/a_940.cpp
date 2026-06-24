#include<stdio.h>
#include<algorithm>
using namespace std;
int num[110];
int main()
{
    int x,y,ans=0;
    scanf("%d%d",&x,&y);
    for(int i=0;i<x;i++)
    {
        scanf("%d",&num[i]);
    }
    sort(num,num+x);
    for(int i=0;i<x;i++)
    {
        int tem=1;
        for(int j=i+1;j<x;j++)
        {
            if(num[j]-num[i]<=y)
            {
                tem++;
            }
            else
            {
                break;
            }
        }
        if(ans<tem)
        {
            ans=tem;
        }
    }
    printf("%d\n",x-ans);
    return 0;
}