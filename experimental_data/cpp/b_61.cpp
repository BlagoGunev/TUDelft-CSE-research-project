#include <bits/stdc++.h>

#include <ext/numeric>



using namespace std;

using namespace __gnu_cxx;



typedef long long ll;

typedef unsigned long long ull;



void fastInOut();



string st[3];



string fix(string a) {

	string ret = "";

	for (int i = 0; i < int(a.size()); ++i) {

		char cur = tolower(a[i]);

		if (cur >= 'a' && cur <= 'z')

			ret += cur;

	}

	return ret;

}



bool ok(string cur, int msk) {

	if (msk == 7)

		return (cur == "");

	for (int i = 0; i < 3; ++i) {

		if (((msk >> i) & 1) || cur.substr(0, st[i].size()) != st[i])

			continue;

		if (ok(cur.substr(st[i].size()), (1 << i) | msk))

			return 1;

	}

	return 0;

}



int main() {

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

#endif

	fastInOut();

	for (int i = 0; i < 3; ++i)

		cin >> st[i], st[i] = fix(st[i]);

	int n;

	string x;

	cin >> n;

	while (n--) {

		cin >> x, x = fix(x);

		cout << (ok(x, 0) ? "ACC\n" : "WA\n");

	}

	return 0;

}



void fastInOut() {

	ios_base::sync_with_stdio(0);

	cin.tie(NULL), cout.tie(NULL);

}