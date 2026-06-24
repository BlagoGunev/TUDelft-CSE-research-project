#include<bits/stdc++.h>

using namespace std;

 

 

//************************************************DEFiNED FUNCTION//*********************************************

 

 

   #define int long long

   #define MOD1   1000000007

   #define MOD   998244353 

   #define pb   push_back

   #define desc greater<int>

   #define pii pair<int,int>

   #define F first

   #define S second

   #define sz(x) ((int)(x).size())

   #define ina(a,n) for(int i = 0 ; i < n ; i ++){ cin >> a[i];}

   #define inv(a,n) for(int i = 0 ; i < n ; i ++){ int x; cin>>x; a.pb(x);}

   #define ins(a,n) for(int i = 0 ; i < n ; i ++){ int x; cin>>x; a.insert(x);}

   #define pb push_back

   #define len(x) x.length()

   #define all(v) v.begin(), v.end()

   #define fl(i, a, b) for(int i = a; i < b; i++)

   #define rfl(i, a, b) for(int i = a; i > b; i--)

   #define vll vector<int> 

   #define PIE 3.141592653589793238462

   #define set_bits __builtin_popcountll

   #define ppb pop_back

   #define lld long double 

   #define string_to_int stoull(s, 0, 2)

   #define rvsort(a) sort(all(a),greater<int>())

   #define ms(arr, v) memset(arr, v, sizeof(arr))

   #define el '\n' 

   #define mine min_element

   #define maxe max_element

   #define ub upper_bound

   #define lb lower_bound

   #define bs binary_search

   #define ull unsigned long long

   #define no cout<<'N'<<'O'<<el

   #define yes cout<<'Y'<<'E'<<'S'<<el

   #define nxp(s) next_permutation(all(s))

   #define sum(v)  accumulate(all(v),0LL)

 

 

 

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++DEBUGGING++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 

template<class T> void Ka(T a) {cout<<a<<el;}

template<class T> void Kau(T a) {cout<<a<<' ';}

template<class T1, class T2> void Ka(T1 a, T2 b) {cout<<a<<' '<<b<<el;}

template<class T1, class T2, class T3> void Ka(T1 a, T2 b, T3 c) {cout<<a<<' '<<b<<' '<<c<<el;}

template<class T1, class T2, class T3, class T4> void Ka(T1 a, T2 b, T3 c, T4 d) {cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<el;}

template<class T> void Kau(T a[], int n) {int i; fl(i,0,n) cout<<a[i]<<' '; cout<<el;}

template<class T> void Ka(vector<T> v) {for(auto x:v) cout<<x<<' '; cout<<el;}

template<class T> void Ka(list<T> l) {for(auto x:l) cout<<x<<' '; cout<<el;}

template<class T> void Ka(set<T> s) {for(auto x:s) cout<<x<<' '; cout<<el;}

template<class T> void Ka(multiset<T> s) {for(auto x:s) cout<<x<<' '; cout<<el;}

template<class T> void Ka(unordered_set<T> s) {for(auto x:s) cout<<x<<' '; cout<<el;}

template<class T1, class T2> void Ka(map<T1,T2> m) {for(auto x:m) cout<<x.F<<'-'<<'>'<<x.S<<el; cout<<el;}

template<class T1, class T2> void Ka(unordered_map<T1,T2> m) {for(auto x:m) cout<<x.F<<'-'<<'>'<<x.S<<el; cout<<el;}

template<class T1, class T2> void Ka(map<T1,vector<T2>> m) {for(auto x:m) {cout<<x.F<<'-'<<'>';Ka(x.S);} cout<<el;}

template<class T1, class T2> void Ka(unordered_map<T1,vector<T2>> m) {for(auto x:m) {cout<<x.F<<'-'<<'>';Ka(x.S);} cout<<el;}

 

/*+++++++++++++++++++++++++++++++++++++++++++++++FUNCTIONS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



//Check

bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0  ||n%(i+2)==0)return false;return true;}

bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}

bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}

 

/*+++++++++++++++++++++++++++  FUNCTION +++++++++++++++++++++++++++++++++++++++++++++++*/

 

int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 

int lcm(int a, int b){return (a/gcd(a,b)*b);}

int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];}

int mminvprime(int a, int b) {return expo(a, b - 2, b);}

int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} 

 int power(int a, int b);





//++++++++++++++++++++++++++++++++++++++Sorting+++++++++++++++++++++++++++++++++++++++++++++++++++

bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}





void Ka_(){

//test case analyse kro and then start kro solve krna...khud se ustadi nhiiiiii

 int n, u, v;

            cin >> n >> u >> v;

            int counter = 0;

            set<int> s1;

            int prev = 0;

            for(int i = 0; i < n; i++){

                  int a;

                  cin >> a;

                  if(i >= 1 && abs(prev - a) >= 2){

                        counter = 1;

                  }

                  prev = a;

                  s1.insert(a);

            }

            if(sz(s1) == 1){

                  cout << min(v + v, u + v) << el;

            }else if(counter == 1){

                  cout << 0 << el;

            }else{

                  cout << min(u, v) << el;

            }

}



signed main(){

 

              ios_base::sync_with_stdio(false);

              cin.tie(NULL);

              int t;

              cin>>t;

              fl(i,0,t){

            //cout<<'C'<<'a'<<'s'<<'e'<<' '<<'#'<<i+1<<' ';

 Ka_();

              }

return 0;

}

int power(int a, int b){if(b==0){ return 1;}if(b%2==0){int t = power(a, b/2);return t*t;}else{int t = power(a, (b-1)/2);

t = t*t;return a*t;}}

// //Prime Factorisation

// int prime_factor[100000];

// vector<pair<int, int> > prime_factors[100000];

// void GeneratePrimeFactors(int N)

// {

//     for(int i = 2; i < N; i++) {

//         if(prime_factor[i] != 0)  continue;

//         prime_factor[i] = i;

//         for(int j = 2*i; j < N; j += i) {

//           prime_factor[j] = i;

//         }

//     }

//     for(int i = 2; i < N; i++) {

//         int x = i;

//         map<int, int> M;

//         while(x != 1) {

//           M[prime_factor[x]]++;

//           x /= prime_factor[x];

//         }

//         for(auto v : M) {

//           prime_factors[i].push_back(v);

//         }

//     }

// }

// bool prime[10000007];

// vector<int> ans;

// void Seive(int N)

// {

//     memset(prime,true,sizeof(prime));

//     for(int i=2;i<=N;i++)

//     {

//         if(prime[i])

//         {

//             ans.pb(i);

//             for(int j=2*i;j<=N;j+=i)

//             {

//                 prime[j]=false;

//             }

//         }

//     }

// }