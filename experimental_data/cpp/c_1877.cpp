#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define mk make_pair
#define N 100009
using namespace std;
int t,n,m,k;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		if(k>3){cout<<0<<endl;continue;}
		if(k==1){
			cout<<1<<endl;
			continue;
		}
		if(k==2){
			cout<<min(n-1,m)+m/n<<endl;
		}
		else cout<<m-(min(n-1,m)+m/n)<<endl;
	}
	return 0;
}