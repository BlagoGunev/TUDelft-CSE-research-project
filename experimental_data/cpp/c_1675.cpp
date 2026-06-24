/**
 * @file file.cpp
 * @author EyadAiman
 * @date 2022-04-24
 */

#include <bits/stdc++.h>

using namespace std;

#define Eyad		                				ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll		   	        				long long
#define ull		    	                			unsigned long long
#define fr(n)             	        				for(int i=0; i<n; i++)
#define fr2(n)            	        				for(int i=n; i>=0; i--)
#define yesNo(cond)         	        				cout<<(cond ? "YES":"NO")<<endl
#define test                	        				int t; cin>>t; while(t--)
#define allA(arr,n)	    	        	    			(arr),(arr+n)
#define all(v)		    	        	    			v.begin(),v.end()
#define sz(v)	            	        				(ll)(v.size())
#define pb(n)								push_back(n)
#define minA(a,n)           	        				*min_element(a,a+n)
#define maxA(a,n)           	        				*max_element(a,a+n)
#define minV(v)           	        				*min_element(all(v))
#define maxV(v)           	        				*max_element(all(v))
#define cumSum(v)                       				accumulate(all(v), 0)
#define cumSumA(arr, n)                     				accumulate(allA(arr,n), 0)
#define cumProd(v)                      				accumulate(all(v), 1, multiplies<ll>())
#define sumOfProducts(v)                				inner_product(all(v), v.begin(), 0)
#define productsOfSum(v)                				inner_product(all(v), v.begin(), 1, multiplies<ll>(), plus<ll>())
#define partSum(v1, v2)                 				partial_sum(all(v1), back_inserter(v2))
#define partMinus(v1, v2)               				partial_sum(all(v1), back_inserter(v2), minus<int>())
#define adjDiff(v1, v2)                 				adjacent_difference(all(v1), v2.begin())
#define adjSum(v1, v2)                  				adjacent_difference(all(v1), v2.begin(), plus<ll>())
#define printArr(v,n)                 				        for(int i=0; i<n; i++) cout<<v[i]<<" "
#define cinArr(v,n)                     				fr(n) cin>>v[i]
#define perm(v,n)                       				sort( all(v) );do{printArr(v,n); cout<<"\n";}while(next_permutation(all(v)))
#define addKV(mp,k,v)                                   		mp[k]=v
#define findK(mp,k)                                     		mp.count(k)
#define printSTL(stl)                                   		for (auto li: stl) cout<<li<<" "
#define printMapA(mp)                                   		for (auto mm: mp) cout<< mm.first<< " "<< mm.second<<endl;
#define printMapD(mp)                                   		auto it = mp.rbegin();for(;it!=mp.rend(); it++) cout<< it->first << " "<< it->second<<endl;
#define SS                                            substr
#define MP                                            make_pair

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string>vs;
typedef vector<bool>vb;
typedef vector<ll>vll;
typedef vector<ull>vull;

ll fastPower(ll x, ll n){
    ll res = 1;
    while(n){
        if (n%2!=0) res *=x;
        x=x*x;
        n/=n;
    }
    return res;
}

ll arthSum(ll a1, ll an, ll n){
    return ((a1+an)*n)/2;
}

ll numInArthSum(ll a1, ll d, ll n){
    return a1+(n-1)*d;
}

ll geomSum(ll a1, ll r, ll n){
    return a1*fastPower(r,n-1);
}

ll numInGeoSum(ll a1, ll r, ll n){
    return (a1 - a1*fastPower(r,n)) / (1-r);
}

ll Mod (ll a, ll n){
    return (a%n+n)%n;
}
ll sumMod(ll a, ll b, ll m){
    return ((a%m)+(b%m))%m;
}

ll multMod(ll a, ll b, ll m){
    return ((a%m)*(b%m))%m;
}

ll powMod (ll a, ll b, ll m){
    ll fp = fastPower(a%m, b);
    ll ans = fp%m;
    return ans;
}
/**
If a%n == b%n => (a-b)%n = 0
largest n such that a%n = b%n is n = b-a
(a % n) %n = a % n
(n ^ x) % n = 0 for any x >= 0
( (a*b) % n * (1/a)%n) %n = b % n
**/

