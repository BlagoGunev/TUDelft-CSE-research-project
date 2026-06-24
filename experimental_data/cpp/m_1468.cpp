#pragma GCC optimize("Ofast")

#pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"



using namespace std;



template <class T>

inline void setmax(T &a, T b) {

  if (a < b) {

    a = b;

  }

}



template <class T>

inline void setmin(T &a, T b) {

  if (a > b) {

    a = b;

  }

}



void solution() {

  int n;

  cin >> n;

  vector<vector<int>> a(n);

  vector<int> coor;

  for (int i = 0; i < n; i++) {

    int siz;

    cin >> siz;

    a[i].assign(siz, 0);

    for (int j = 0; j < siz; j++) {

      cin >> a[i][j];

      coor.emplace_back(a[i][j]);

    }

  }

  sort(coor.begin(), coor.end());

  coor.erase(unique(coor.begin(), coor.end()), coor.end());

  for (int i = 0; i < n; i++) {

    for (int &x : a[i]) {

      x = int(lower_bound(coor.begin(), coor.end(), x) - coor.begin());

    }

  }

  constexpr int block = 450;

  int m = int(coor.size());

  for (int i = 0; i < n; i++) {

    if (a[i].size() > block) {

      vector<bool> vis(m);

      for (int &x : a[i]) {

        vis[x] = true;

      }

      for (int j = 0; j < n; j++) {

        if (i != j) {

          int cnt = 0;

          for (int &x : a[j]) {

            if (vis[x]) {

              cnt++;

            }

          }

          if (cnt >= 2) {

            cout << i + 1 << " " << j + 1 << "\n";

            return;

          }

        }

      }

    }

  }

  vector<vector<int>> pos(m);

  for (int i = 0; i < n; i++) {

    if (a[i].size() <= block) {

      for (int &x : a[i]) {

        pos[x].emplace_back(i);

      }

    }

  }

  vector<int> sus(m, -1);

  for (int v = 0; v < m; v++) {

    for (int i : pos[v]) {

      for (int &x : a[i]) {

        if (x != v) {

          if (sus[x] == -1) {

            sus[x] = i;

          } else {

            cout << sus[x] + 1 << " " << i + 1 << "\n";

            return;

          }

        }

      }

    }

    for (int i : pos[v]) {

      for (int &x : a[i]) {

        sus[x] = -1;

      }

    }

  }

  cout << "-1\n";

}



signed main() {

  ios::sync_with_stdio(0);

  cin.tie(0);

#ifdef DEBUG

  freopen("Input.txt", "r", stdin);

  auto start = chrono::high_resolution_clock::now();

#endif

  signed testcases = 1;

  cin >> testcases;



  for (int test = 0; test < testcases; test++) {

    // cout << "Case #" << test << ": ";

    solution();

  }



#ifdef DEBUG

  auto end = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

  cout << endl << "_ Execution time: [ " << duration << "ms ] _" << endl;

#endif



  return 0;

}