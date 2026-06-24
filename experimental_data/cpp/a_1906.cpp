#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define iinf INT_MAX
#define linf LONG_LONG_MAX
#define pb push_back
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int> ,null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*
// find_by_order, order_of_key
*/
void fastio(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
void file(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  #endif
}
bool valid(int i, int j) { return (i >= 0 and j >= 0 and i < 3 and j < 3); }
int dx[] = {0, 1, 1, -1, -1, -1, 1, 0};
int dy[] = {1, 1, -1, 1, -1, 0, 0, -1};

// بسم الله //
void solve() {
  vector<string> a(3);
  for (int i = 0; i < 3; i++)
      cin >> a[i];

  vector<string> ans;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      char m1 = 'Z', m2 = 'Z';
      for (int k = 0; k < 8; k++){
        int x = dx[k] + i;
        int y = dy[k] + j;
        if(valid(x,y)){
          m2 = min(m2,max(m1, a[x][y]));
          m1 = min(m1, a[x][y]);
        }
      }
      string s;
  

      s.push_back(min(m1,m2));
      s.push_back(a[i][j]);
      s.push_back(max(m1,m2));
      //cout << s << endl;
      ans.push_back(s);
    }
  }
  sort(all(ans));
  cout << ans[0] << endl;
}

void solve1(){
  
}
int main()
{

  file();
  fastio();
  int t = 1;
  //cin >> t;
  while(t--){
      solve();
  }
}