#include <iostream>

#include <vector>

using namespace std;



#define fast()      ios_base::sync_with_stdio(false); cin.tie(NULL)

#define endl		"\n"

#define ll			long long int

#define ull			unsigned long long

#define debug(x)	cout<<'['<<#x<<" is "<<x<<"]"<<endl;

#define all(d)		d.begin(),d.end()

#define rall(d)		d.rbegin(), d.rend()





void solve() {

	ll lc, lr;

	ll a, b;

	cin >> a >> b;

	ll r, c;

	cin >> r >> c;

	if ((a - r) > r - 1)

		lc = a - r;

	else

		lc = r - 1;

	if ((b - c) > c - 1)

		lr = b - c;

	else

		lr = c - 1;

	cout << lr + lc << endl;





}

int main() {

	fast();

	ll a;

	cin >> a;

	while (a--)

	{

		solve();

	}

	return 0;

}