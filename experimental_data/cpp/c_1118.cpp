#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int a[1000];
int cnt[1010];
int ans[25][25];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n*n; i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    if(n%2==0)
    {
        bool judge = false;
        int tmp = n/2;
        int cntt = 0;
        for(int i=1; i<1010; i++)
        {
            if(cnt[i]%4!=0)
            {
                judge = true;
                break;
            }
        }
        if(judge)
        {
            printf("NO\n");
            return 0;
        }
        for(int i=1; i<1010; i++)
        {
            while(cnt[i]>0)
            {
                cntt++;
                if(cntt%tmp!=0)
                    ans[cntt%tmp][cntt/tmp+1] = i;
                else
                    ans[tmp][cntt/tmp] = i;
                cnt[i] -= 4;
            }
        }
        printf("YES\n");
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                printf("%d ",ans[min(i,n+1-i)][min(j,n+1-j)]);
            }
            printf("\n");
        }

    }
    else
    {
        if(n==1)
        {
            printf("YES\n%d\n",a[0]);
            return 0;
        }
        int odd = 0;
        bool judge = false;
        int tmp = n/2;
        int cntt = 0;
        int cnttt = 0;
        for(int i=1; i<1010; i++)
        {
            if(cnt[i]%2==1)
            {
                if(odd==0)
                {
                    odd++;
                    ans[n/2+1][n/2+1] = i;
                    cnt[i]--;
                }
                else
                {
                    judge = true;
                    break;
                }
            }
            if(cnt[i]%4==2)
            {
                if(cnttt==n-1)
                {
                    judge = true;
                    break;
                }
                if(cnttt<tmp)
                {
                    ans[tmp+1][++cnttt] = i;
                }
                else
                {
                    cnttt++;
                    ans[cnttt-tmp][tmp+1] = i;
                }
                cnt[i]-=2;
            }
            else if(cnt[i]%4!=0)
            {
                judge = true;
                break;
            }
        }
        if(judge)
        {
            printf("NO\n");
            return 0;
        }
        for(int i=1; i<1010; i++)
        {
            while(cnt[i])
            {
                if(cntt < tmp*tmp)
                {
                    cntt++;
                    if(cntt%tmp!=0)
                        ans[cntt%tmp][cntt/tmp+1] = i;
                    else
                        ans[tmp][cntt/tmp] = i;
                    cnt[i] -= 4;
                }
                else
                {
                    if(cnttt<tmp)
                    {
                        ans[tmp+1][++cnttt] = i;
                    }
                    else
                    {
                        cnttt++;
                        ans[cnttt-tmp][tmp+1] = i;
                    }
                    cnt[i]-=2;
                }
            }
        }
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",ans[tmp+1-abs(tmp+1-i)][tmp+1-abs(tmp+1-j)]);
            }
            printf("\n");
        }
    }
}