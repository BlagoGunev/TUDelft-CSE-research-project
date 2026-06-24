#include <bits/stdc++.h>

using namespace std;

int main (int argc, const char *argv[]) {
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  bool flag = true;
  set<pair<char, char>> se;
  se.insert({'4', '6'});
  se.insert({'5', '9'});
  se.insert({'7', '7'});
  se.insert({'0', '8'});
  se.insert({'3', '3'});
  for (int i = 0; i < (int)s.size(); i ++) {
    char c1 = s[i], c2 = t[i];
    if (c1 > c2) swap(c1, c2);
    if (!se.count({c1, c2})) {
      flag = false;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}