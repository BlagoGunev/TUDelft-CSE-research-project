#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define eps 1e-9
#define all(a)   a.begin(),a.end()
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define sz size()
#define rd(inp) scanf("%lld",&inp)
#define rd2(inp1, inp2) scanf("%lld %lld",&inp1, &inp2)
#define rl(inp) scanf("%d",&inp)
#define pf(out) printf("%lld\n", out);

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int inf = 1e9;

ll read(){
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus){
		return -result;
	}
	else{
		return result;
	}
}

ll fpow(ll base,ll power){
	ll result = 1;
	while (power > 0){
		if (power%2 == 1) result=(result*base);
  		base = (base*base);
  		power /= 2;
  	}
	return result;
}

int lasttrick = 1;
vector<ll> v1, v2;

int main(){
  	ll n;
  	ll p1 , p2;
  	p1 = p2 = 0;
  	n = read();
  	ll i;
  	for ( i = 0 ; i < n ; i ++ ){
  		ll x;
  		x = read();
  		if ( x < 0 ){
  			v2.pb(-x);
  			p2 += -x;
  		}
  		else{
  			v1.pb(x);
  			p1 += x;
  		}
  		if ( i == n - 1 ){
  			if ( x < 0 ){
  				lasttrick = 2;
  			}
  			else{
  				lasttrick = 1;
  			}
  		}
  	}
  	if ( p1 > p2 ){
  		cout << "first" << "\n";
  		return 0;
  	}
  	else if (p1 < p2){
  		cout << "second" << "\n";
  		return 0;
  	}
  	else{
  		// if ( v1.sz > v2.sz ){
  		// 	cout << "first" << "\n";
  		// 	return 0;
  		// }
  		// else if ( v2.sz > v1.sz ){
  		// 	cout << "second" << "\n";
  		// 	return 0;
  		// }
  		if(1){
  			for ( i = 0 ; i < min(v1.sz, v2.sz) ; i ++ ){
  				if ( v1[i] > v2[i] ){
  					return 0 * printf("first\n");
  				}	
  				if ( v2[i] > v1[i] ){
  					return 0 * printf("second\n");
  				}
  			}
  		}
  	}
  	if ( lasttrick == 1 ){
  		return 0 * printf("first\n");
  	}
  	return 0 * printf("second\n");
}