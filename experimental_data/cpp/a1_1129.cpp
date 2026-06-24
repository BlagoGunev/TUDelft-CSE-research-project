#include <bits/stdc++.h>
#include <chrono>



using namespace std;

using ll = long long;

#define db(x) cerr << #x << " == " << (x) << endl;
//#define db(x)

const int INF = numeric_limits<int>::max() / 3;
const int MAXN = 5123;
int ni[MAXN];
int ci[MAXN];
int n, m;

int D(int a, int b) {
  return (b - a + n) % n;
}

int main() {
   ios::sync_with_stdio(false);

   cin >> n >> m;
   fill(ci, ci + n, INF);
   for (int i = 0; i < m; i++) {
     int a, b;
     cin >> a >> b;
     a--; b--;
     ni[a]++;
     ci[a] = min(ci[a], D(a, b));
   }

   for (int j = 0; j < n; j++) {
     int ans = 0;
     for (int i = 0; i < n; i++) {
       if (not ni[i]) continue;
       int tij = D(j, i) + (ni[i] - 1) * n + ci[i];
       ans = max(ans, tij);
     }
     cout << ans << ' ';
   }
   cout << endl;
}