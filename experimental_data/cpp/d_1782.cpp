#include <bits/stdc++.h>

using namespace std;



void solve(){

	int n, a[205];

	cin >> n; 

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1,a + 1 + n);

	int ans = 1;

	for (int i = 1; i <= n; i++){

		for (int j = i + 1; j <= n; j++ ){

			int diff = a[j] - a[i];

			for (int t = 1; t * t <= diff; t++){

				if (diff % t != 0) continue ;

				if ((t + diff / t) % 2 == 1) continue ;

				long long QAQ = (diff / t - t) / 2;

				long long k = QAQ * QAQ - a[i];

//				cout << QAQ << " " << k << endl;

				if (k < 0) continue;

			

				int num = 0;

				for (int u = 1; u <= n; u++ ){

					long long t = sqrtl(a[u] + k);

					if (t * t == a[u] + k) num++;

				} 

//				cout << k << " " << num << endl;

				ans = max(ans, num);

			}

		}

	}

	cout << ans << endl;

	

	

}



int main(){

	int T;

	cin >>T ;

	while (T--){

		solve();

	}

}