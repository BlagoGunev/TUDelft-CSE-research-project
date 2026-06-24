#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>


using namespace std;
typedef long long ll;

int main()
{
    vector<ll> sf(3);
    cin>>sf[0]>>sf[1]>>sf[2];
    ll x;
    cin>>x;
    sort(sf.begin(),sf.end());
    ll h = sf[1] - x;
    ll ans = max(sf[0]- h,0LL);
  //  cout<<ans<<endl;
    h = sf[1]+x;
    ans+= max(h - sf[2],0LL);
    cout<<ans<<endl;

}