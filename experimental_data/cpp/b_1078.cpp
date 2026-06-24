#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,a[105],num[105],ans=0,zl=0;
bool dp[105][10005];

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    //freopen("in.txt","r",stdin);
    cin>>n;
    memset(num,0,sizeof num);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(num[a[i]]==0)
            zl++;
        num[a[i]]++;
    }
    if(zl<=2)
    {
        cout<<n<<endl;
        return 0;
    }
    for(int i=1;i<=100;i++)
    {
        if(num[i])
        {
            memset(dp,0,sizeof dp);
            dp[0][0]=1;
            for(int j=1;j<=n;j++)
            {
                if(a[j]==i)
                    continue;
                for(int k=i*num[i];k>=a[j];k--)
                    for(int l=num[i];l>=1;l--)
                        dp[l][k]|=dp[l-1][k-a[j]];
            }
            for(int j=1;j<=num[i];j++)
            {
                if(dp[j][j*i])
                    break;
                else
                    ans=max(ans,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}