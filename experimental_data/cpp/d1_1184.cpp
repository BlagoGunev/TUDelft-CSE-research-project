#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
 #define mod 1000000007
 const int N=100005;
 const int inf=1e18;
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n,k,m,t;
	cin>>n>>k>>m>>t;
	int cc=n;
	int cp=k;
	while(t--){
		int b;
		cin>>b;
		int i;
		cin>>i;
		if(b==1){
			if(cp<i){
				cc++;
			}else{
				cp++;
				cc++;
				if(cc>m){
					cc=m;
				}
			}
		}else{
			if(cp<=i){
				cc=i;
			}else{
				cp=cp-i;
				cc=cc-i;
			}
		}
		cout<<cc<<" "<<cp<<"\n";
	}
	







	
	
return 0;	
}