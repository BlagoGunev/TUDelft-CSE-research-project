#include<bits/stdc++.h>

using namespace std;



#define ll long long 

#define umap unordered_map

#define py cout<<"YES\n"

#define pn cout<<"NO\n"

#define nline "\n"

#define pb push_back

#define ff first

#define ss second

#define sz(x)             (int)((x).size())

#define mp make_pair

#define rep(i,a,b)        for(int i=a;i<b;i++)

#define all(x)            (x).begin(), (x).end()

#define ppb pop_back

typedef vector<long long int > vl;

#define MOD 1000000007 //prime 

#define LIMIT 1000000



const int MOD1 = 998244353;



ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll mod(ll a, ll m) {return ((a % m + m) % m);}

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



// ========================================MATH UTIL BEGINS==============================================

//==================================== compute higher powers with mod ===================================

ll power(ll x, ll y, ll p =  MOD)

{

    unsigned long long res = 1;



    x = x % p;

    while (y > 0)

    {



        if (y & 1)

            res = (res * x) % p;



        y = y >> 1;

        x = (x * x) % p;

    }

    return res;

}



// =============================================================================================================



ll modInverse(ll n, ll p=MOD)       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]

{

    return power(n, p - 2, p);

}

// can also derive this using extended euclidean... however this has a much simpler code....



ll fac(ll x){

  if(x<=1)  return 1;

  return (x*fac(x-1))%MOD;



}

// =========================================Used to calculate nCr of higher values ===================================

ll nCr(ll n, ll r, ll p=MOD)     // faster calculation.. 

{

    if (n < r)

        return 0;



    if (r == 0)

        return 1;

        

    vector<ll> fac(n+1,0);

    fac[0] = 1;

    for (ll i = 1; i <= n; i++)

        fac[i] = (fac[i - 1] * i) % p;



    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;

}



// ================================== check prime ======================================================== //



bool isPrime(int n)

{

    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {

        if (n % i == 0) return false;

    }

    return true;

}



// ============================= solution for quadratic equation =================================== //



double solveQuadratic(double a, double b, double c) {

    double discriminant = b * b - 4 * a * c;

    double sqrtDiscriminant = sqrt(discriminant);

    double x1 = (-b + sqrtDiscriminant) / (2 * a);

    return x1;

}



// ==================================== MATH UTIL ENDS=======================================================//



void solve(){

	string s = "codeforces";

	vector<ll>cnt(10,1);



	ll k;

	cin>>k;



	ll val = 1,ptr = 0;



	while(val<k){

		val/=cnt[ptr];

		cnt[ptr]++;

		val*=cnt[ptr];



		ptr++;

		ptr%=10;

	}

	rep(i,0,10){

		rep(j,0,cnt[i]){

			cout<<s[i];

		}

	}

	cout<<nline;

}

int main(){ 



	ios_base::sync_with_stdio(false);

	cin.tie(NULL); cout.tie(NULL);

	clock_t time_req=clock();

	/*

	#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("error.txt", "w", stderr);

    freopen("output.txt", "w", stdout);

    #endif

    */

    int t=1;

    //cin>>t;

    while(t--) solve();



    #ifndef ONLINE_JUDGE

    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;

	#endif    



	return 0;

}