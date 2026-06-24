#include<bits/stdc++.h>
using namespace std;
int n,k;
bool dp[1001][2002];
int II()
{
int n;
scanf("%d",&n);
return n;
}
int main(){
cin>>n>>k;
string a;
cin>>a;

dp[0][1000]=true;


for(int i=0;i<n;i++){
	for(int j=0;j<2002;j++){
		
		if(dp[i][j]==true){
			
			
			if(a[i]=='?'){
				if(j+1<1000+k||i+1==n)
			dp[i+1][j+1]=true;
			dp[i+1][j]=true;
			if(j-1>1000-k||i+1==n)
			dp[i+1][j-1]=true;
			}
			
			if(a[i]=='L')
			if(j-1>1000-k||i+1==n)
			dp[i+1][j-1]=true;

			if(a[i]=='W')
			if(j+1<1000+k||i+1==n)
			dp[i+1][j+1]=true;

			if(a[i]=='D')
			dp[i+1][j]=true;

		}
		
	}
}


if(dp[n][1000+k]==false&&dp[n][1000-k]==false)
cout<<"NO"<<endl;
else{
	if(dp[n][1000+k]==true){
	vector<char> sol;
	int bil=1000+k;
	for(int i=n;i>=1;i--){
		
		
		if(a[i-1]=='?'){
		if(dp[i-1][bil+1]==true){
		sol.push_back('L');
		bil++;
		}
		else{
			if(dp[i-1][bil-1]==true){
			sol.push_back('W');
			bil--;
			}
			else
			if(dp[i-1][bil]==true){
			sol.push_back('D');
			}
		}
		}
		if(a[i-1]=='W'){
			sol.push_back('W');
			bil--;
		}
		if(a[i-1]=='L'){
			sol.push_back('L');
		bil++;
		}
		if(a[i-1]=='D')
		sol.push_back('D');
		
	}
	for(int i=n-1;i>=0;i--)
	cout<<sol[i];
	}
	else{
	vector<char> sol;
	int bil=1000-k;
	for(int i=n;i>=1;i--){
		
		if(a[i-1]=='?'){
		if(dp[i-1][bil+1]==true){
		sol.push_back('L');
		bil++;
		}
		else{
			if(dp[i-1][bil-1]==true){
			sol.push_back('W');
			bil--;
			}
			else
			if(dp[i-1][bil]==true){
			sol.push_back('D');
			}
		}
		}
		if(a[i-1]=='W'){
			sol.push_back('W');
			bil--;
		}
		if(a[i-1]=='L'){
			sol.push_back('L');
		bil++;
		}
		if(a[i-1]=='D')
		sol.push_back('D');
		
	}
	for(int i=n-1;i>=0;i--)
	cout<<sol[i];	
	}
}

return 0;
}