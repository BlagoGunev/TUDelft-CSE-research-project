#include<bits/stdc++.h>

using namespace std;


int main(){
	int i,j,k,l,n,m;
	cin>>n>>m;
	if(n>m){ //prefix sum handles see codeforees 319 editorial prob 2
		cout<<"YES\n";
		//exit(0);
		return 0;
	}
	vector<int> a(n);
	vector<bool> dp(m,0);
	vector<bool> dp2(m,0);
	for(i=0;i<n;i++)
		cin>>a[i];
	//vector<vector<int>  > dp(n,vector<int> (m+1,0));
	
	for(i=0;i<n;i++){
		dp2[a[i]%m]=1;
		//cout<<a[i]%m<<endl;
		for(j=1;j<m;j++){
			if(dp[j])
				dp2[(j+a[i]%m)%m]=1;
		}
		dp=dp2;
	}
	if(dp[0] || dp2[0])
		cout<<"YES\n";
	else
		cout<<"NO\n";

	return 0;
}