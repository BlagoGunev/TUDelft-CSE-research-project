#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 2005;

int32_t main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
      cin>>a[i];
      cnt[a[i]]++;
    }
    int mx = 0;
    for(auto itr: cnt) mx = max(mx, itr.second);

      cout<<n - mx<<endl;
  }
  return 0;
}