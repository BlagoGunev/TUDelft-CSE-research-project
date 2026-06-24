/*
  http://codeforces.com/problemset/problem/362/B
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 3000

int n, m;

int dirty_steps[MAXN];
int pos = 1;

int main(){
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    cin >> dirty_steps[i];

    if(dirty_steps[i] == 1 || dirty_steps[i] == n){
      cout << "NO" << endl;
      return 0;
    }
  }

  if(m < 3){
    cout << "YES" << endl;
    return 0;
  }

  sort(dirty_steps, dirty_steps+m);

  for(int i=0; i<m-2; i++){
    if(dirty_steps[i+1] == dirty_steps[i]+1 && dirty_steps[i+2] == dirty_steps[i]+2){
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}