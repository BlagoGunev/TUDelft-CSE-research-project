#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

typedef long long ll;
ll A[300000];
ll pows[40];
int gots[40];
int ptricks[40];
int ntricks[40];

void solve() {
  int N;
  cin >> N;
  ll tot = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    tot += A[i];
  }
  if (tot % N != 0) {
    cout << "No" << endl;
    return;
  }
  for (int j = 0; j <= 30; ++j) ntricks[j] = ptricks[j] = gots[j] = 0;
  ll avg = tot / N;
  for (int i = 0; i < N; ++i) {
    A[i] -= avg;
    bool neg = false;
    if (A[i] == 0) continue;
    if (A[i] < 0) { A[i] = -A[i]; neg = true; }
    int first = -1;
    int second = -1;
    for (int j = 0; j <= 30; ++j) {
      if (A[i] & pows[j]) {
        if (first == -1) {
          first = j;
        } else if (second != -1) {
          cout << "No" << endl;
          return;
        }
      } else {
        if (first != -1 && second == -1) second = j;
      }
    }
    gots[first] += (neg ? 1 : -1);
    gots[second] += (neg ? -1 : 1);
    if (first + 1 == second) {
      if (neg) ptricks[second] += 1;
      else ntricks[second] += 1;
    }
  }
  int zeros = 0;
  for (int j = 30; j > 0; --j) {
    if (gots[j] > 0) {
      if (ntricks[j] >= gots[j]) {
        gots[j-1] += 2 * gots[j];
        zeros -= gots[j];
        gots[j] = 0;
      } else {
        cout << "No" << endl;
        return;
      }
    }
    if (gots[j] < 0) {
      if (ptricks[j] >= -gots[j]) {
        gots[j-1] += 2 * gots[j];
        zeros -= gots[j];
        gots[j] = 0;
      } else {
        cout << "No" << endl;
        return;
      }
    }
  }
  assert(zeros == 0);
  cout << "Yes" << endl;
}

int main() {
  pows[0] = 1;
  for (int i = 1; i <= 30; ++i) pows[i] = pows[i-1] * 2LL;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) solve();
  return 0;
}