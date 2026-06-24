#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		b=min(a,b);
		c=min(a,c);
		int ans=min(a*2,b+c+d);
		cout<<ans<<"\n";
	}
}