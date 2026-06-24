#include <bits/stdc++.h>

using namespace std;

#define int long long



int32_t main(){

	ios_base::sync_with_stdio(false);

 	cin.tie(NULL);cout.tie(NULL);

	int t;cin>>t;

	while(t--){

		int n;cin>>n;

		vector<int>a(n);

		for(int i=0;i<n;i++)cin>>a[i];

		set<int>st;

		int ans=n;

		st.insert(0);

		int z=0;

		for(int i=0;i<n;i++){

            z=z^a[i];

			if(st.find(z)!=st.end()){

				ans--;

                st.clear();

			}

			st.insert(z);

		}

		cout<<ans<<'\n';

	}

}