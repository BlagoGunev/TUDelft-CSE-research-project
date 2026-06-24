#include <bits/stdc++.h>

using namespace std;

#define INF (1ll << 62)
#define pb push_back
#define ii pair<int,int>
#define OK cerr <<"OK"<< endl
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>

signed main () {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vector<int> arr(n);


  for(int &x:arr)
    cin >> x;


  sort(arr.begin(), arr.end());
 
  int f = 1;

  vector<int> ans(n);
  int l = 0, r = n-1;
  for(int i = 0; i < n; i++) {
    if(f)
      ans[l++] = i;
    else
      ans[r--] = i;
    f ^=1;
  }  

  // rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend());

  for(int x: ans)
    cout << arr[x] << ' ';  
  cout << endl;

}