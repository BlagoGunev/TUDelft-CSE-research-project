#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

void add_edge(int u, int v) {
  printf("%d %d\n", u + 1, v + 1);
  a[u]--;
  a[v]--;
}

void solve() {
  if (accumulate(a, a + N, 0ll) != 2 * N) {
    puts("No");
    return;
  }
  int twos = count(a, a + N, 2);
  if (twos == N) {
    puts("Yes");
    for (int i = 0; i < N; i++)
      add_edge(i, (i + 1) % N);
    return;
  }
  vector <int> leaves, other;
  for (int i = 0; i < N; i++)
    (a[i] == 1 ? leaves : other).push_back(i);
  auto get_leaves = [&](int node) {
    while (a[node]) {
      add_edge(node, leaves.back());
      leaves.pop_back();
    }
  };
  if (!twos) {
    puts("Yes");
    for (int i = 0; i < other.size(); i++)
      add_edge(other[i], other[(i + 1) % other.size()]);
    for (auto it : other)
      get_leaves(it);
    return;
  }
  vector <pii> sorted;
  for (int i = 0; i < N; i++)
    sorted.emplace_back(a[i], i);
  sort(sorted.begin(), sorted.end(), greater <pii> ());
  if (sorted[1].first < 3 || (other.size() % 2 && (other.size() == 3 || (sorted[0].first == 3 && (other.size() == 5 || other.size() == twos + 2))))) {
    puts("No");
    return;
  }
  vector <vector <int>> chain(2);
  for (int i = 0; i < N && sorted[i].first > 1; i++)
    chain[i % 2].push_back(sorted[i].second);
  puts("Yes");
  for (int i = 0; i < 2; i++)
    add_edge(sorted[0].second, sorted[1].second);
  bool need = other.size() % 2;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < chain[i].size(); j++) {
      if (!i && need && a[chain[i][j]] > 1) {
        add_edge(chain[i][j], chain[i].back());
        get_leaves(chain[i].back());
        chain[i].pop_back();
        need = false;
      }
      if (j < (int)chain[i].size() - 1)
        add_edge(chain[i][j], chain[i][j + 1]);
      get_leaves(chain[i][j]);
    }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}