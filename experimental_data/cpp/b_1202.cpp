#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[2000010];
int dp[10][10][10][10];
int cnt[10][10];
int main()
{
    memset(dp,0x3f,sizeof(dp));
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    for(int i1=0;i1<10;i1++){
        for(int k=0;k<10;k++)
        for(int l=0;l<10;l++){
            if(k==0&&l==0) continue;
            dp[i][j][i1][(i1+k*i+l*j)%10]=min(dp[i][j][i1][(i1+k*i+l*j)%10],k+l);
        }
    }
    for(int i=2;i<=n;i++){
        cnt[s[i-1]-'0'][s[i]-'0']++;
    }
    for(int i=0;i<10;i++,puts(""))
    {
        for(int j=0;j<10;j++){
            ll sum=0;
            for(int i1=0;i1<10;i1++)
            for(int j1=0;j1<10;j1++){
                if(cnt[i1][j1]&&dp[i][j][i1][j1]>1e9){
                    sum=-1;goto out;
                }
                sum+=cnt[i1][j1]*(dp[i][j][i1][j1]-1);
            }
            out:;
            printf("%lld ",sum);
        }
    }



    return 0;
}