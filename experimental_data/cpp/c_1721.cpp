#include<bits/stdc++.h>

using namespace std;

#define ll long long int

#define fo for(int i=0;i<n;++i){cin>>v[i];}

#define rep(i,a,b) for(int i=a;i<b;i++)

#define vout(a,b,v) for(int i=a;i<b;i++){cout<<v[i]<<" ";}cout<<"\n";

#define vect(type1,name) vector<type1> name

#define pb push_back

#define full(x) x.begin(),x.end()

#define Pi 3.1415926535897932382626



void solve()

{

  ll n;

  cin>>n;

  vector<ll> a(n),b(n),mx,mn;

  for(int i=0 ; i<n;i++)

  {

    cin>>a[i];

  }

  for(int i=0 ; i<n;i++)

  {

    cin>>b[i];

  }

  // For d max

  ll j = n-1;

  mx.push_back(b[j]-a[j]);

  for(int i= n-1 ; i>0 ;i--)

  {

    if(b[i-1]<a[i])

    {

      j = i-1;

    }

    mx.push_back(b[j]-a[i-1]);

  }

  reverse(full(mx));



  // For d min

  for(int i=0 ; i<n;i++)

  {

    ll st =0 , en = n-1 , temp= i;

    while(st<=en)

    {

      ll mid = (st+en)/2;

      if(b[mid]>=a[i])

      {

        temp = mid;

        en = mid-1;

      }

      else

      {

        st = mid +1;

      }

    }

    mn.push_back(b[temp]-a[i]);

  }

  vout(0,mn.size(),mn);

  vout(0,mx.size(),mx);

  

}

int main(){

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  cout.tie(NULL);

  ll t;

  t=1;

  cin>>t;

  while(t--)

  {

    solve();

  }

  return 0;

}