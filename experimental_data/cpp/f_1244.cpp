#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
string s;

bool same(int i, int j) {
	if (i < 0) i += n;
	if (j < 0) j += n;
	i %= n;
	j %= n;
	return s[i] == s[j];
}

char getColor(int i) {
	if (i < 0) i += n;
	i %= n;
	return s[i];
}

// both inclusive
void updateInterval(int low, int high) {
	char color = getColor(low-1);
	char color2 = getColor(high+1);

	if (high < low) {
		high += n;
	}
	if (same(low-1, high+1)) {
		if (2*k > high - low + 1) {
			// everything turns into the color of the ends
			rep(i, low, high+1) {
				s[i%n] = color;
			}
		}
		else {
			rep(i, low, low+k) {
				s[i%n] = color;
			}
			if ((k&1) == 1) {
				rep(i, low+k, high - k+1) {
					if (s[i%n] == 'W') s[i%n] = 'B';
					else s[i%n] = 'W';
				}
			}
			rep(i, high - k +1, high+1) {
				s[i%n] = color;
			}
		}
	}
	else {
		int change = min(k, (high - low + 1) / 2);
		rep(i, low, low+change) {
			s[i%n] = color;
		}
		if ((k&1) == 1) {
			rep(i, low+change, high - change+1) {
				if (s[i%n] == 'W') s[i%n] = 'B';
				else s[i%n] = 'W';
			}
		}
		rep(i, high - change +1, high+1) {
			s[i%n] = color2;
		}
	}
}

bool alternating() {
	rep(i, 1, n) {
		if (s[i] == s[i-1]) {
			return false;
		}
	}
	if (s[n-1] == s[0]) return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n >> k;
	cin >> s;

	if (alternating()) {
		if ((k&1) == 1) {
			rep(i, 0, n) {
				if (s[i] == 'W') cout << "B";
				else cout << "W";
			}
		}
		else {
			rep(i, 0, n) {
				if (s[i] == 'W') cout << "W";
				else cout << "B";
			}
		}
		cout << endl;
		return 0;
	}

	vi starts;
	vi ends;
	for (int startIndex = 0; startIndex < n; startIndex++) {
		if (same(startIndex-2, startIndex-1) && !same(startIndex-1, startIndex)) {
			int endIndex;
			for (endIndex = startIndex + 1; ; endIndex++) {
				if (same(endIndex - 1, endIndex)) {
					endIndex -= 2;
					break;
				}
			}
			if (endIndex != startIndex - 1) {
				starts.push_back(startIndex);
				ends.push_back(endIndex);
			}
		}
	}
	rep(i, 0, starts.size()) {
		updateInterval(starts[i], ends[i]);
	}

	rep(i, 0, n) {
		cout << s[i];
	}
	cout << endl;
}