#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>
#include <fstream>
#include <ctime>

using ll = long long;
using LL = long long;

#define ld long double
#define ull unsigned ll
#define mp(xx, yy) make_pair(xx, yy)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define pll pair<ll, ll> 
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vs vector<string>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define forn(i,n) for (int i=0;i<n;i++)
#define fornDesc(i,n) for (int i=n-1;i>=0;i--)
#define foran(i,a,n) for (int i=a;i<n;i++)

ld pi = acos(-1.0);
const int mod = 1e9 + 7;
using namespace std;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

LL lcm(LL a, LL b) {
	return (a * b / gcd(a, b));
}
ll sum(vll a) {
	ll s = 0;
	forn(i, a.size()) {
		s += a[i];
	}
	return s;
}
ll fact(ll a) {
	if (a < 2) return 1;
	return a * fact(a - 1);
}


int uppBound(ll array[], ll sum, int left, int right) {
	if (left == right) {
		return -1;
	}
	while (left < right) {
		ll sr = (left + right) / 2;

		if (sum < array[sr]) {
			right = sr; 
		}
		else {
			left = sr + 1;
		}
	}
	return left-1; 
}

ll MAX(ll a, ll b) {
	if (a > b)return a;
	
	return b;
}
void solve()
{
	int n;
	cin >> n;
	int B;
	cin >> B;

	int x;
	cin >> x;
	int y;
	cin >> y;

	ll sum = 0;

	int pred = 0;
	forn(i, n) {
		int current = 0;
		if (pred + x <= B) {
			current = pred + x;
		}
		else {
			current = pred - y;
		}
		pred = current;
		sum += current;
	}
	
	cout << sum << "\n";
	return;
}

int main() {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;

}