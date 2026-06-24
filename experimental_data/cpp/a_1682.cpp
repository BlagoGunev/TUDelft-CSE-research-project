#include <bits/stdc++.h>



#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)



#define ll long long



using namespace std;

                                       

const bool MULTI_TEST = true;

void solve() {         

	int n; cin >> n;

	string s; cin >> s;

	int pos = s.size() / 2;

	int left = pos, right = pos;

	for(int i = pos + 1; i < s.size() && s[i] == s[i - 1]; i++) {

		right = i;

	}



	for(int i = pos - 1; i >= 0 && s[i] == s[i + 1]; i--) {

	 	left = i;

	}



	//cerr << s << ' ' << left << ' ' << right << ' ' << pos << endl;



	cout << right - left + 1 << '\n';

}



int32_t main() {

	fast;

	int T = 1;

	if(MULTI_TEST)

		cin >> T;

	

	while(T--) {

 		solve();

 	}



 	return 0;

}