#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using db = double;

using pin = pair<int, int>;

using pil = pair<int, ll>;



int main() {

  cin.tie(0), cout.tie(0) -> ios::sync_with_stdio(false);

  

  int T;

  cin >> T;

  for (; T--; ) {

    string a, b;

    cin >> a >> b;

    vector <int> cnt(26, 0);

    cnt[a[0] - 'a']++, cnt[a[1] - 'a']++;

    cnt[b[0] - 'a']++, cnt[b[1] - 'a']++;

    int ans = 0;

    for (int i = 0; i < 26; i++) {

      if (cnt[i] != 0) ++ans;

    }

    --ans;

    cout << ans << "\n";

  }

  return 0;

}