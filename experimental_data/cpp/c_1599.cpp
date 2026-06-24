#include<bits/stdc++.h>



using namespace std;



// #include <ext/pb_ds/assoc_container.hpp>

// #include<ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// using namespace __gnu_cxx;

// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define   int                      long long

typedef   double                   dd;

typedef   vector<int>              vi;

typedef   vector<char>             vc;

typedef   set<int>                 si;

typedef   map<int,int>             mp;

typedef   pair<int,int>            pr;

typedef   tuple<int,int, int>      tp;

typedef   vector<vector<int>>      vvi;

typedef   vector<pair<int,int>>    vpr;

#define   intmax            INT_MAX

#define   lintmax           LLONG_MAX

#define   endl              "\n"

#define   pb                push_back

#define   F                 first

#define   S                 second

#define   pi                acos(-1.0)

#define   size(a)           (int)a.size()

#define   all(v)            v.begin(), v.end()

#define   rall(v)           v.rbegin(), v.rend()

#define   bp(x)             __builtin_popcountll(x)



#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n';}

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>

void err(istream_iterator<string> it, T a, Args... args) {

   cerr << *it << "= " << a << " ! ";

   err(++it, args...);

}



//int ax[] = {0,  0, -1, 1, -1,  1, -1, 1};

//int ay[] = {1, -1,  0, 0, -1, -1,  1, 1};



const double eps = 1e-5;

const int N = 1e6 + 5;



int ii = 1;



void solve() {

   int n; cin >> n;

   dd p; cin >> p;

   dd ze = 0.000;

   if(p-eps <= eps) {

      cout << 0 << endl;

      return;

   } 

   if(1.00000 - p <= eps) {

      cout << n-1 << endl;

      return;

   }





   for (int i = 1; i < n-1; i++) {

      dd p1 = (dd)(n - i);

      dd i1 = ((dd)i)*1.00;

      

      dd c3 = 0.00;

      if(i >= 3) {

         c3 = (i1*(i1-1.0000)*(i1-2.0000))/6.0000 * (1.0000);

      }

      dd c2 = 0.0000;

      if(i >= 2) {

         c2 = (i1*(i1-1.00))/2.0000 * (p1);

      }

      dd c1 = (i1) * (p1*(p1-1.00))/2.000;

      dd c0 = (1.000) * (p1*(p1-1.00)*(p1-2.00)/6.00);



      dd p2 = ((c2+c3) + c1*0.5000) / (c0 + c1 + c2 + c3);



      if(p2 - p >= eps) {

         cout << i << endl;

         return;

      } 



   }





}



int32_t main() {

   IO;

   int TestCase = 1; 



   // #ifndef ONLINE_JUDGE

   // freopen("D:\\Atom\\sublime text 3\\input.in", "r", stdin);

   // freopen("D:\\Atom\\sublime text 3\\output.out", "w", stdout);

   // #endif



   // cin >> TestCase;

   // scanf("%d", &TestCase);

   while(TestCase--)

      solve();



   //cerr << endl << "time : "<< (float)clock()/CLOCKS_PER_SEC << " s" << endl;



   return 0;

}







 

/**

   stuff you should look for

   * obvious case

   * check MIN/MAX value

   * int overflow, array bounds

   * special cases (n=1?)

   * do smth instead of nothing and stay organized

   * WRITE STUFF DOWN

   * DON'T GET STUCK ON ONE APPROACH

*/