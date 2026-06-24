#ifndef ONLINE_JUDGE
  #include "bits/debug.cpp"
  #else
  #define debug(...)
  #define debugArr(...)
  #endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define vardclr ll t,m,n,p,q,i,j,k,x,y,z,l,r;
#define tc cin>>t;while(t--)
#define fri(z) for(i=0;i<z;i++)
#define cs cout<<"Case "<<casee<<": ";casee++;
#define pb                push_back
#define mem(x, i)    memset(x, i, sizeof(x))
#define all(x)        x.begin(), x.end()

const double pi = 2 * acos(0.0);
const ll N = 1e6+6;
const ll mod=1e9+7;

ll cil(ll num, ll div){
  return (num / div) + !!(num % div);
}
ll cili(ll num, ll div){
  return (num+div-1)/div;
}
void vout(vector<ll> &v, ll n)
{
  for (ll i = 0 ; i <n ; i++)
  {
    if (i == n-1)
      cout << v[i] << endl;
    else
      cout << v[i] << " ";
  }
}

int main()
{
  fast
  vardclr
  ll casee = 1;
  string s = "";
  char ch;
  tc
  {
    cin>>n;
    if(n==1)
    {
      cout<<1<<endl;continue;
    }

    if(n&1)cout<<-1<<endl;
    else
    {
      vector<ll>v(n);
      ll num=n;
      for(i=0;i<n;i+=2)
      {
         v[i]=num;
         num-=2;
      }
      num=1;
      for(i=1;i<n;i+=2)
      {
        v[i]=num;
        num+=2;
      }
      vout(v,v.size());
    }

  }
}