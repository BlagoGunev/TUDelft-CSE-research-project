#include <stdio.h>
#include <iostream>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair <int, int> ii;

int n;
char en[500];

int process(){

	char c;

	cin >> n;

	int ngang = 0, doc = 0;

	int res = 0;

	for (int i = 1; i <= n; i++){
		cin >> c;
		if (c == 'L' || c == 'R'){
			if (ngang == c) continue;
			if (ngang == 0) { ngang = c; continue; }
			else {
				//cout << i << ' ' << c << endl;
				res++;
				ngang = c;
				doc = 0;
			}
		}
		else {
			if (doc == c) continue;
			if (doc == 0) { doc = c; continue; }
			else {
				//cout << i << ' ' << c << endl;
				res++;
				ngang = 0;
				doc = c;
			}
		}
	}

	cout << res+1;

	return 0;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("1.INP", "r", stdin);
		freopen("1.OUT", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	process();

	return 0;
}