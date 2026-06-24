#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define ll long long 
//#pragma comment (linker,"/STACK:200000000")

using namespace std;

//ifstream cin ("input.txt"); ofstream cout ("output.txt");
//ifstream cin ("rooms.in"); ofstream cout ("rooms.out");
ll maxl(ll aa, ll bb) {
	if (aa<bb) return bb;
	else return aa;
}
ll minl(ll aa, ll bb) {
	if (aa>bb) return bb;
	else return aa;
}
double maxd(double aa, double bb) {
	if (aa>bb) return aa;
	else return bb;
}
double mind(double aa, double bb) {
	if (aa<bb) return aa;
	else return bb;
}
ll step(ll a, ll n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) return step(a*a, n / 2);
	else return a*step(a, n - 1);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	map<string,vector<int>> A;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		int x;
		cin >> x;
		A[tmp].push_back(x);
	}
	ll ans = 0;
	ll minim = 0, odin=0;
	for (auto i : A) {
		vector<int> a, b;
		a = i.second;
		string p = i.first;
		reverse(p.begin(), p.end());
		b = A[p];
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		if(p!=i.first){
			for (int j = 0; j < min(a.size(), b.size()); j++) {
				if (a[j] + b[j] >= 0) ans += a[j] + b[j];
			}
		}
		else {
			for (int j = 0; j < a.size()-1; j+=2) {
				if (a[j] >= 0 && a[j + 1] >= 0) odin += a[j] + a[j + 1];
				else if (a[j] + a[j + 1] >= 0) {
					odin+= a[j] + a[j + 1];
					minim = minl(minim, a[j + 1]);
				}
				else if (a[j] >= 0) {
					minim = minl(minim, -a[j]);
				}
			}
			if (a.size() % 2 == 1) {
				minim = minl(minim, -a.back());
			}
		}
	}
	cout << ans/2+odin-minim;
}