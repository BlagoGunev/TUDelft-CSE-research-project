//g++ -std=c++11 ./SC.cpp -o ./p
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define rz resize
#define len length
#define nl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

inline int dig(ll r){
  int x=0;
  while(r)
    r/=10,x++;
  return x;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  ll l,r;
  cin>>l>>r;

  int ld=dig(l),rd = dig(r),i;

  ll x=0,ans=-1;
  for(i=1;i<=10;i++){
    x*=10,x+=9;
    if( l<= x/2 and (x+1)/2 <= r){
      ans = max(ans, (x/2)*((x+1)/2) );
    }
  }
  
  ll y=0;

  for(i=1;i<=ld;i++)
    y*=10,y+=9;
  ans = max(ans, l*(y-l) );

  y=0;
  for(i=1;i<=rd;i++)
    y*=10,y+=9;
  ans = max(ans, r*(y-r) );
  
  cout << ans << nl;

  return 0;
};