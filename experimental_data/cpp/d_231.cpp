#include <bits/stdc++.h>



using namespace std;



#define vi vector<int>

#define pii pair<int, int>

#define endl '\n'



typedef long long int64;



const double eps = 1e-9;

const int oo = 0x3f3f3f3f;



int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);	

	

	int x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;

	cin >> x >> y >> z >> x1 >> y1 >> z1 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;



	int ans = 0;



	if (y < 0)

		ans += a1;

	else if	(y > y1)

		ans += a2;



	if (z < 0)

		ans += a3;

	else if	(z > z1)

		ans += a4;



	if (x < 0)

		ans += a5;

	else if	(x > x1)

		ans += a6;



	cout << ans << endl;



	return 0;

}