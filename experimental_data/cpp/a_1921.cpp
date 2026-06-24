#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

void print(bool flag) {
  cout << (flag ? "YES" : "NO") << endl;
}

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;

PII w[4];

void solve() {
  for (int i = 0; i < 4; ++i) cin >> w[i].x >> w[i].y;
  sort(w, w+4);

  int dx = w[2].x - w[0].x;
  int dy = w[1].y - w[0].y;
  cout << dx * dy << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
//  int T = 1;
  while (T -- ) { solve(); }
  return 0;
}