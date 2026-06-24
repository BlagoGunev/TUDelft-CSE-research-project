#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
#define SPEEDUP ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr)
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
// #define for(a, b, s) for(size_t i = (a); i < (b); i = i + s)
#define in_file(f_in) ifstream (f_in); (f_in).open("input.txt");
#define out_file(f_out) ofstream (f_out); (f_out).open("output.txt");
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
///////////////////////////////////////////////////////////////////////////////////

int main() {
 SPEEDUP;

 int n;
 cin >> n;
 map<int, int> m;

 int var;
 for (int i = 0; i < n; ++i) {
  cin >> var;
  ++m[var];
 }

 int ans = 0;
 map<int, int> res;


 if (m.size() == 1) {
  m[(*(m.begin())).first + 1] = 0;
  m[(*(m.begin())).first - 1] = 0;

  cout << n << "\n";
  for (auto v : m) {
   for (int d = 0; d < v.second; ++d) {
    cout << v.first << " ";
   }
  }
  cout << "\n";

  return 0;

 }

 int q = (*m.begin()).second;
 int p = (*(--m.end())).second;
 int k = (*(++m.begin())).second;

 if (m.size() == 2) {
  if ((*m.begin()).first + 1 == (*(--m.end())).first) {
   cout << n << "\n";
  for (auto v : m) {
   for (int d = 0; d < v.second; ++d) {
    cout << v.first << " ";
   }
  }
  cout << "\n";

  return 0;
  } else {
   m[(*m.begin()).first + 1] = 0;
  }
 }


 q = (*m.begin()).second;
 p = (*(--m.end())).second;
 k = (*(++m.begin())).second;


 if (q >= p) {
  ans += (q - p);
  res[(*m.begin()).first] = q - p;
  m[(*m.begin()).first] = p;
  q = p;
 } else {
  ans += (p - q);
  res[(*(--m.end())).first] = p - q;
  m[(*(--m.end())).first] = p;
  p = q;
 }

 if (k <= 2*p) {
  res[(*(++m.begin())).first] = k + 2 * p;
  ans += k;
 }
 else {
  res[(*(--m.end())).first] += (p + (k / 2));
  res[(*m.begin()).first] += (p + (k / 2));
  ans += 2 * p;
  res[(*(++m.begin())).first] += (k % 2);
  ans += k % 2;
 }

 cout << ans << "\n";
 for (auto v : res) {
  for (int d = 0; d < v.second; ++d) {
   cout << v.first << " ";
  }
 }
 cout << "\n";

 return 0;
}