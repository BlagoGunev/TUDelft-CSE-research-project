#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    int t;

	cin>>t;

	while(t--){

	    int n, k;

        cin>>n>>k;



        int a[n], b[k]={0};

        for(int i=0;i<n;i++){

            cin>>a[i];

            b[i%k] = max(a[i], b[i%k]);

        }



        int sum = 0;

        for(int i = 0;i<k;i++){

            sum+=b[i];

        }

        cout<<sum<<endl;



	}

}