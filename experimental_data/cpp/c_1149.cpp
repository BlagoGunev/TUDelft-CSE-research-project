#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

const int N = 200050;
typedef long long LL;

int readInt() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f *= -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

int max(int a, int b) { return a < b ? b : a; }
int max(int a, int b, int c) { return max(a, max(b, c)); }
int max(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }

struct Msg {
  int lma, lmm, rma, rmm, a, b, ans;
  Msg() {}
  Msg(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
      : lma(a1), lmm(a2), rma(a3), rmm(a4), a(a5), b(a6), ans(a7) {}
} msgv[N << 2];

Msg operator*(const Msg &L, const Msg &R) {
  return Msg(
    max(L.lma, L.a + L.b + R.lmm, L.a - L.b + R.lma),
    max(L.lmm, R.lmm + L.b - L.a),
    max(R.rma, R.a + R.b + L.rmm, R.b - R.a + L.rma),
    max(R.rmm, L.rmm + R.a - R.b),
    L.a + max(R.a - L.b, 0),
    R.b + max(L.b - R.a, 0),
    max(L.ans, R.ans, L.rma + R.lmm, L.rmm + R.lma)
  );
}

inline Msg LP() { return Msg(1, 1, 1, 0, 0, 1, 1); }
inline Msg RP() { return Msg(1, 0, 1, 1, 1, 0, 1); }

char s[N];

void Build(int o, int l, int r) {
  if (l == r) {
    msgv[o] = s[l] == '(' ? LP() : RP();
  } else {
    int mid = (l + r) / 2;
    Build(o << 1, l, mid);
    Build(o << 1 | 1, mid + 1, r);
    msgv[o] = msgv[o << 1] * msgv[o << 1 | 1];
  }
}

void Modify(int o, int l, int r, int x) {
  if (r < x || l > x) return;
  if (l == r) {
    msgv[o] = s[l] == '(' ? LP() : RP();
  } else {
    int mid = (l + r) / 2;
    Modify(o << 1, l, mid, x);
    Modify(o << 1 | 1, mid + 1, r, x);
    msgv[o] = msgv[o << 1] * msgv[o << 1 | 1];
  }
}

int main() {
  int n = 2 * readInt() - 2, q = readInt();
  scanf("%s", s + 1);
  Build(1, 1, n);
  printf("%d\n", msgv[1].ans);
  while (q--) {
    int x = readInt(), y = readInt();
    std::swap(s[x], s[y]);
    Modify(1, 1, n, x);
    Modify(1, 1, n, y);
    printf("%d\n", msgv[1].ans);
  }
  return 0;
}