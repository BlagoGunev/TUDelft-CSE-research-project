#include <bits/stdc++.h>

using namespace std;



#define FOR(x,n) for(int x=0;x<n;x++)

using ll = long long;

using ii = pair<int,int>;



int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  

  int n; 

  cin >> n; 

  int orig[2][n];

  int want[2][n];

  int corig = 0, cwant = 0;

  FOR(i,2) FOR(j,n) {

    cin >> orig[i][j];

    corig += orig[i][j];

  }

  FOR(i,2) FOR(j,n) {

    cin >> want[i][j];

    cwant += want[i][j];

  }

  if(corig != cwant) {

    cout << "-1\n";

    exit(0);

  }

  ll apre = 0, bpre = 0, ans = 0;

  FOR(i,n) {

    if(orig[0][i]) apre++;

    if(want[0][i]) apre--;

    if(orig[1][i]) bpre++;

    if(want[1][i]) bpre--;

    if(apre > 0 && bpre < 0) {

      ans++;

      apre--;

      bpre++;

    }

    else if(apre < 0 && bpre > 0) {

      ans++;

      apre++;

      bpre--;

    }

    ans += abs(apre) + abs(bpre);

  }

  cout << ans << '\n';

}