// Problem: B. Mathematical Circus

// Contest: Codeforces - Codeforces Round #814 (Div. 2)

// URL: https://codeforces.com/contest/1719/problem/B

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

using namespace std;

void solve(){

	int n;

	long long m;

	cin >> n >> m;

	if(n % 2 == 0){

		if((1 + m) * 2 % 4 != 0 && (2 + m) % 4 != 0)cout << "NO" << '\n';

		else {

			cout << "YES" << '\n';

			for(long long i = 1; i <= n; i+=2){

				if((i + m) * (i + 1) % 4ll == 0){

					cout << i << " " << i + 1 << '\n';

				}

				else {

					cout << i + 1 << " " << i << '\n';

				}

			}

		}

	}

	else {

		cout << "NO" << '\n';

	}

}

int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);

	int t;

	cin >> t;

	while(t--)solve();

}