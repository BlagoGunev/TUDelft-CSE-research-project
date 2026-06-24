#include<bits/stdc++.h>
using namespace std;

#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))

int dx[] = { 0,0,1,-1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,1,-1 };

template <class T> inline T biton(T n, T pos) { return n | ((T)1 << pos); }
template <class T> inline T bitoff(T n, T pos) { return n & ~((T)1 << pos); }
template <class T> inline T ison(T n, T pos) { return (bool)(n & ((T)1 << pos)); }
template <class T> inline T gcd(T a, T b) { while (b) { a = a%b; swap(a, b); } return a; }
template <class T> inline T bigmod(T p, T e, T m) { T ret = 1; for (; e > 0; e >>= 1) { if (e & 1) ret = (ret * p) % m; p = (p * p) % m; } return (T)ret; }


int f = -1, s = -1;

void divisors(int k) {
	int sqrtn = sqrt(k);
	for (int i = 1; i <= sqrtn; i++) {

		if (k%i == 0) {
			int a = k / i;
			int b = i;

			if (a >= 5 && b >= 5)
			{
				f = a;
				s = b;
			}
		}
	}
}



void solve() {
	
	int k;
	cin >> k;

	divisors(k);

	if (f == -1)
	{
		cout << -1 << endl;
		return;
	}

	string vowel = "aeiou";
	
	string res = "";

	for (int i = 0; i < f; i++) {
		
		int temp = i;

		for (int j = 0; j < s; j++) {

			res += vowel[temp % 5];
			temp++;
		}
	}

	cout << res << endl;

}

int main()
{

	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10); cout.tie(nullptr); cin.tie(nullptr);

	int t = 1;

	while (t--) {

		solve();
	}

	int p;
	cin >> p;

	return 0;
}