#include <bits/stdc++.h>

using namespace std;



const int N = 1000 + 100;



struct gr {

  int c, p, id;

};



gr grs[N];

pair<int, int> tables[N];



int main()

{

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n;

  cin >> n;

  for (int i = 1; i <= n; ++i) {

    cin >> grs[i].c >> grs[i].p;

    grs[i].id = i;

  }

  int k;

  cin >> k;

  for (int i = 1; i <= k; ++i) {

    cin >> tables[i].first;

    tables[i].second = i;

  }

  

  sort(tables+1, tables+1 + k);

  sort(grs+1, grs+1 + n,

      [](gr g1, gr g2) -> bool { return g1.c < g2.c; });



  auto cmp_by_pr = 

    [](gr g1, gr g2) -> bool { return g1.p < g2.p; };

  priority_queue<gr, vector<gr>,

    decltype(cmp_by_pr) > q(cmp_by_pr);



  int tot = 0;

  vector<pair<int, int> > ans;

  for (int i = 1, rg = 1; i <= k; ++i) {

    while (rg <= n and grs[rg].c <= tables[i].first) {

      q.push(grs[rg]);

      ++rg;

    }

    if (!q.empty()) {

      gr g = q.top();

      q.pop();

      tot += g.p;

      ans.emplace_back(g.id, tables[i].second);

    }

  }

  

  cout << (int)ans.size() << ' ' << tot << '\n';

  for (auto it : ans) {

    cout << it.first << ' ' << it.second << '\n';

  }

}

// g++ -W -Wall -Wextra -pedantic -std=c++0x -o p main.cpp