#include<iostream>

#include<stdio.h>

#include<vector>

#include<algorithm>

#include<memory.h>

#include<stack>

#include<queue>

#include<map>

#include<string>

#include<set>

using namespace std;

#define ll long long

#define f(i,x,n) for (int i = x; i < n; ++i)

#define mp make_pair

const int N = 1e+5;

int main(){

	ll r, ans = 0;

	int n[3], p[3], f[3] = { 0 }, d = 0, m = 0;

	string s;

	cin >> s;

	f(i, 0, s.size())

		if (s[i] == 'B')f[0]++;

		else if (s[i] == 'S')f[1]++;

		else f[2]++;

		f(i, 0, 3)cin >> n[i];

		f(i, 0, 3){

			cin >> p[i];

			d += f[i] * p[i];

		}

		cin >> r;

		while(1){

			f(i, 0, 3)

				if (f[i] > 0)m = max(m, n[i] / f[i]);

			int i = 1;

			while (i <= m){

				while (f[0] > 0 && r - p[0] >= 0 && n[0] / f[0] < i){

					n[0]++;

					r -= p[0];

				}

				while (f[1] > 0 && r - p[1] >= 0 && n[1] / f[1] < i){

					n[1]++;

					r -= p[1];

				}

				while (f[2] > 0 && r - p[2] >= 0 && n[2] / f[2] < i){

					n[2]++;

					r -= p[2];

				}

				i++;

			}

			f(i, 0, 3)if (f[i] > 0)m = min(m, n[i] / f[i]);

			f(i, 0, 3)n[i] -= (m*f[i]);

			ans += m + r / d;

			if(m + r / d == 0)break;

			r %= d;

		}

		cout << ans;

		return 0;

}