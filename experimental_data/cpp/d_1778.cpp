//SHREE

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

 

using namespace std;

using namespace __gnu_pbds;



#define int long long

#define double long double

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define PI 3.141592653589793238462



const int M = 998244353;





#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;

#else

#define debug(x);

#endif



void _print(int t) {cerr << t;}

void _print(bool t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(double t) {cerr << t;}



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



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



/*---------------------------------------------------------------------------------------------------------------------------*/

int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b

int mminvprime(int a, int b) {return expo(a, b - 2, b);}

int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

/*--------------------------------------------------------------------------------------------------------------------------*/







void solve(){

    int n;

    cin >> n;

    string a1, b1;	

    cin >> a1 >> b1;

    int diff = 0;

    for(int i = 0; i < n; i++){

    	if(a1[i] != b1[i]){

    		diff++;

    	}

    }

    int a = 0, b = expo(2, n, M)-1;

    if(diff == 0){

    	cout << a << '\n';

    	return;

    }

    else if(diff == 1){

    	cout << b << '\n';

    	return;

    }

    for(int i = 2; i <= diff; i++){

    	int c = mod_sub(mod_mul(mod_div(n,n-(i-1),M),b,M) - mod_div(n, n-(i-1), M), mod_mul(a, mod_div(i-1, n-(i-1), M), M), M);

    	a = b;

    	b = c;

    }

    cout << b << '\n';

}



int32_t main() {

#ifndef ONLINE_JUDGE

    freopen("error.in", "w", stderr);

    auto start = std::chrono::high_resolution_clock::now();

#endif

    fastio();





    int t = 1;

    cin >> t;



    for(int i = 1; i <= t; i++){

        // cout << "Case #" << i << ": ";

        solve();

    }





#ifndef ONLINE_JUDGE

    auto stop = std::chrono::high_resolution_clock::now(); 

    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();

        std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;     

#endif

}