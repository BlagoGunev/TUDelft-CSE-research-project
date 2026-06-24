#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll foo(ll n)
{
    ll N=n;
    while(n!=0)
    {
        N-=(n%10);
        n/=10;
    }
    return N;
}
int main()
{

  ll n,s;
  cin>>n>>s;
  ll l=0;
  ll h=n+1;
  ll mid;
  while(h-l>1)
  {
       mid=(l+h)/2;
      if(foo(mid)>=s)
        h=mid;
      else
      l=mid;
  }
  //cout<<h<<endl;
  cout<<(n-h+1);
}