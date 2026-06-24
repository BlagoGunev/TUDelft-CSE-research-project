#include<bits/stdc++.h>



using namespace std;



#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define   int                      long long

typedef   double                   dd;

typedef   vector<int>              vi;

#define   endl              "\n"

#define   pb                push_back

#define   size(a)           (int)a.size()

#define   all(v)            v.begin(), v.end()

#define   rall(v)           v.rbegin(), v.rend()



// int ax[] = {0,  0, -1, 1};

// int ay[] = {1, -1,  0, 0};



const double eps = 1e-8;

const int N = 1e6 + 5, inf = 1e18;

int mod = 1e9 + 7, ii = 1;



void solve() {

   int n; string s, t; cin >> n >> s >> t;

   int ans = 0;

   int nn = n;

   int c1 = 0, c2 = 0;

   for (int i = 0; i < n; i++) {

      c1 += (s[i] == '1');

      c2 += (t[i] == '1');

   }

   if(c1 != c2) {

      cout << -1 << endl;

      return;

   }

   string ss;

   for (int i = 0; i < n; i++) {

      if(s[i] == t[i]) continue;

      ss += s[i];

   }

   s = ss;

   n = size(s);

   int mn1, mn2;

   c1 = c2 = mn1 = mn2 = 0;

   for (int i = 0; i < n; i++) {

      c1 += (s[i] == '0');

      c1 -= (s[i] == '1');

      mn1 = min(mn1, c1);

      mn2 = min(mn2, -c1);

      ans = max({ans, c1 - mn1, -c1 - mn2});

   }

   cout << ans << endl;

}



int32_t main() {

   IO;

   int TestCase = 1;

   // cin >> TestCase;

   while(TestCase--)

      solve();

   

   return 0;

}