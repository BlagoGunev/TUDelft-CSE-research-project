#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair <int, int>
#define vi vector <int>
#define vl vector <ll>
#define pll pair <ll, ll> 
#define PI acos(-1)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define MEM(a, b) memset(a, b, sizeof(a))
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/gcd(a,b)))
#define SQR(a) ((a)*(a))
#define INF 100000000
#define MOD 1000000007
#define EPS 1e-9
#define harmonic(n) 0.57721566490153286l+log(n)
#define nl puts("")
#define all(v) v.begin(), v.end()
#define vsort(v) sort(all(v))
#define uniq(v) v.resize( unique(all(v)) - v.begin())
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
inline bool EQ(double a, double b) { return fabs(a - b) < EPS; }

//debug
#ifdef kfoozminus

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << *it;
	}
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin()) os << ", ";
		os << *it;
	}
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second ;
	}
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n ) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

#else
#define dbg(args...)
#endif
//debug

/*
ll add(ll a, ll b, ll m = MOD) {
	ll ret = a + b;
	if(ret >= m) ret -= m;
	return ret;
}

ll subtract(ll a, ll b, ll m = MOD) {
	ll ret = a - b;
	if(ret < 0) ret += m;
	return ret;
}

ll mult(ll a, ll b, ll m = MOD) {
	ll ret = a * b;
	if(ret >= m) ret %= m;
	return ret;
}

ll bigmod(ll a, ll b, ll m = MOD) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = mult(ret, a, m);
		b >>= 1;
		a = mult(a, a, m);
	}
	return ret;
}

ll inverse(ll n, ll m = MOD) { return bigmod(n, m - 2); }
*/

/*
#define PMX 1000000

int marked[PMX/64 + 2];
vi primes;

#define mark(x) marked[x >> 6] |= (1 << ((x & 63) >> 1))
#define check(x) (marked[x >> 6] & (1 << ((x & 63) >> 1)))

bool isPrime(int x)
{
	return (x > 1) && ((x == 2) || ((x & 1) && (!(check(x)))));
}

void seive(int n)
{
	int i, j;
	for(i = 3; i * i <= n; i += 2) if(!check(i)) for(j = i * i; j <= n; j += i << 1) mark(j);
	primes.PB(2);
	for(i = 3; i <= n; i += 2) if(isPrime(i)) primes.PB(i);
}
*/

//int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};

/*
bool checkBit(int n, int i) { return (n&(1<<i)); }
int setBit(int n, int i) { return (n|(1<<i)); }
int resetBit(int n, int i) { return (n&(~(1<<i))); }
*/

#define MX 100007

int main () {
#ifdef kfoozminus
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	ll d, x, y, k, bar, cnt, ans = 0, n, D, M;

	scanf("%lld %lld %lld %lld", &n, &k, &M, &D);

	for(d = 1; d <= D; d ++) {
		x = k;
		y = d - 1;
		if(y) {
			if(x * y >= n) break;
			if(x >= n/y) break;
		}
		bar = x * y + 1;
		x = n/bar;
		dbg(x);
		x = min(x, M);
		//if(x > M) continue;
		dbg(d);
		cnt = x * d;
		ans = max(ans, cnt);
	}
	printf("%lld\n", ans);

//	timeStamp;
	return 0;
}