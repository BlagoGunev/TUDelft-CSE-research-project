#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,q;
    cin >> n >> q;
    vector<int> x(n+1,0);
    for(int i=1;i<=n;i++){
      cin >> x[i];
      x[i]^=x[i-1];
    }
    map<int,set<int>> mp;
    for(int i=0;i<=n;i++){
      mp[x[i]].insert(i);
    }
    while(q>0){
      q--;
      int l,r;
      cin >> l >> r;
      l--;
      if(x[l]==x[r]){
        cout << "YES\n";
        continue;
      }
      else{
        int pr=(*mp[x[r]].lower_bound(l));
        auto it=mp[x[l]].lower_bound(r);
        it--;
        int pl=(*it);

        if(pr<pl){cout << "YES\n";}
        else{cout << "NO\n";}
      }
    }
  }
  return 0;
}