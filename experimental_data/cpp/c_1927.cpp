#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m, k;
  cin>>n>>m>>k;
  map<int, int> mp1, mp2;

  for(int i=0;i<n;i++) {
    int temp; cin>>temp;
    if(temp <= k) mp1[temp]++;
  }
  for(int i=0;i<m;i++) {
    int temp; cin>>temp;
    if(temp <= k) mp2[temp]++;
  }

  int count1 = 0, count2 = 0;
  if(mp1.size() + mp2.size() < k or mp1.size() < k/2 or mp2.size() < k/2) cout<<"NO"<<endl;
  else {
    for(auto it : mp1) mp2[it.first]++;
    if(mp2.size() == k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}




signed main() {
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}