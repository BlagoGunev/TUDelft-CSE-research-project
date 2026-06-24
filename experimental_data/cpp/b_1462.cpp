// URL: https://codeforces.com/contest/1462/problem/B

// NAME: B. Last Year's Substring, Codeforces - Codeforces Round #690 (Div. 3)

// LIMIT: 256 MB, 2000 ms

// DATE: 2022-08-08 15:59:23



#include <bits/stdc++.h>



using namespace std;



#ifdef github_fengwei2002

#include "algo/debug.h"

#else

#define debug(...) 42

#endif

/*-----------------------*/



bool canTrans(string& s) {

	const int n = s.size(); 

	

	for (int i = 0; i <= 4; i++) {

		if (s.substr(0, i) + s.substr(n - 4 + i, 4 - i) == "2020") {

			return true; 

		}

	} 

	

	return false;

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    

    int tt = 0; 

    cin >> tt; 

    

    while (tt--) {

    	int n = 0;

    	cin >> n; 

    	string s = ""; 

    	cin >> s; 

    	if (canTrans(s)) {

    		cout << "YES" << endl; 

    	} else {

    		cout << "NO" << endl; 

    	}

    } 



    return 0;

}





/*







*/