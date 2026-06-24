#include <bits/stdc++.h>

using namespace std;

#define pf pop_front

#define pb push_back

#define FOR(i,begin,end) for (ulli i=begin;i<=end;i++)

#define rep(i,t) for (LL i=0;i<t;i++)

#define pii pair<LL,LL>

#define X first

#define Y second

typedef long long LL;

typedef unsigned long long int ulli;

const ulli maxN=2e3+37,N=1e2+17,inf=500017,MOD=1e9+7;

LL n,x,y,ans,d[maxN],h,a[maxN];

bool bad;

int main()

{

  cin>>n>>h;

  FOR(i,1,n)

    cin>>a[i];

  FOR(i,1,n)

  {

    x=min(i,n+1-i);

    if(h-a[i]>=0 && h-a[i]<=x)

      continue;

    else

    	bad=true;

  }

  FOR(i,2,n)

  {

    if(abs(a[i]-a[i-1])>1)

     	bad=true;

  }

  if(bad)

    return cout<<"0\n",0;

  d[1]=1;

  FOR(i,2,n)

  {

  	d[i]=(d[i-1]%MOD);

    if(a[i]==a[i-1])

      d[i]*=((h-a[i-1]+1)%MOD),d[i]%MOD;

    else

    {

      if(a[i]>a[i-1])

        d[i]*=((h-a[i-1])%MOD),d[i]%=MOD; 

    }

  }

  return cout<<d[n]%MOD<<"\n",0;

}