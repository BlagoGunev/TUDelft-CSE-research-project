#include <iostream>

using namespace std;

#define ll unsigned long long

int main(){

	ll t, x, y, a, b;

	cin>>t;

	while(t--){

		cin>>x >>y>>a>>b;

		ll m, f, s, init, secT,sec;

		f= x*a + y*a;

		m=min(x, y);

		s=m*b;	

		secT=max(x,y)-m;

		sec = (secT*a)+s;

		ll ans =min(f,sec);

		cout<<ans<<endl;

		

		}

		

	}