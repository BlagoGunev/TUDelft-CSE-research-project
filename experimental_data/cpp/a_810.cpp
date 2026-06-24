#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <set>
#include <cstdio>
#include <map>
#include <algorithm>
#include <ctype.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <utility>
#include <queue>
#include <iomanip>
#include <stack>
#include <bitset>
#include <functional>

#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define MAX_N 1000000007
#define ll long long
#define ld long double
template <class T> T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int i = n;
	while ((int)((ld)sum / (ld)i + 0.500000000000000001) != k) {
		sum += k;
		i++;
	}

	cout << i - n;
}