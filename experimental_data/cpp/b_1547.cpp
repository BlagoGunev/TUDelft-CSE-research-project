#include<map>

#include<set>

#include<cmath>

#include<stack>

#include<array>

#include<queue>

#include<vector>

#include<string>

#include<iomanip>

#include<cstring>

#include<iostream>

#include<algorithm>

#define rep(i,x,y) for(int i=x;i<=y;i++)

#define per(i,x,y) for(int i=x;i>=y;i--)

using namespace std;

using LL = long long;

using ull = unsigned long long;

using PII = pair<int, int>;

const int N = 1e5 + 10;

const int mod = 998244353;

const double eps = 1e-8;

int a[N];

string s;

void solve() {

	cin >> s;

	int l = 0, r = s.size() - 1;

	per(i, s.size() - 1, 0) {

		char ch = i + 'a';

		if (s[l] == ch)l++;

		else if (s[r] == ch)r--;

		else {

			cout << "NO\n";

			return;

		}

	}

	cout << "YES\n";

}

signed main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T = 1;

	cin >> T;

	while (T--) solve();

}