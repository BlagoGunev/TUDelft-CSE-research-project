#include <bits/stdc++.h>

#include<string.h>

#define MAX 1000005

#define MOD 1000000007

#define MA 1200000

#define PI 3.14159265358979323846264338327950

//const int  MAXA=1e15+1;

typedef long long int  ll;

const ll INF=1e9;

using namespace std;

const  int maxn=1e5+5;

const int ma=1e9+5;

ll dp[105];

int main()

{

    //freopen("input.txt","r+",stdin);

    //freopen("output.txt","w+",stdout);

    ios::sync_with_stdio(0);

    cin.tie(0);

    ll n,m,i,j,x,ans=0;

    cin>>n>>m;

    for(i=0;i<n;i++)

        dp[i]=INF;

    for(i=0;i<n;i++)

    {

        for(j=0;j<m;j++)

        {

            cin>>x;

            dp[i]=min(dp[i],x);

        }

        ans=max(ans,dp[i]);

    }

    cout<<ans;

    return 0;

}