// besmellah
#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 3e3+10;
const int64 MO = 1000000007;
const int64 IN = 1000000000;

int a[maxn];
int cnt[maxn];
int T, n;

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int ff = 0; ff < T; ff++) {
		cin >> n;
		for (int i = 0; i <= n; i++)
			cnt[i] = 0;
		
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		int64 ans = 0;
		cnt[a[n - 1]] = 1;
		for (int i = n - 2; i >= 0; i--) {
			int cur = 0;
			for (int t = 0; t < i; t++) {
				ans += cur * cnt[a[t]];
				if (a[t] == a[i])
					cur++;
			}	
			cnt[a[i]]++;
		}

		cout << ans << "\n";
	}
}