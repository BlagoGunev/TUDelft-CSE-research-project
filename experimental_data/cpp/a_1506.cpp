#include<bits/stdc++.h>

using namespace std;

#define int long long

#define pb push_back

void solve(){

	int n,m,k;

    cin>>n>>m>>k;

    int rem = k%n;

    int quo =(k+(n-1))/n;

    if(rem==0)

     rem = n;

    rem--;

    //cout<<rem<<" "<< quo<<'\n';

    cout<<(m*rem)+(quo)<<"\n";

}

int32_t main(){

	ios_base::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	int t=1;

	cin>>t;

	while(t--){

		solve();

	}

	return 0;

}