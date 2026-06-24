#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int) (a).size())

#define L(i, j, k) for(int i = (j); i <= (k); ++i)

#define R(i, j, k) for(int i = (j); i >= (k); --i)

#define endl '\n'

#define pb push_back

#define all(x) (x).begin(),(x).end()

typedef long long ll;

const int N=2e5;

ll gcd (ll a, ll b) {

    if (b == 0)

        return a;

    else

        return gcd (b, a % b);

}

void solve(){

	ll a;

	cin>>a;

	string s;

	cin>>s;

	bool t=0;

	for(int i=0;i<s.size();i++){

		if(s[i]!='9') t=1;

	}

	cout<<a*(s.size()-ll(t))<<"\n";

}

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    ll t;

    cin>>t;

    while(t--){

    	solve();

	}

}