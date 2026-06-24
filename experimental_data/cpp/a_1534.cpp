#include <bits/stdc++.h>



void RunCase() {

  int n, m;

  std::cin >> n >> m;

  std::vector<std::string> g(n);

  for (int i = 0; i < n; i++) {

    std::cin >> g[i];

  }

  std::string t1, t2;

  for (int i = 0; i < m; i++) {

    if (i % 2 == 0) {

      t1.push_back('R');

      t2.push_back('W');

    } else {

      t1.push_back('W');

      t2.push_back('R');

    }

  }

  std::vector<std::string> g1(n), g2(n);

  for (int i = 0; i < n; i++) {

    if (i % 2 == 0) {

      g1[i] = t1;

      g2[i] = t2;

    } else {

      g1[i] = t2;

      g2[i] = t1;

    }

  }

  bool ok1 = true, ok2 = true;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {

      if (g[i][j] != '.' && g[i][j] != g1[i][j]) {

        ok1 = false;

      }

      if (g[i][j] != '.' && g[i][j] != g2[i][j]) {

        ok2 = false;

      }

    }

  }

  if (ok1) {

    std::cout << "YES\n";

    for (int i = 0; i < n; i++) {

      std::cout << g1[i] << '\n';

    }

  } else if (ok2) {

    std::cout << "YES\n";

    for (int i = 0; i < n; i++) {

      std::cout << g2[i] << '\n';

    }

  } else {

    std::cout << "NO\n";

  }

}



int main() {

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  int t;

  std::cin >> t;

  while (t--) {

    RunCase();

  }

  return 0;

}