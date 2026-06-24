#include <stdio.h>
#include <string.h>

#define maxn 100100
int sum[maxn];
int data[maxn];

int main()
{
    int n,k,x,i,ans,cnt;
    int flag,st;
    while (scanf("%d%d",&n,&k) == 2)    {
        memset(data,0,sizeof(0));
        ans = 0;    cnt = 0;    st = -1;
        for (i = 0 ; i < n ; i++)   {
            scanf("%d",&sum[i]);
            if (cnt == k)
                continue;
            if (data[sum[i]] == 0)  {
                flag = i;
                cnt++;
            }
            data[sum[i]]++;
        }
        for (i = 0 ; i < flag ; i++)
            if (data[sum[i]] > 1)   {
                st = i;
                data[sum[i]]--;
            } else {
                break;
            }
        if (st == -1)   {
            if (cnt == k)
                printf("1 %d\n",flag + 1);
            else
                printf("-1 -1\n");
        } else {
            if (cnt == k)
                printf("%d %d\n",st + 2,flag + 1);
            else
                printf("-1 -1\n");
        }
    }
    return 0;
}