ll modularExponential(ll x, ll n, ll m){
    ll res = 1;
    while (n){
        if (n%2!=0) res = multMod(res, x, m);
        x = multMod(x,x,m);
        n/=2;
    }
    return res;
}


bool isPrime(ll n){
    if (n==2) return true;
    if (n<2 || n%2==0) return false;
    for(ll i=3; i*i<=n; i+=2)
        if (n%i==0) return false;
    return true;
}

int countPrimeNumbersSieve(ll n){
    vb isPrime(n+1, true);
    isPrime[0]=isPrime[1]=false;
    for (ll i=2; i*i<=n; i++)
        if (isPrime[i])
            for (ll j=i*2; j<=n; j+=i)
                isPrime[j]=false;
    int cnt=0;
    fr(sz(isPrime))
        if (isPrime[i]) cnt++;

    return cnt;
}

vll generateDivisors(ll n){
    vll divisors;
    ll i;
    for (i=1; i*i<n; i++)
        if (n%i==0) divisors.pb(i), divisors.pb(n/i);
    if (i*i==n) divisors.pb(i);
    return divisors;
}

vll primeFactorization(ll n){
    vll primeDivisors;
    for (ll i=2; i*i<=n; i++)
        while (n%i==0) primeDivisors.pb(i), n/=i;
    if (n>1) primeDivisors.pb(n);
    return primeDivisors;
}

ll gcd (ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

ll lcm (ll a, ll b){
    ll gd = gcd(a,b);
    return (a*b)/gd;
}

ll fact (ll n){
    ll f=1;
    fr2 (n) f*=i;
    return f;

}

ll extendedEuclid(ll a, ll b, ll &x, ll &y){
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1, y1;
    ll g = extendedEuclid(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}



int extendedEuclid_iterative(int a, int b, int& x_prev, int& y_prev)
{
    x_prev=1,y_prev=0;
    int x=0,y=1;
    while (b) {
        int q=a/b;
        tie(x,x_prev)=make_tuple(x_prev-q*x,x);
        tie(y,y_prev)=make_tuple(y_prev-q*y,y);
        tie(a,b)=make_tuple(b,a%b);

    }

    return a;
}

ll extended_eculid(ll a, ll b, ll &x, ll &y){
    if (a<0){
        ll r = extended_eculid(-a,b,x,y);
        x*=-1;
        return r;
    }
    if (b<0){
        ll r = extended_eculid(a, -b, x,y);
        y*=-1;
        return r;
    }
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    ll g = extended_eculid(b, a%b, y, x);
    y-=(a/b)*x;
    return g;
}

ll linear_diophantine(ll a, ll b, ll c, ll &x, ll &y, bool found){
    ll g = extended_eculid(a,b,x,y);
    found = c%g;
    if (!found) x*=c/g, y*=c/g;
    return g;
}



ll modular_multiplicative_inverse(ll a, ll m){
        ll x, y;
        ll d = extendedEuclid(a,m,x,y);
        if (d > 1) return -1;
        return Mod(x,m);
}

ll fermat_little_theorem (ll a, ll m){
    /// use only if m is Prime
    return modularExponential(a, a-2, m);
}


/**
X >> 1	 = 	1001000000 			Equals X/2
X >> 2	 = 	100100000 			Equals X/4
X << 1	 =  100100000000		Equals X*2
X << 2	 =  1001000000000		Equals X*4
**/

void printNum(int n, int len){
    if (!len) return;
    printNum(n>>1, len-1);
    cout<<(n&1);
}

int countBits1(int mask){
    int res=0;
    while(mask){
        if (mask & 1) res++;
        mask>>=1;
    }
    return res;
}

int totalBits(int num){
    return (int)log2(num)+1;
}

int getIndex(string v, char K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end()){
        int index = it - v.begin();
        return index;
    }
    else return -1;
}



int main(){
    Eyad
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        ll cnt=0;
        if (s[0] == 0) {cout<<1<<"\n"; continue;}
        if (s == "1") {cout<<1<<"\n";continue;}
        int cdon = count(all(s), '?');
        if (sz(s) == cdon) {cout<<sz(s)<<"\n"; continue;}
        int size = sz(s);
        int left = 0, right = size-1;
        fr(size) if (s[i] == '0') {right = i; break; }
        fr2(size-1){
            if (s[i] == '1') {left = i; break;}
        }
        cout<< abs(right - left)+1<<"\n";
    }
}