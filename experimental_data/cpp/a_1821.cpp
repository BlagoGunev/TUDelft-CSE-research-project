#include <bits/stdc++.h> 
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 #define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

ll INF=2e18;

void solve() {
string s;cin>>s;
if(s[0]=='0') {
  cout<<0<<endl;
  return ;
}
ll k=1;
for(ll i=0;i<s.size();i++) {
  if(s[i]=='?') {
    if(i==0) k*=9;
    else k*=10;
  }
}

cout<<k<<endl;




}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
    ll t;cin>>t;
    for(ll i=0;i<t;i++) {
        solve();
    }
}