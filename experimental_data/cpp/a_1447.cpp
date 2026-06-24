#include<iostream>

#include<queue>

#include<vector>

#include<cmath>

#include<set>

#include<map>

#include<bitset>

#include<cstring>

#define endl "\n"

#define ll long long

#define vi vector<int>

#define vl vector<long long>

#define vd vector<double>

#define YO cout<<"YES\n"

#define NO cout<<"NO\n"

# define FAST ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)

using namespace std;

//const int N = 1e5 + 3;

//int a[N];

//ll dp[N];

ll fact(ll n, ll r) {

	if (n == 0 || n == 1 || n == r)

		return 1;

	else

		return n * fact(n - 1, r);

}

double C(double n, double r, double g) {

	if (n == 0) { return 1; }

	return (n / (max(r, (double)1) * max(g, (double)1))) * C(n - 1, r - 1, g - 1);

}

int main() {

	FAST;

	int t; cin >> t;

	while (t--) {

		int n; cin >> n;

		cout << n << endl;

		for (int i = 1; i <= n; i++) { cout << i << " "; }

		cout << endl;

	}

}