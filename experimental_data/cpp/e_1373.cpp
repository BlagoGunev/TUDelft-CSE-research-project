#include<bits/stdc++.h>

using namespace std;

#define int long long

#define ll long long

#define pii pair<int,int>

#define all(v) v.begin(),v.end()

const double eps=1e-7;

const double pi=acos(-1);

//te pan

int a[20];

signed main(){

	ios::sync_with_stdio(false);cin.tie(0);

	int __;

	cin>>__;

	for(int i=1;i<=9;i++){

		a[i]=a[i+9]=i;

	}

	while(__--){

		int n,k;

		cin>>n>>k;

		int ans=9e18;

		for(int i=0;i<=9;i++){

			int s=n;

			for(int u=0;u<=k;u++){

				s-=a[u+i];

			}

			if(s<0||s%(k+1)) continue;

			int x=s/(k+1);

			int res=0;

			if(x<9) res=x;

			else{

				int t=8;

				if(i+k<=9) t=9;

				

				res=t;

				x-=t;

				int shou=x%9,mu=10;

				x-=shou;

		//		cout<<i<<':'<<t<<" "<<shou<<" "<<x<<" ";

				while(x){

					res=res+9*mu;

					x-=9;shou*=10;mu*=10;

				}

				res=shou*10+res;

			}

			ans=min(ans,res*10+i);

	//		cout<<res*10+i<<"\n";

		}

		if(ans==9e18) cout<<"-1\n";

		else cout<<ans<<"\n";

	}

	return 0;

}