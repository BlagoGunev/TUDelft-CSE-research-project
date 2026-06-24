#include <iostream>

#include <cstdio>

#include <cmath>

#include <algorithm>

#include <set>

#include <map>

#include <queue>

#include <vector>

#include <iomanip>

#include <ctime>

using namespace std;



template <typename T>

T next_int() {

	T p = 1, x = 0;

	char ch;

	do { ch = getchar(); } while(ch <= ' ') ;

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



const int max_n = (int)1e6 + 227 + 1;

const int max_int = (int)1e9 + 227 + 1;

const int mod = (int)1e9 + 7;



struct BOR {

	int p[2];

	int k;

} new_bor;



vector<BOR> t;



void add(int a) {

	int v = 0;



	t[v].k++;



	for(int i = 29; i >= 0; i--) {

		bool next = ((1 << i) & a);



		if(!t[v].p[next]) {

			t[v].p[next] = t.size();

			t.push_back(new_bor);

		}



		v = t[v].p[next];

		t[v].k++;

	}            

}



int get(int a, int b) {

	int v = 0;



	int ans = 0;

	bool ok = 1;

	for(int i = 29; i >= 0; i--) {

		bool f = ((1 << i) & a);

		bool s = ((1 << i) & b);



		if(s == 0) {

			if(t[v].p[1 - f]) ans += t[t[v].p[1 - f]].k;

		}



		if(!t[v].p[f ^ s]) {

			ok = 0;

			break;

		}



		v = t[v].p[f ^ s];

	}



	if(ok) ans += t[v].k;



	return ans;

} 



// a ^ ? >= b



int main() {

//	freopen(".in", "r", stdin);



	t.push_back(new_bor);



	int n = next_int<int>();

	int m = next_int<int>();



	int e = 0;

	long long ans = 0;

	for(int i = 0; i < n; i++) {

		add(e);



		int a = next_int<int>();



		e ^= a;



		ans += get(e, m);

	}



	cout << ans << "\n";

}