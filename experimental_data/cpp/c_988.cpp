#include <bits/stdc++.h>
using namespace std;
typedef int lld;
typedef vector<lld> vi;
typedef pair<lld,lld> pi;
#define F first
#define S second
#define PB push_back
#define MOD 1000000007
#define MP make_pair
#define rep(i,a,b) for (lld i = a; i < b; i++)
lld l,y,n,m,i,z,s,e,q,j,k,g,b,d,t,h,timer;string s1,s2;
lld x[1000009];
unordered_map<lld,pi>ma;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  cin>>k;
  rep(j,0,k)
  {
    cin>>n;
    s=0;
    rep(i,0,n)
    {
      cin>>x[i];
      s+=x[i];
    }
    rep(i,0,n)
    {
      pi p1={0,0};
      if(ma[s-x[i]].F!=j+1&&ma[s-x[i]]!=p1)
      {
        l=s-x[i];
        cout<<"YES\n";
        cout<<ma[l].F<<" "<<ma[l].S<<endl;
        cout<<j+1<<" "<<i+1<<endl;
        return 0;
      }
      else
      {
        ma[s-x[i]]={j+1,i+1};
      }
    }
  }
  cout<<"NO";
}