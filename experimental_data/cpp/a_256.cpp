/*
 *
 * File:   p256AAlmostArithmeticalProgression.cpp
 * Author: Andy Y.F. Huang
 * Created on December 16, 2012, 10:31 AM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Unsolved
 * @author Andy Y.F. Huang
 */
namespace p256AAlmostArithmeticalProgression {
int seq[4444];
vector<int> pos[4444], vals;

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &seq[i]);
    vals.push_back(seq[i]);
  }
  if (len == 1) {
    puts("1");
    return;
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int i = 0; i < len; i++) {
    seq[i] = lower_bound(vals.begin(), vals.end(), seq[i]) - vals.begin();
    pos[seq[i]].push_back(i);
  }
  int ans = 0;
  for (int i = 0; i < (int) vals.size(); i++) {
    ans = max(ans, (int) pos[i].size());
    for (int j = i + 1; j < (int) vals.size(); j++) {
      int a = 1, b = 1, cnt = 2, curpos, cur;
      if (pos[i].front() < pos[j].front()) {
        curpos = pos[j].front();
        cur = 0;
      }
      else {
        curpos = pos[i].front();
        cur = 1;
      }
      while (true) {
        if (cur == 0) {
          while (a < (int) pos[i].size() && pos[i][a] < curpos)
            a++;
          if (a < (int) pos[i].size()) {
            curpos = pos[i][a];
            cnt++;
          }
          else break;
        }
        else {
          while (b < (int) pos[j].size() && pos[j][b] < curpos)
            b++;
          if (b < (int) pos[j].size()) {
            curpos = pos[j][b];
            cnt++;
          }
          else break;
        }
        cur ^= 1;
      }
      ans = max(ans, cnt);
    }
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
//    freopen("input.txt", "w", stdout);
//    printf("%d\n", 4000);
//    for (int i = 1; i <= 4000; i++)
//      printf("%d ", i % 2);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  p256AAlmostArithmeticalProgression::solve();
  return 0;
}