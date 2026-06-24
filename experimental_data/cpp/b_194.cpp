#include <iostream>

using namespace std;

int64_t gcd(int64_t a, int64_t b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    int64_t x;
    cin >> x;
    cout << x * 4 / gcd(x + 1, 4) + 1 << '\n';
  }
}