#include <iostream>

#include <string>

#include <stdio.h>

#include <vector>

#include <algorithm>

#include <math.h>

#include <queue>

#include <set>

#include <map>

#pragma warning(disable:4996)

using namespace std;

typedef long long ll;

int n, a[207],col[207],cyc=1,p[207],cycIn[207];

vector <int> gr[207];

void dfs(int v){

	col[v] = 1;

	for (int i = 0; i < gr[v].size(); i++){

		int w = gr[v][i];

		if (col[w] == 0){

			p[w] = v;

			dfs(w);

		}

		else if (col[w] == 1){

			int cyc_beg = w, cyc_end = v;

			while (cyc_end != cyc_beg){

				cycIn[cyc_end] = cyc, cyc_end = p[cyc_end];

			}

			cycIn[cyc_beg] = cyc;

			cyc++;

		}

	}

	col[v] = 2;

}

ll gcd(ll a, ll b){

	if (b == 0) return a;

	else return gcd(b, a%b);

}

int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) { 

		scanf("%d", &a[i]); 

		gr[i].push_back(a[i]);

	}

	for (int i = 1; i <= n; i++)

	if (col[i] == 0) dfs(i);

	ll ans = 1;

	for (int i = 1; i < cyc; i++){

		int cnt = 0;

		for (int j = 1; j <= n; j++) if (cycIn[j] == i) cnt++;

		ans = (ans*cnt) / gcd(ans, cnt);

	}

	int mx = 1;

	for (int i = 1; i <= n; i++){

		if (cycIn[i] == 0){

			int cnt = 0,v=i;

			while (cycIn[v] == 0) 

				v = gr[v][0],cnt++;

			mx = max(mx, cnt);

		}

	}

	ans = ans*ceil(mx / (ans+0.0));

	cout << ans;

	//cin >> n;

	return 0;

}