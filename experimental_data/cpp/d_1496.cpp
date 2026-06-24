//#define GLIBCXX_DEBUG

#pragma GCC optimize("O3")



#include<bits/stdc++.h>

using namespace std;



//TEMPLATE ZONE--------------------------------------------------------------------



#define int long long

//#define double long double



typedef long long ll;typedef long double ld;

typedef vector<int> vi;typedef pair<int, int> pii;

// typedef vector<ll> vi;typedef pair<ll, ll> pii;



//DEV ZONE-------------------------------------------------------------------------

const int MAXN = 100000;

const ll inf = 2e18;

void run_case(){

	int n;

	cin>> n;

	vi v(n);

	for(int& i : v)cin >> i;

	int cb = 0;

	int p = v[0];

	int ml = 0;

	int mb1 = -1;

	int mb2 = -1;

	int cntm1 = 0;

	int cntm2 = 0;

	for(int i = 1; i <= n; i++){

		if(i==n||v[i] < p){

			int cl = i - cb;

			if(cl > ml){

				ml = cl;

				mb1 = i-1;

				cntm1=1; 

			}else if(cl==ml){

				cntm1++;

			}

			if(i!=n)

			p = v[i];

			cb = i;

		}else{

			// cb=i;

			p=v[i];

		}

	}

	cb = 0;

	p = v[0];

	for(int i = 1; i <= n; i++){

		if(i==n||v[i] > p){

			int cl = i - cb;

			if(cl > ml){

				ml = cl;

				mb2 = cb;

				cntm2=1; 

				cntm1=0; 

			}else if(cl==ml){

				cntm2++;

				mb2=cb;

			}

			if(i!=n)

			p = v[i];

			cb  =i;

		}else{

			// cb = i;

			p=v[i];

		}

	}

	// cout << ml << ' '<< mb1 << ' '<<mb2<<' '<< cntm1<< ' ' <<cntm2;

	if(cntm1<=1&& cntm2<=1 && mb2!=0&&mb1!=n-1&& ml%2==1){

		if(cntm1==1&&cntm2==1){

			if(mb1 != mb2){

				cout<<"0\n";

				return;

			}else{

				cout << "1\n";

			}

		}else{

		cout << "0\n";

		}

	}else{

		cout << "0\n";

	}

}



signed main(){

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	int tt=1;

	// cin >> tt;

	while(tt--){

		run_case();

	}

}