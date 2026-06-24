#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define deb(x) cout<<#x<<" "<<x<<endl;
//#define deb(x) cout<<#x<<" "<<x<<" ";
const ll INF = 1e9 + 7;
#define MEM(a,b) memset((a),(b),sizeof(a))
const ll Max_Valid = 1e12;

int main(){
  fastio;
  ll T;
  cin>>T;
  while (T--) {
    ll n,x,a,b;
    std::cin >> n >> x >> a >> b;
    if(a > b) swap(a,b);
    ll ans = n-1;

    // deb(a);
    // deb(b);
    // deb(ans);

    //ll can_do = (a-1) + (n-b) ;
    ans = min( (b-a) + x , ans);
    std::cout << ans << '\n';
  }
  return 0;
}