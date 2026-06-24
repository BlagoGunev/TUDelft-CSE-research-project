#pragma GCC optimize("Ofast")

#pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"



using namespace std;



template <class S>

inline void setmax(S &a, S b) {

  if (a < b) {

    a = b;

  }

}



template <class S>

inline void setmin(S &a, S b) {

  if (a > b) {

    a = b;

  }

}



void solution() {

  int n;

  cin >> n;

  vector<int> a(n), cnt(n);

  for (int i = 0; i < n; i++) {

    cin >> a[i];

    cnt[--a[i]]++;

  }

  if (*max_element(cnt.begin(), cnt.end()) * 2 > n + 1) {

    cout << "-1\n";

    return;

  }

  int res = 0;

  fill(cnt.begin(), cnt.end(), 0);

  for (int i = 1; i < n; i++) {

    if (a[i - 1] == a[i]) {

      res++;

      cnt[a[i]] += 2;

    }

  }

  cnt[a[0]]++;

  cnt[a[n - 1]]++;

  setmax(res, *max_element(cnt.begin(), cnt.end()) - 2);

  cout << res << "\n";

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