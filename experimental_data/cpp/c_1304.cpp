#include<bits/stdc++.h>

using namespace std;

#define int long long

#define cel(x,a) ((x + a - 1) / a)

#define all(v) v.begin(),v.end()

#define mod 1000000007

#define haan cout<<"YES\n";

#define na cout<<"NO\n";

#define pb push_back

#define finish if(flag){cout<<"YES\n";}else{cout<<"NO\n";}

#define start int arr[n];for(int i=0;i<n;i++){cin>>arr[i];} 

#define N 200010

#define dis(v) for(auto &x:v){cout<<x<<" ";}cout<<"\n";

#define dis2(v) for(auto &x:v){cout<<x.first<<" "<<x.second<<"\n";}

signed main() {

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

cin.tie(NULL);

int t=1;

cin>>t;

while(t--){

	int n,m;cin>>n>>m;

	int i=m,j=m;

	int prev=0;

	bool flag=true;

	while(n--){

		int a,b,c;

		cin>>a>>b>>c;

		i-=a-prev;

		j+=a-prev;

		prev=a;

		if(b>j or c<i){

			flag=false;

		}

		i=max(i,b);

		j=min(j,c);

		

	}	

	finish

}

}