#include <bits/stdc++.h>

#define pb push_back

#define mp make_pair

#define mx 1004

#define mod 1000000007

#define int long long

#define pi acos(-1.0)

#define BLOCK 320

#define inf 1000000000000000001



using namespace std;





int dp[mx];

int n,ara[mx];

int cum[mx];



main()

{

//    freopen("input.txt","r",stdin);

//    freopen("output.txt","w",stdout);



    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);





    cin>>n;



    for(int i=1;i<=n;i++)cin>>ara[i];

    dp[1]=2;

    int ans=2;

    cum[1]=2;

    for(int i=2;i<=n;i++){

        dp[i] = (cum[i-1]-cum[ ara[i]-1 ]+2)%mod;

        cum[i]= (cum[i-1]+dp[i])%mod;

    }





    cout<<(cum[n]+mod)%mod<<endl;



    return 0;

}