#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int mod=1000000000+7;

int addm(int& a,int b) {return (a+=b)<mod?a:a-=mod;}

template<class T,class U> bool smin(T& a,U b) {return a>b?(a=b,1):0;}
template<class T,class U> bool smax(T& a,U b) {return a<b?(a=b,1):0;}

ll query(string name) {
	string y=name.substr(4);
	ll fy=1989;
	int len=1;
	ll p10=10;
	while (len<y.size()) {
		len++;
		fy+=p10;
		p10*=10;
	}

	ll toadd=(stoi(y)-fy)%p10;
	if (toadd<0) toadd+=p10;
	return fy+toadd;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string abb;
		cin >> abb;
		cout << query(abb) << '\n';
	}
	
}