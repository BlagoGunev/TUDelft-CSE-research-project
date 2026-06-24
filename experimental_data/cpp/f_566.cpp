#include<bits/stdc++.h>




#define lson k<<1
#define rson k<<1|1
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int dp[1000100];
int n,a;
int main()
{
    int k=1;
  scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
          a=read();
        dp[a]++;
    }
    for(int i=1000000;i>=1;i--)
    {
        int temp=dp[i];
        for(int j=i;j<=1000000;j+=i)
        {
            if(j!=i)
            {


            dp[i]=max(dp[i],dp[j]+temp);
        k=max(k,dp[i]);


        }
    }

    }
    printf("%d\n",k);
    return 0;
}