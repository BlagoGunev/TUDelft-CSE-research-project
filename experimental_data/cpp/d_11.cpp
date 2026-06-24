#include <bits/stdc++.h>

using namespace std;

#define pf pop_front

#define pb push_back

#define FOR(i,begin,end) for (LL i=begin;i<=end;i++)

#define rep(i,t) for (LL i=0;i<t;i++)

#define pii pair<LL,LL>

#define X first

#define Y second

#define INF 1LL<<60

typedef long long LL;

typedef unsigned long long int ulli;

const LL maxN=20,N=(1<<19)+7,MOD=1e9+7,Mod=1e9+6;

LL n,x,y,z,help,dp[N][maxN],cnt,s,m,ans;

bool a[maxN][maxN];

int left_most_bit(LL x)

{

  for(LL i=n-1;i>=0;i--)

  {

    if((x>>i)&1)

      return i;

  }

}

int main()

{ 

  cin.tie(0);

  ios::sync_with_stdio(false);

  cin>>n>>m;

  FOR(i,1,m)

    cin>>x>>y,x--,y--,a[x][y]=true,a[y][x]=true;

  rep(i,n)

    dp[1<<i][i]=1;

  for(LL i=1;i<(1<<n);i++)

  {

    if(__builtin_popcountll(i)>1)

    {

      cnt=0;

      for(LL j=n-1;j>=0;j--)

      {

        if((i>>j)&1)

        {

          cnt++;

          if(cnt!=1)

          {

            rep(x,n)

            {

              if(a[j][x])

                dp[i][j]+=dp[i^(1<<j)][x];

            }

          }

          else

            dp[i][j]=0;

        }

        else

          dp[i][j]=0;

      }

    }

    if(__builtin_popcountll(i)>2)

    {

      s=left_most_bit(i);

      rep(j,n)

      {

        if(a[j][s])

          ans+=dp[i][j];

      }

    }

  }

  return cout<<ans/2<<"\n",0;

}