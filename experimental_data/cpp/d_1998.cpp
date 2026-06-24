#include <iostream>
#include <vector>

int main() {
  int tc;
  std::cin >> tc;
  while (tc--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--, v--;
      g[v].push_back(u);
    }

    std::vector<int> f(n);
    f[0] = 0;
    for (int i = 1; i < n; i++) {
      f[i] = f[i-1]+1;
      for (int j : g[i])
        f[i] = std::min(f[i], f[j]+1);
    }

    std::vector<int> p(n+1, 0);
    for (int i = 0; i < n; i++) {
      for (int j : g[i]) {
        int k = i - f[j] - 1;
        if (j+1 < k) {
          p[j+1]++;
          p[k]--;
        }
      }
    }

    int s = 0;
    for (int i = 0; i < n-1; i++) {
      s += p[i];
      std::cout << (s > 0 ? 0 : 1);
    }
    std::cout << '\n';
  }
}