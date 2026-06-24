#include <bits/stdc++.h>



using namespace std;





void solve() {

     int N; cin >> N;

     vector<int> v(N);

     for (auto& e : v)

          cin >> e;

     set<int>p;

     for (int i = N - 1; i >= 0; --i)

     {

          if (p.insert(v[i]).second != 1) {

               cout << (i + 1) << endl;

               return;

          }

     }

     cout << 0 << endl;

}

int main() {

     ios_base::sync_with_stdio(false);

     cin.tie(0);

     int t;

     cin >> t;

     while (t--) {

          solve();

     }



}