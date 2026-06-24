#include <bits/stdc++.h>

using namespace std;

#define int long long

int n , k , p , fib[111];

vector <int> ans;

int32_t main(){

	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin >> n >> k;

	fib[1] = 1; 

	for(int i = 2 ; i <= n ; i++)

		fib[i] = fib[i-1] + fib[i-2];

	while(n > 0){

		if(k > (fib[n])){

			k -= fib[n];

			ans.push_back(2);

			n -= 2;

		}else{

			ans.push_back(1);

			n --;

		}

	}

	for(int x : ans){

		//cout << x << ' ';

		cout << p+x << ' ';

		if(x == 2) cout << p+1 << ' ';

		p += x;

	}

}