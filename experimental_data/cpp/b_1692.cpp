#include <bits/stdc++.h> 



 #define ll long long 

 #define ull unsigned long long

 #define ld long double

 #define oo 2000000000

 #define pi  3.14159265359

 #define mod 1000000007

 #define odd(a)  a&1

 #define even(a)  !(a&1)

 #define fixed(n) fixed << setprecision(n)

 #define Num_of_Digits(n) ((int)log10(n) + 1)

 #define power_of_2(x) (x && (!(x&(x-1))))

 #define isPerfectSquare(n) (sqrt(n) == (int)sqrt(n))

 #define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))

 #define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << nl ;



 #define all(a) a.begin(), a.end()

 #define rall(a) a.rbegin(), a.rend()

 #define mx(a) *max_element(all(a))

 #define mn(a) *min_element(all(a))

 #define v_sort(x) sort(all(x),less<>())

 #define v_gsort(x) sort(all(x),greater<>())

 #define v_find(x,num) *find(all(x),num)

 

 #define sz(x) int(x.size())

 #define nl "\n"

 #define r_v_n return void(cout<<"NO");

 #define r_v_y return void(cout<<"YES");

 #define bool(n) cout<<(n?"YES":"NO");

 #define FI first

 #define SE second

 #define MP make_pair

 #define pb push_back

 #define pf push_front

 #define rev(a) reverse(all(a));



 #define cin_v(a) for ( auto & i : a) cin >>i;

 #define cin_pair(a) for ( auto & i : a) cin>> i.FI >>i.SE;

 #define cout_v(a)  for ( auto & i : a) cout << i <<" ";

 #define cout_pair(a)  for ( auto & i : a) cout << i.FI <<" "<<i.SE<<nl;



 #define upper(s) transform(all(s), s.begin(), ::toupper);

 #define lower(s) transform(all(s), s.begin(), ::tolower);

 #define to_decimal(bin) stoll(bin, nullptr, 2)





ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}

ll factorial(ll n) { return (n == 0?1:n * factorial(n - 1)); } 

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

double n_q(int x1,int y1,int x2,int y2){return sqrt(  pow((x1-x2),2) + pow ((y1-y2)  ,2) )/2;}

bool is_tri(int a,int b, int c){ return (((a+b>c) && (a+c>b) && (b+c>a)  && (a && b && c))?true:false   ) ;}

bool vowel(char c){return (c=='a' || c=='o' || c=='u' || c=='i' ||c=='e')|| (c=='A' || c=='O' || c=='U' || c=='I' ||c=='E');}

 

 

 using namespace std;



  void menna_allah(){

 ios_base ::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);



  #ifndef ONLINE_JUDGE

  freopen("input.txt","r", stdin), freopen ("output.txt", "w", stdout);

  #endif



}

 void kick(){

 ios_base ::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);



  freopen("input.txt", "r", stdin);

  freopen ("output.txt", "w", stdout);

}







  void solve(){

ll n; cin >>n;



set<int> s;

for ( int i=0;i<n;i++){

  int x;

  cin >>x;

  s.insert(x);

}

cout<<(even(n-sz(s))?sz(s):sz(s)-1);



  }

   



int main()

{

   menna_allah();

 // kick();

int t=1;

          cin>>t;





while(t--){



 solve();

 cout<<nl;

 //Time;

}

    return 0;

}