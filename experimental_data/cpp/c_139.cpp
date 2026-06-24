#include <iostream>

#include <string>

#include <vector>

#include <map>

#include <queue>

#include <stack>

#include <deque> 

#include <set>

#include <sstream>

#include <cmath>

#include <algorithm>

#include <cstdlib>

#include <cstdio>

#include <ctime>

using namespace std;

#define INF 1000010000



bool suf(string &s, int k){

	vector <char> g = { 'a', 'e', 'i', 'o', 'u' };

	int r = s.length() - 1;

	while (k > 0 && r >= 0){

		if (s[r] == g[0] || s[r] == g[1] || s[r] == g[2] || s[r] == g[3] || s[r] == g[4])--k;

		--r;

	}

	if (r < 0 && k > 0)return false;

	s.replace(0, r + 1, "");

	return true;

}



int main() {

	//freopen("input.txt","r",stdin);

	//freopen("output.txt","w",stdout);

	int n, k;

	cin >> n >> k;

	int ans = 0;

	bool ck = true;

	for (int i = 0; i < n; ++i){

		string a, b, c, d;

		cin >> a >> b >> c >> d;

		if (!suf(a, k)){

			ck = false;

		}

		if (!suf(b, k)){

			ck = false;

		}

		if (!suf(c, k)){

			ck = false;

		}

		if (!suf(d, k)){

			ck = false;

		}

		int t = 0;

		if (a == b && c == d && b != c)t = 1;

		if (a == c && b == d && b != c)t = 2;

		if (a != b && a == d && b == c)t = 3;

		if (a == b && b == c && c == d)t = 4;

		if (t == 0){

			ck = false;

		}

		if (ans == 0){

			ans = t;

			continue;

		}

		if (ans == t)continue;

		if (ans == 4){

			ans = t;

			continue;

		}

		if (t == 4)continue;

		if (ans != t){

			ck = false;

		}

	}

	if (!ck){

		cout << "NO\n";

		return 0;

	}

	if (ans == 1){

		cout << "aabb\n";

	}

	else if (ans == 2){

		cout << "abab\n";

	}

	else if (ans == 3){

		cout << "abba\n";

	}

	else if (ans == 4){

		cout << "aaaa\n";

	}

	return 0;

}