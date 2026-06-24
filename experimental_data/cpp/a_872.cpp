#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define mo 1000000007
 
 
 
int main()
{
	ll n,m;
	cin>>n>>m;
	ll a[n+1],b[m+1];
	int freq[10]={0};
	for(ll i=0;i<n;i++){
		cin>>a[i];
		freq[a[i]]++;


	}
	for(ll i=0;i<m;i++){
		cin>>b[i];
		freq[b[i]]++;

	}
	ll ans=0;	
	for(ll i=1;i<=9;i++){
		if(freq[i]==2){
			ans=i;
			break;
		}
	}
	if(ans==0){
		ll mina=*min_element(a,a+n);
		ll minb=*min_element(b,b+m);
		
	

		if(mina<minb){
			ans=mina*10+minb;
			//cout<<ans<<"\n";
		}
		else if(mina>minb){
			ans=minb*10+mina;
			//cout<<ans<<"\n";
		}
		else
			ans=mina;

		

	}
	cout<<ans<<"\n";


	
	
}