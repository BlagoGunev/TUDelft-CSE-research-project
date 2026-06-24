#include <bits/stdc++.h>

using namespace std;

int read() {

  int su = 0;

  scanf("%d", &su);

  return su;

}

int t, n;

char ch[105];

map<char, bool> mp;

int main() {

  cin >> t;

  while (t--) {

    mp.clear();

    cin >> n;

    bool f = 1;

    for (int i = 1; i <= n; i++) {

      cin >> ch[i];

      if (mp[ch[i]] == 1 && ch[i - 1] != ch[i]) {

        f = 0;

      }

      mp[ch[i]] = 1;

    }

    if (f) {

      puts("YES");

    } else {

      puts("NO");

    }

  }

  return 0;

}