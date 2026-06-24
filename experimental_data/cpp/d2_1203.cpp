#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream> //stringstream
#include <cstring> // getline
#include <cmath>
#include <unordered_set>
#include <limits>
#include <unordered_map>

#define _CRT_SECURE_NO_WARNINGS
#define ll 				long long int
#define ld				long double
#define FOR(i, b, e)    for (ll i =(b)-((b)>(e));i!=(e)-((b)>(e));i += 1-2*((b)>(e)))
#define EPS  			1e-9
#define all(v) 			v.begin(),v.end()
#define X 				first 
#define Y 				second
#define IO 				std::ios_base::sync_with_stdio(0);cin.tie(NULL);
#define MAXI 			100005
#define endl 			'\n'
#define re   			return
#define mp				make_pair
#define NumofDigits(n)  ((int)log10(n)+1)
#define fixedpre(n)     fixed<<setprecision(n);
#define sz size()

using namespace std;

const double PI = acos(-1);
ll MOD = 1e9 + 7;
ll OO = 1e18 + 8;
int oo = 1e9 + 9;

ll pw(ll b, ll p) { if (!p) re 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; re sq; }
ll gcd(ll a, ll b) { re(b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { re((a*b) / gcd(a, b)); }
ll PowMod(ll bs, ll ex, ll M) { if (!ex)re 1; ll p = PowMod((bs*bs) % M, ex >> 1, M); re(ex & 1) ? (p*bs) % M : p; }
ll ModInverse(ll a) { re PowMod(a, MOD - 2, MOD); }
ll ExtGCD(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; re a; } ll r = ExtGCD(b, a%b, y, x); y -= a / b*x; re r; }
ll mult(ll a, ll b) { re(1LL * a * b) % MOD; }

bool cmp(double a, double b) { re abs(a - b)<EPS; }
bool isint(double a) { re cmp(a, round(a)); }
bool isPrime(ll n) { if (n == 2)re 1; if (n<2 || n % 2 == 0)re 0; for (ll i = 3; i*i <= n; i += 2)if (n%i == 0)re 0; re 1; }
bool isPalindrome(string str) { ll l = 0; ll h = str.size() - 1; while (h > l) { if (str[l++] != str[h--]) { re 0; } } re 1; }
bool isPerfectSquare(ld x) { ld sr = sqrt(x); re((sr - floor(sr)) == 0); }

double EucildDistance(double x, double y, double xx, double yy) { re sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy)); };

//freopen("input.txt", "r", stdin);
//freopen ("output.txt","w",stdout);

int dx[6] = { 1, -1, 0, 0, 0, 0 }, dy[6] = { 0, 0, 1, -1, 0, 0 }, dz[6] = { 0, 0, 0, 0, 1, -1 };

string s, t;
int n, m;

int main()
{
	IO;
	cin >> s >> t;
	n = s.length(), m = t.length();
	vector<int> f(m), l(m);
	for (int i = 0, j = 0; i < s.length() && j < t.length(); i++)
		if (s[i] == t[j]) f[j] = i, j++;
	
	for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--)
		if (s[i] == t[j]) l[j] = i, j--;
	
	int maxi = max(l[0], n - f[m - 1] - 1);

	for (int i = 1; i < m; i++)
		maxi = max(l[i] - f[i - 1] - 1, maxi);
	cout << maxi << endl;
	re 0;
}