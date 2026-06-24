//Practice ,practice ,practice ,practice, and practice ,and never stop of practice. 

// this code created by E: Mina Salah Zaki 

#include<iostream>

#include<cmath>

#include<cstdio>

#include <algorithm>

#include<string>

#include<iomanip>

#include<new>

#include <limits>

#include<cassert>

#include<fstream>

#include<vector>

#include<stack>

#include<map>

#include<list>

#include<complex>

#include<sstream>

#include<queue>

#include<valarray>

#include <utility>

#include <numeric>

using namespace std;

void speed() {



	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);



}

#define ll long long 

#define d double

#define pi  3.141592653

#define INF 2'000'000'000

#define ve vector

#define RT(x) return cout << (x), 0;

#define sz(s) (int)(s.size())

#define all(v) v.begin(),v.end()

#define en "\n" 

int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };

int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

typedef vector<int> vi;

ll gcd(ll x, ll y) { return(!y ? x : gcd(y, x % y)); }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

 

int main()

{

	speed();







	int tt; cin >> tt;

	while (tt--) {



		int n;

		cin >> n;

		string s;

		cin >> s;

		int count = 2;

		sort(s.begin(), s.end());

		for (int i = 1; i < n; i++) {

			if (s[i] != s[i - 1])

				count += 2;

			else count++;

		}

		cout << count << en;





	}



	return 0;

}