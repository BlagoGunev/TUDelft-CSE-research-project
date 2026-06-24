// Problem: D. Kill Anton
// Contest: Codeforces - Codeforces Round #723 (Div. 2)
// URL: https://codeforces.com/contest/1526/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cti(char x) {
  if (x == 'A') return 0;
  if (x == 'N') return 1;
  if (x == 'T') return 2;
  return 3;
}
char itc(int x) {
  if (x == 0) return 'A';
  if (x == 1) return 'N';
  if (x == 2) return 'T';
  return 'O';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int freq[4];
    memset(freq, 0, sizeof freq);
    int n = 0;
    for (char x : str) {
      if (x == 'A') freq[0]++;
      if (x == 'N') freq[1]++;
      if (x == 'T') freq[2]++;
      if (x == 'O') freq[3]++;
      n++;
    }
    vector<int> perm;
    perm.push_back(0);
    perm.push_back(1);
    perm.push_back(2);
    perm.push_back(3);
    ll mn = 0;
    int ans = 0;
    for (int r = 0; r < 24; r++) {
      ll tot = 0;
      int numDone[4];
      memset(numDone, 0, sizeof numDone);
      int first[4];
      first[perm[0]] = 0;
      for (int i = 1; i < 4; i++) {
        first[perm[i]] = first[perm[i - 1]] + freq[perm[i - 1]];
      }
      for (int i = 0; i < n; i++) {
        int spotsMove = 0;
        for (int j = 3; j >= 0; j--) {
          spotsMove += numDone[perm[j]];
          if (perm[j] == cti(str[i])) {
            break;
          }
        }
        tot += first[cti(str[i])] + spotsMove - i;
        numDone[cti(str[i])]++;
      }
      if (tot > mn) {
        ans = r;
        mn = tot;
      }
      next_permutation(perm.begin(), perm.end());
    }
    perm.clear();
    perm.push_back(0);
    perm.push_back(1);
    perm.push_back(2);
    perm.push_back(3);
    for (int i = 0; i < ans; i++) {
      next_permutation(perm.begin(), perm.end());
    }
    for (int i = 0; i < 4; i++) {
      for (int k = 0; k < freq[perm[i]]; k++) {
        cout << itc(perm[i]);
      }
    }
    cout << "\n";
  }
}