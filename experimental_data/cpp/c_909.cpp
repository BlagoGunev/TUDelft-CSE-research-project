#include <bits/stdc++.h>
using namespace std;
const int N=5001,MOD=1e9+7;
int A[N],n,dp[2][N],cnt=0,rez;
char x;
int main()
{
    scanf("%d",&n);
    dp[0][0]=1;
    cin>>x;
    if(x=='f'){
        A[0]=1;
        cnt=1;
    }
    else
        A[0]=0;
    for(int i=1;i<n;i++){
        cin>>x;
        if(A[i-1]){
   //         cout<<"Cnt "<<cnt<<endl;
            for(int i=1;i<=cnt;i++){
                dp[1][i]=dp[0][i-1];
            }
        }
        else{
            int sum=0;
            for(int j=cnt;j>=0;j--){
                sum=(sum+dp[0][j])%MOD;
                dp[1][j]=sum;
            }
        }
        for(int j=0;j<=cnt;j++){
            dp[0][j]=dp[1][j];
            dp[1][j]=0;
      //      printf("%d ",dp[0][j]);
        }
   //     printf("\n");
        if(x=='f'){
            cnt++;
            A[i]=1;
        }
        else{
            A[i]=0;
        }
    }
    for(int i=0;i<=cnt;i++){
        rez=(rez+dp[0][i])%MOD;
    }
    cout<<rez;
    return 0;
}