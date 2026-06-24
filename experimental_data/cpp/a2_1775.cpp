#include<bits/stdc++.h>

 using namespace std;

using ll = long long int ; // 

#define hi cout << "test\n" ;

const int mod = 998244353  ;

#define files freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout),freopen("error.txt","w",stderr) 

#define FastIO ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

#ifndef ONLINE_JUDGE

#define dbg(x) cerr << #x <<" = "; _print(x); cerr << endl;

#else

#define dbg(x)

#endif

ll expo(ll a, ll b, ll mod) {ll ans = 1; while (b > 0) {if (b & 1)ans = (ans * a) % mod; a = (a * a) % mod; b = b >> 1;} return ans;}

ll gcd(ll a, ll b) { return((b == 0) ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

void _print(auto t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//----------------------------------------------------------------------------------------------------------------------------------

void solve(){

   string s ; 

   cin >> s ; 

   int n = s.size() ; 

   int bb = -1 ; 

   int aa = -1 ;

   int as = 0 , bs=0  ; 

   for ( int i =0 ; i < n ;i++ ){

     if ( s[i] == 'a' ) aa = i  ,as++; 

     else bb = i ,bs++; 

   }       

   if ( aa == -1 or bb == -1   ) {

      cout << s[0] << " " ;

      for ( int i = 1 ; i < s.size() - 1 ; i++) 

       cout << s[i]  ;

      cout << " "; 

      cout << s[1] ; 

      return ; 

   }

   if ( s[0] == 'a' and s[ n - 1 ] == 'a' ) {

     int i = 0 ; 

      while ( s[i] == 'a' ) {

       cout << s[i] ; 

       i++  ;

      }

      cout << " "; 

      while ( s[i] == 'b' ) {

         cout << s[i]  ; 

         i++ ; 

      }

      cout <<  " " ;

      while ( i < n ) {

         cout << s[i] ; 

         i++ ; 

      }

      return ; 

   }

   if ( s[0] == 'a' and s[n-1] =='b' ) {

     cout << s[0]   ; 

      if ( as  ==  1 ) {

         cout <<" " ; 

         for ( int i = 1 ; i < n - 1 ; i++ ) 

          cout << s[i] ; 

         cout << " " << s[n-1]  ; 

         return ; 

      }

      if ( s[1] == 'a' ) {

         cout << " " << s[1] << " "; 

         for ( int i = 2 ; i < n ;i ++) cout << s[i] ; 

          return ;

      }

        cout << " " ; 

        int i = 1; 

        while ( s[i] == 'b' and i < n - 1 ) 

          cout <<s[i++] ; 

        cout << " " ; 

        while ( i < n ) 

          cout << s[i++] ; 



      return ; 

   }

   

   if ( s[0] == 'b' and s[n-1] == 'b' ) {

     int i = 0 ; 

     while ( s[i] == 'b' ) 

      cout << s[i++]  ; 

      cout <<" " << s[i] << " "  ; 

      i++ ; 

      while ( i  < n ) 

        cout << s[i++] ; 

   }

   if ( s[0] == 'b' and s[n-1] == 'a' ) {

      if ( as == 1 ) {

         cout << s[0] << " " ; 

         for ( int i = 1 ; i < n - 1; i++ ) 

          cout <<s[i] ; 

          cout << " " << s[n-1] ; 

          return ;

      }

    int i = 0 ; 

     while ( s[i] == 'b' ) 

      cout << s[i++] ; 

      cout <<" " ; 

      cout << s[i] << " "; 

      i++ ; 

      while ( i < n ) 

        cout << s[i++] ; 



   }





}//--------- -----------------------------------------------------------------------------------------------------------------

int32_t main(){

 #ifndef ONLINE_JUDGE

    files;

  #endif 

     FastIO ;

 int test = 1;

   cin>>test; 

    while(test--){

 //cout << " test case " <<++i<<endl;

     solve(); 

     if(test>0)

       cout << endl; 

}

 

 }