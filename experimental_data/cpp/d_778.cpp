#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ld = long double;

constexpr int nax = 55;
constexpr int infty = 1000 * 1000 * 1000 + 5;
constexpr int mod = 1000 * 1000 * 1000 + 7;

int n, m;

char tab[2][nax][nax];

vector<pair<int, int>> ruchy;
void Obroc(int row, int col) {
  ruchy.emplace_back(row, col);
  assert(1 <= row and row < n);
  assert(1 <= col and col < m);
  if (tab[0][row][col] == 'L') {
    assert(tab[0][row][col] == 'L');
    assert(tab[0][row][col + 1] == 'R');
    assert(tab[0][row + 1][col] == 'L');
    assert(tab[0][row + 1][col + 1] == 'R');
    tab[0][row][col] = 'U';
    tab[0][row + 1][col] = 'D';
    tab[0][row][col + 1] = 'U';
    tab[0][row + 1][col + 1] = 'D';
  } else if (tab[0][row][col] == 'U') {
    assert(tab[0][row][col] == 'U');
    assert(tab[0][row + 1][col] == 'D');
    assert(tab[0][row][col + 1] == 'U');
    assert(tab[0][row + 1][col + 1] == 'D');
    tab[0][row][col] = 'L';
    tab[0][row][col + 1] = 'R';
    tab[0][row + 1][col] = 'L';
    tab[0][row + 1][col + 1] = 'R';
  } else {
    assert(false);
  }
}

void Podmien(int i, int j) {
  debug() << "Podmien(" << imie(i) << imie(j) << ")";
  assert(1 <= i and i < n);
  assert(1 <= j and j < m);
  assert(tab[0][i][j] == 'L' or tab[0][i][j] == 'U');
  if (tab[0][i][j] == 'U') {
    if (tab[0][i][j] != tab[0][i][j + 1]) {
      if (tab[0][i][j + 1] == 'D') {
        Podmien(i - 1, j + 1);
      }
      Podmien(i, j + 1);
    }
  } else if (tab[0][i][j] == 'L') {
    if (tab[0][i][j] != tab[0][i + 1][j]) {
      if (tab[0][i + 1][j] == 'R') {
        Podmien(i + 1, j - 1);
      }
      Podmien(i + 1, j);
    }
  }
  Obroc(i, j);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        scanf(" %c", &tab[i][j][k]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (tab[0][i][j] != tab[1][i][j]) {
        Podmien(i, j);
      }
      assert(tab[0][i][j] == tab[1][i][j]);
    }
  }
  printf("%d\n", (int) ruchy.size());
  assert((int) ruchy.size() <= 100 * 1000);
  for (const auto& it : ruchy) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}