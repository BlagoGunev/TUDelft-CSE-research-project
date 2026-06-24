#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))

#define ff(i, a, b) for (int i = a; i <= b; i++)

#define fd(i, a, b) for (int i = a; i >= b; i--)

#define fe(i, a, b) for (int i = a; i < b; i++)

#define ii pair <int, int>

#define fi first

#define se second

#define sz(a) a.size()

#define RESET(a, b) memset((a), (b), sizeof (a))

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

const int INF = 1e9 + 7;

const int maxN = 2e5 + 9;

const int base = 1e9 + 7;



int r, g;

int f[maxN];



void enter()

{

   cin >> r >> g;

   swap(r, g);

}



void process()

{

   int N = (int) ((sqrt(1 + 8 * (r + g)) - 1) / 2);

   int M = N * (N + 1) / 2;

   f[0] = 1;

   ff(i, 1, N) fd(j, r, i) {

      f[j] = (f[j] + f[j - i]) % base;

   }



   int ans = 0;

   ff(i, max(0, M - g), r) ans = (ans + f[i]) % base;

   cout << ans;

}



int main()

{

   ios_base::sync_with_stdio(false); cin.tie(NULL);

   //freopen("487D.inp", "r", stdin);

   //freopen("template.out", "w", stdout);



   enter();

   process();



   return 0;

}