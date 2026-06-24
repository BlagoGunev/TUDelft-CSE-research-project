#include <bits/stdc++.h>

using namespace std;

const int lenmax = 2e5+5;

char s[lenmax];
int n, t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> (s + 1);
    n = strlen(s + 1);
    
    
    for (int i = 1; i <= n; i++) s[i] -= '0';
    
    int bestPos = -1;
    int bestCifra = -1;
    int bestMask = 0;
    int mask = 0;
    for (int i = 1; i <= n; i++) {
      for (int c = 0; c < s[i]; c++) {
        if (i == 1 && c == 0) continue;
        mask ^= (1<<c);
        int spots_left = n - i;
        if (spots_left >= __builtin_popcount(mask)) {
          bestPos = i;
          bestCifra = c;
          bestMask = mask;
        }
        mask ^= (1<<c);
      }
      mask ^= (1<<s[i]);
    }
    
    if (bestPos == -1) {
      for (int i = 1; i <= n - 2; i++) cout << 9;
      cout << '\n';
      continue;
    }
    
    int should_match = __builtin_popcount(bestMask);
    s[bestPos] = bestCifra;
    for (int i = bestPos + 1; i <= n - should_match; i++) {
      s[i] = 9;
    }
    for (int i = n - should_match + 1; i <= n; i++) {
      for (int c = 9; c >= 0; --c) {
        if (bestMask & (1<<c)) {
          s[i] = c;
          bestMask ^= 1<<c;
          break;
        }
      }
    }
    
    for (int i = 1; i <= n; i++) { s[i] += '0'; }
    cout << (s + 1) << '\n';
  }
  
  return 0;
}