#include <bits/stdc++.h>

using namespace std;

#define pf push_front

#define pb push_back

#define FOR(i,begin,end) for (LL i=begin;i<=end;i++)

#define rep(i,t) for (LL i=0;i<t;i++)

#define pii pair<LL,LL>

#define pi pair<pii,int>

#define X first

#define Y second 

#define fast cin.tie(0),cout.tie(0),ios::sync_with_stdio(false) 

typedef long long LL;

typedef unsigned long long int ulli;

const LL maxN=2e3+7,MOD=1e9+7,INF=1e18+7,N=5000+7;

LL n,k,pointer=1;

main()

{

  cin>>n>>k;

  if(k==0 && n==1)

    return cout<<"1\n",0;

  if((n/2)>k || n==1)

    return cout<<"-1\n",0;

  int help=(n-2)/2;

  cout<<(k-help)<<" "<<2*(k-help)<<" ";

  int cnt=0;

  while(cnt<help)

  {

    if(pointer!=(k-help) && pointer!=2*(k-help) && (pointer+1)!=(k-help) && (pointer+1)!=2*(k-help))

      cout<<pointer<<" "<<pointer+1<<" ",cnt++;

    pointer+=2;

  }

  if(n&1)

    cout<<999999997<<"\n";

  return cout<<"\n",0;

}