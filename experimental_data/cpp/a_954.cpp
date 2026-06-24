#include<stdio.h>
#include<string.h>
int main()
{
    int  n;
    char vis[1000];
    while(~scanf("%d",&n))
    {
        int i;
        scanf("%s",vis);
        int sum=0;
        for(i=0; i<n; i++)
        {
            if(vis[i]!=vis[i+1]&&i+1<n)
            {
                ++sum;
                i++;
            }
            else
            {
                sum++;
            }
        }
        printf("%d\n",sum);


    }
    return 0;
}