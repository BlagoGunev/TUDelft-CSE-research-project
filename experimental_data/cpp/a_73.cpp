// In the name of ALLAH

#include <bits/stdc++.h>

using namespace std;



#define int ll



#define PB push_back

#define PF push_front

#define MP make_pair

#define FF first

#define SS second

#define _sz(x) (int)x.size()



typedef long long ll;

typedef long double ld;

typedef pair <int, int> pii;



int a[3], b[3], k;



int32_t main(){

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> a[0] >> a[1] >> a[2] >> k; k = min(k, a[0] + a[1] + a[2] - 3);

	sort(a, a + 3);



	for (int i = 0; i < 3; i ++) b[i] = k / 3;

	for (int i = 0; i < k % 3; i ++) b[2 - i] ++;



	for (int i = 0; i < 2; i ++){

		if (b[i] >= a[i]){

	  		b[2] += b[i] - (a[i] - 1);

			b[i] = a[i] - 1;

		}

	}



	while (b[2] - 1 >= b[1] + 1 && b[1] + 1 < a[1]) b[1] ++, b[2] --;



//	cout << ' ' << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';

	cout << (b[0] + 1) * (b[1] + 1) * (b[2] + 1) << '\n';

}