#include<bits/stdc++.h>

using namespace std;



long long n,k,T,a[200010];



long long gcd(long long a,long long b) {

	return b==0?abs(a):gcd(b,a%b);

}



void solve() {

	cin>>n>>k;

	for(int i=1;i<=n;i++) cin>>a[i];

	sort(a+1,a+n+1);

	long long d=0;

	for(int i=1;i<=n;i++) {

		if(a[i]==k) {

			cout<<"YES"<<'\n';

			return;

		}

	}

	for(int i=2;i<=n;i++) {

		d=gcd(a[i]-a[i-1],d);

	}

	if(d==1) {

		cout<<"YES"<<'\n';

		return;

	}

	for(int i=1;i<=n;i++) {

		if((k-a[i])%d==0) {

			cout<<"YES"<<'\n';

			return;

		}

	}

	cout<<"NO"<<'\n';

}

 

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0),cout.tie(0);

    cin>>T;

    while(T--) solve();

    return 0;

}