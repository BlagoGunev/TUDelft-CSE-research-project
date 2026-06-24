#include <bits/stdc++.h>



using namespace std;



const int N = 300010;



struct node {

  int cnt[N], sum[N], go[N][26], f[N], tot;

} nd;

vector <node> vec;

char foo[N];



void add(char s[], int ad, node & v) {

  int p = 0;

  auto & tot = v.tot;

  auto & go = v.go;

  for (int i = 0; s[i]; i ++) {

    int c = s[i] - 'a';

    if (! go[p][c]) {

      go[p][c] = ++ tot;

    }

    p = go[p][c];

  }

  v.cnt[p] += ad;

}



void bfs(node & v) {

  auto & go = v.go;

  auto & sum = v.sum;

  auto & cnt = v.cnt;

  auto & f = v.f;

  queue <int> q;

  q.push(0);

  while (q.size()) {

    int x = q.front(), c = 0;

    sum[x] = sum[f[x]] + cnt[x];

    q.pop();

    for (auto y : go[x]) {

      if (y) {

        q.push(y);

        int k = f[x];

        while (k && ! go[k][c]) k = f[k];

        if (x && go[k][c]) k = go[k][c];

        f[y] = k;

      }

      c ++;

    }

  }

}



int main() {

  int m, flag = 1;

  scanf("%d", &m);

  while (m --) {

    int t;

    scanf("%d %s", &t, foo);

    if (t == 1 || t == 2) {

      flag = 0;

      if (vec.empty() || vec.back().tot > N / 21) {

        if (vec.size()) bfs(vec.back());

        vec.push_back(nd);

      }

      add(foo, 3 - 2 * t, vec.back());

    }

    if (t == 3) {

      if (! flag ++) bfs(vec.back());

      long long ans = 0;

      for (auto & v : vec) {

        auto & go = v.go;

        auto & f = v.f;

        auto & sum = v.sum;

        for (int i = 0, k = 0; foo[i]; i ++) {

          int c = foo[i] - 'a';

          while (k && ! go[k][c]) k = f[k];

          if (go[k][c]) k = go[k][c];

          ans += sum[k];

        }

      }

      printf("%lld\n", ans);

      fflush(stdout);

    }

  }

  return 0;

}