// NOTE : LCM*GCD == A*B _______ LCM = (A*B)/GCD(A,B) _______ LCM = (A/GCD(A,B))*B

// (X-Y) MOD M ------> (X%M - Y%M + 2*M)%M

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

template <typename T>

using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define AliveTube ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define endl "\n"

#define MX -1

#define MN INT_MAX

#define ll long long

// #define int long long

#define ull unsigned long long

#define all(x) x.begin(), x.end()

#define allr(x) x.rbegin(), x.rend()

#define posmod(v, m) ((v) % (m) + (m)) % m // To take positive mod

const long double PI = 3.14159265358979323846;

const int N = 1001;

const int MOD = 1000000007;

const long double EPS = 0.000001;

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1}; // left , right , up , down , downright , downleft , upright , upleft

int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};



ll pre[1002][1002] = {0};



void solve (){

   int n , q ; cin >> n >> q;

   memset(pre , 0 , sizeof pre);

   for (int i = 0; i < n; i++)

   {

      ll h , w ;cin >> h >> w;

      pre[h][w]+=h*w;

   }

   for (size_t i = 1; i < 1002; i++)

   {

      for (int j = 1; j < 1002; j++)

      {

         pre[i][j] += pre[i-1][j];

         pre[i][j] += pre[i][j-1];

         pre[i][j] -= pre[i-1][j-1];

      }

   }

   while (q--){

      ll h1,w1,h2,w2;cin >> h1 >> w1 >> h2 >> w2 ;

      ll ans = pre[h1][w1] - pre[h2-1][w1] - pre[h1][w2-1] + pre[h2-1][w2-1];

      cout << ans << endl ;

  }

}

signed main(){

   AliveTube

   // freopen("input.txt", "r", stdin);

   // freopen("output.txt", "w", stdout);

   int phantasmagorical = 1;

   cin >> phantasmagorical ;

   while (phantasmagorical--){

      solve();

   }

}