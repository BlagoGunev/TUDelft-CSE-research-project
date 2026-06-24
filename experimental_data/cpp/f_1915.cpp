#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<deque>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<ii> v;
    for(int i = 0; i < n; ++i){
      int a, b; cin >> a >> b;
      v.pb(mp(a, b));
    }
    sort(v.begin(), v.end());
    ordered_set st;
    ll ans = 0;
    for(int i = 0; i < v.size(); ++i){
      ans += st.order_of_key(-v[i].se);
      st.insert(-v[i].se);
    }
    cout << ans << '\n';
  }
  return 0;
}