#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define mod (long long)(998244353)

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cout << fixed << setprecision(25);

    cerr << fixed << setprecision(10);

    auto stat = std::chrono::high_resolution_clock::now();

	int t;

	int n,l,r,k;

	ll m,val;

	cin>>t;

	// t=1;

	while(t--){

		cin>>n;

		ll a[n];

		for(auto &x:a)cin>>x;

		bool isit=true;

		for(int i=0;i<n;++i){

			if(a[i]!=i+1)isit=false;

		}

		if(isit){

			cout<<"0"<<endl;

			continue;

		}

		int segs=0;

		for(int i=0;i<n;++i){

			if(a[i]==i+1)continue;

			if(segs>0){

				++segs;

				continue;

			}

			int j=i;

			while(j<n && a[j]!=j+1){

				++j;

			}

			segs=1;

			i=j;

		}

		if(segs>1){

			cout<<2<<endl;

		}

		else{

			cout<<1<<endl;

		}

	}

	return 0;

}