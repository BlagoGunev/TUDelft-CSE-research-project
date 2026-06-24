#include <cstdio>
#include <cstring>
#define max(a,b) (a>b?a:b)

int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    while(~scanf("%d",&n))
    {
        int cnt_1[110]={0};
        int cnt_0[110]={0};

        int a[110]={0};
        int dp[110]={0};// 0-1

        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            /*cnt_1[i]=cnt_1[i-1];
            cnt_0[i]=cnt_0[i-1];
            if(a) cnt_1[i]+=1;
            else cnt_0[i]+=1;*/
        }

        int m=-1,mm=-10;

        for(int i=1;i<=n;++i)
        {
            if(a[i])//1
            {
                dp[i]=max(dp[i-1]-1,-1);
            }
            else{//0
                dp[i]=max(dp[i-1]+1,1);
            }
            if(dp[i]>mm)
            {
                mm=dp[i];
                m=i;//角标
            }
        }
        int ans=0;

        if(dp[m]<=0)
        {
            for(int i=1;i<=n;++i) if(a[i]) ans+=1;
            ans-=1;
            printf("%d\n",ans);
            continue;
        }

        //for(int i=1;i<=n;++i) printf("%d ",dp[i]);printf("\n");

        int st=1;
        for(int i=m;i>0;--i)
        {
            if(dp[i]<0)
            {
                st=i+1;
                break;
            }
        }
        ans=0;

        //printf("%d %d\n",st,m);

        if(st<=m)
        {
            ans=(m-st+1+dp[m])/2;//反转部分0的个数

            for(int i=1;i<st;++i) if(a[i]) ans+=1;
            for(int i=m+1;i<=n;++i) if(a[i]) ans+=1;
        }
        else{
            for(int i=1;i<=n;++i) if(a[i]) ans+=1;
        }

        printf("%d\n",ans);
    }
    return 0;
}