#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const ll  inf = 1000000000000000000LL;
const double EPS = 1e-9;
const ll mod = 1000000007ll;
#define PI acos(-1)



const int  maxn = (int)600500 + 10;

vector<pair<ll, ll> > factors;
void getFactors(ll n) {
	factors.clear();
	ll d = 1;
	for (ll i = 2; i * i <= n; i += d, d = 2)
		if (n % i == 0) {
			factors.push_back(make_pair(i, 0));
			while (n % i == 0) {
				n /= i;
				factors.back().second++;
			}
		}
	if (n != 1)
		factors.push_back(make_pair(n, 1));
}

vector<ll> divisors;
void getDivisors(ll ind = 0, ll res = 1) {
	if (ind == (ll)factors.size()) {
		divisors.push_back(res);
		return;
	}
	for (ll i = 0; i <= factors[ind].second; i++) {
		getDivisors(ind + 1, res);
		res *= factors[ind].first;
	}
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	ll n, k;
	scanf("%lld%lld", &n, &k);
	getFactors(n);
	getDivisors();
	k--;
	sort(divisors.begin(), divisors.end());
	if (divisors.size() <= k) puts("-1");
	else printf("%lld", divisors[k]);
}