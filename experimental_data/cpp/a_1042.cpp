#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main(){
    fio;
  ll n,m;
  cin>>n>>m;
   vector<ll>a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  sort(a.begin(),a.end());
  ll max1=a[n-1],s=0;
  for(ll i=0;i<n;i++)
  {
      s+=abs(a[i]-max1);
  }
  if(n==1)
    cout<<a[0]+m<<" ";
  else if(s==0)
  {
    cout<<a[0]+(m / n) + ((m % n) != 0)<<" ";

  }
  else if(s>=m)
    cout<<a[n-1]<<" ";
  else
    {
        cout<<a[n-1]+((m-s) / n) + (((m-s) % n) != 0)<<" ";

    }
  cout<<a[n-1]+m;
}