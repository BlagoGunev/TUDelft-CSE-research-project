#include <bits/stdc++.h>
using namespace std;

int64_t C2(int n) {
  return 1LL * n * (n-1) / 2;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), f(n);
  for (int& x: a) cin >> x, x--;
  int last = 0;

  const int B = 500;
  const int M = (n+B-1)/B;
  vector<vector<int64_t>> block_ans(M, vector<int64_t>(M)), updateL(M+1, vector<int64_t>(M+1)), updateR(M, vector<int64_t>(M));
  vector<vector<int>> pref_freq(M+1, vector<int>(n));
  for (int block = 0; block < M; block++) {
    pref_freq[block+1] = pref_freq[block];
    for (int i = block * B; i < n && i < (block+1) * B; i++) {
      pref_freq[block+1][a[i]]++;
    }
    int64_t cur = 0;
    for (int i = block * B; i < n; i++) {
      if (i%B == 0) block_ans[block][i/B] = cur;
      cur += f[a[i]]++;
    }
    for (int i = block * B; i < n; i++) f[a[i]] = 0;
  }

  auto get_block_ans = [&] (int l, int r) {
    int64_t ans = block_ans[l][r];
    for (int z = l; z <= r; z++) ans += updateL[l][z] + updateR[r][z];
    return ans;
  };

  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      p = (p+last) % n;
      x = (x+last) % n;
      if (a[p] == x) continue;
      for (int block = p/B+1; block <= M; block++) {
        pref_freq[block][a[p]]--;
        pref_freq[block][x]++;
      }
      for (int l = 0; l <= p/B; l++) updateL[l][p/B+1] += pref_freq[l][a[p]] - pref_freq[l][x] - 1;
      for (int r = p/B+1; r < M; r++) updateR[r][p/B] += pref_freq[r][x] - pref_freq[r][a[p]];
      a[p] = x;
    }
    else if (type == 2) {
      int l, r;
      cin >> l >> r;
      l = (l+last) % n;
      r = (r+last) % n;
      if (l > r) swap(l, r);
      int64_t ans = 0;
      if (l/B == r/B) {
        for (int i = l; i <= r; i++) ans += f[a[i]]++;
        for (int i = l; i <= r; i++) f[a[i]] = 0;
      }
      else {
        ans = get_block_ans(l/B+1, r/B);
        for (int i = l; i < (l/B+1)*B; i++) ans += pref_freq[r/B][a[i]] - pref_freq[l/B+1][a[i]] + f[a[i]]++;
        for (int i = r; i >= (r/B)*B; i--) ans += pref_freq[r/B][a[i]] - pref_freq[l/B+1][a[i]] + f[a[i]]++;
        for (int i = l; i < (l/B+1)*B; i++) f[a[i]] = 0;
        for (int i = r; i >= (r/B)*B; i--) f[a[i]] = 0;
      }
      ans = C2(r-l+1) - ans;
      cout << ans << '\n';
      last = ans % n;
    }
  }
}