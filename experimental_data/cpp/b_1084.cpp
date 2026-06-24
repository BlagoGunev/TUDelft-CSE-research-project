#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
using namespace std;
typedef long long int lld;
typedef vector<lld> vi;
typedef pair<lld, lld> pi;
#define F first
#define S second
#define N 1000007
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (lld i = a; i < b; i++)
lld r, j, l, m, n, s, q, i, k, t, w,p, timer;string s1, s2;
lld a[N];
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>s;
  p=MOD;
  rep(i,1,n+1)
  {
    cin>>a[i];k+=a[i];
    p=min(p,a[i]);
  }
  if(k<s)cout<<-1;
  else
  {
    rep(i,1,n+1)
    {
      s-=(a[i]-p);
    }
    if(s<=0)cout<<p;
    else
    {
     // cout<<s;
      rep(i,1,n+1)
      {
        a[i]=p-(s/n);
        //cout<<a[i]<<' ';
      }
      s%=n;
      //cout<<s;
      if(s==0)cout<<a[1];
      else cout<<a[1]-1;
    }
  }
}