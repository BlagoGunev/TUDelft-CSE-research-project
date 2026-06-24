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



int tin[max_n];

int tout[max_n];



vector<pair<int, int> > a[max_n];



int mda[max_n][20];

int timer;



void go(int v, int pr) {

	tin[v] = ++timer;



	for(int i = 0; i < 20; i++) mda[v][i] = -1;



	mda[v][0] = pr;

	for(int i = 1; i < 20; i++)

		if(mda[v][i - 1] != -1)

			mda[v][i] = mda[mda[v][i - 1]][i - 1];



	for(int i = 0; i < a[v].size(); i++) {

		if(a[v][i].first == pr) continue;



		go(a[v][i].first, v);

	}



	tout[v] = ++timer;

}



bool check(int a, int b) {

	return tin[a] <= tin[b] && tout[a] >= tout[b];

}

 

int get(int f, int s) {

	int ans = 0;

 

	if(!check(f, s)) {

		for(int i = 19; i >= 0; i--) {

			if(mda[f][i] != -1 && !check(mda[f][i], s)){

				f = mda[f][i];

 

				ans += (1 << i);

			}

		}

		

		ans++;

		f = mda[f][0];

	}

 

	if(!check(s, f)) {

		for(int i = 19; i >= 0; i--) {

			if(mda[s][i] != -1 && !check(mda[s][i], f)){

				s = mda[s][i];

 

				ans += (1 << i);

			}

		}

		

		ans++;

		s = mda[s][0];

	}

 

	return f;

}



int ans[max_n];

int d[max_n];



int gey(int v, int pr) {

	int sum = d[v];

	for(int i = 0; i < a[v].size(); i++) {

		if(a[v][i].first == pr) continue;



		int temp = gey(a[v][i].first, v);



		sum += temp;

		ans[a[v][i].second] += temp;

	}

	return sum;

}



int main() {

//	freopen(".in", "r", stdin);



	int n = next_int<int>();

	for(int i = 0; i < n - 1; i++) {

		int x = next_int<int>() - 1;

		int y = next_int<int>() - 1;



		a[x].push_back(make_pair(y, i));

		a[y].push_back(make_pair(x, i));

	}



	go(0, -1);



	int m = next_int<int>();

	while(m--) {

		int x = next_int<int>() - 1;

		int y = next_int<int>() - 1;



		if(x == y) continue;



		int lca = get(x, y);



		int k = 0;

		if(x != lca) d[x]--, k++;

		if(y != lca) d[y]--, k++;



		d[lca] += k;

	}



	gey(0, -1);



	for(int i = 0; i < n - 1; i++) cout << -ans[i] << " ";

	puts("");

}