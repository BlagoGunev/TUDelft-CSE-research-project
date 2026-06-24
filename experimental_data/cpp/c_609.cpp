#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int readInt() {
  int t;
  scanf("%d", &t);
  return t;
}
#define INT(x) int x = readInt();

long long readLong() {
  long long t;
  scanf("%lld", &t);
  return t;
}
#define LL(x) long long x = readLong();

char buf[100 * 1000 + 1];
string readString() {
  scanf("%s", buf);
  return string(buf);
}
#define STR(x) string x = readString();


int main() {
  INT(n);
  vector<int> cnt(20001);
  for (int i = 0; i < n; i++) {
    INT(a);
    cnt[a]++;
  }
  int ans = 0;
  for (int L = 0, R = 20000; R - L > 1;) {
    if (cnt[L] == 0) {
      L++;
    } else if (cnt[R] == 0) {
      R--;
    } else {
      int q = min(cnt[L], cnt[R]);
      cnt[L] -= q;
      cnt[L + 1] += q;
      cnt[R] -= q;
      cnt[R - 1] += q;
      ans += q;
    }
  }
  printf("%d\n", ans);
  return 0;
}