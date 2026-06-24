// In the name of God

#include <iostream>

#include <cmath>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <iomanip>

#include <ctime>

#include <queue>

#include <set>

#include <map>

#include <vector>

#include <list>

#include <bitset>

#define sqr(a) (a)*(a)

using namespace std;



template <typename T>

T next_int() {

	T x = 0, p = 1;

	char ch;

	do { ch = getchar(); } while(ch <= ' ');

	if(ch == '-') {

		p = -1;

		ch = getchar();

	}

	while(ch >= '0' && ch <= '9') {

		x = x * 10 + (ch - '0');

		ch = getchar();

	}

	return p * x;

}

	

const int max_int = (int)1e9 + 227 + 1;

const int max_n = (int)1e6 + 227 + 1;	

const int mod = (int)1e9 + 7;



bool check(vector<string> a, vector<string> b) {

	int j = 0;

	for(int i = 0; i < a.size(); i++) {

		while(j < b.size() && b[j] != a[i]) j++;



		if(j == b.size()) return 0;



		j++;

	}



	return 1;

}



int get(vector<int> a) {

	int ans = 0;

	for(int i = 0; i < a.size(); i++)

		for(int j = 0; j < i; j++)

			if(a[i] < a[j]) ans++;

	return ans;

}



vector<string> get(vector<string> a, vector<int> b) {

	vector<string> ans = a;



	for(int i = 0; i < b.size(); i++) ans[b[i]] = a[i];



	return ans;

}



int main() {

//	freopen(".in", "r", stdin);



	int n = next_int<int>();



	vector<string> a(n);

	for(int i = 0; i < n; i++) cin >> a[i];



	int f = 1;

	for(int i = 2; i <= n; i++) f *= i;



	vector<int> c;

	for(int i = 0; i < n; i++) 

		c.push_back(i);



	int m = next_int<int>();



	int ans = -max_int;

	int p = -1;

	for(int i = 1; i <= m; i++) {

		int k = next_int<int>();



		vector<string> b(k);

		for(int j = 0; j < k; j++) cin >> b[j];



		int kek = max_int;

		for(int it = 0; it < f; it++) {

			if(check(get(a, c), b)) {

				kek = min(kek, get(c));

			}



			next_permutation(c.begin(), c.end());

		}



		if(kek == max_int) continue;



		kek = n * (n - 1) / 2 - kek + 1;



		if(ans < kek) {

			ans = kek;

			p = i;

		}

	}



	if(p == -1) {

		puts("Brand new problem!");

	} else {

		cout << p << "\n";

		cout << "[:";

		while(ans--) cout << "|";

		puts(":]");

	}

}