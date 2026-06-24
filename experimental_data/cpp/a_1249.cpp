#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll int t;
	cin>>t;
	while(t--){
		ll int n;
		cin>>n;
		ll int a[n];
		for(ll int i=0;i<n;i++)cin>>a[i];
		ll int flag = 0;
		for(ll int i=0;i<n;i++){
			for(ll int j=i+1;j<n;j++){
				if(abs(a[i]-a[j])==1){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1)cout<<2<<endl;
		else cout<<1<<endl;
	}
}