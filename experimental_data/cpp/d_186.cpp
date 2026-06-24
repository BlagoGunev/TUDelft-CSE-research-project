#include<bits/stdc++.h>

#define ll          long long int

#define pb          push_back

#define mp          make_pair

#define pii         pair<int,int>

#define vi          vector<ll>

#define Max(a,b)    ((a)>(b)?(a):(b))

#define Min(a,b)    ((a)<(b)?(a):(b))

#define rep(i,a,b)  for (__typeof((b)) i=(a);i<(b);i+=1)

#define all(a)      (a).begin(),(a).end()

#define F           first

#define S           second

#define sz(x)       (int)x.size()

#define hell        1000000007

#define endl        '\n'

#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';

using namespace std;

ll expo(ll base, ll exponent, ll mod) {								//return base^exponent modulo modulus

    ll ans = 1;

    while(exponent !=0 ) {

        if((exponent&1) == 1) {

            ans = ans*base ;

            ans = ans%mod;

        }

        base = base*base;

        base %= mod;

        exponent>>= 1;

    }

    return ans;

}

void solve(){

    int S,a,b,c;

    cin>>S>>a>>b>>c;

    cout.precision(15);

    if(a==0 && b==0 && c==0){

        cout<<0<<" "<<0<<" "<<0;

        return;

    }

    else if(a==0 && b==0){

        cout<<0<<" "<<0<<" "<<S;

        return;

    }

    else if(a==0 && c==0){

        cout<<0<<" "<<S<<" "<<0;

        return;

    }

    else if(b==0 && c==0){

        cout<<S<<" "<<0<<" "<<0;

        return;

    }

    else if(a==0){

        cout<<0<<" "<<(long double)S/(b+c)*b<<" "<<(long double)S/(b+c)*c;

        return;

    }

    else if(b==0){

        cout<<(long double)S/(a+c)*a<<" "<<0<<" "<<(long double)S/(a+c)*c;

        return;

    }

    else if(c==0){

        cout<<(long double)S/(b+a)*a<<" "<<(long double)S/(b+a)*b<<" "<<0;

        return;

    }

    else{

        cout<<(long double)S/(b+c+a)*a<<" "<<(long double)S/(b+c+a)*b<<" "<<(long double)S/(b+c+a)*c;

        return;

    }

}



int main(){

	int t=1;

//	cin>>t;

	while(t--){

		solve();

	}

	return 0;

}