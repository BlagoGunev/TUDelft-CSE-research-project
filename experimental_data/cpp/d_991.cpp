#include<bits/stdc++.h>
using namespace std;

#define MAX 100009
#define ll long long
#define MOD 1000000007
#define fc freopen("inp.txt","r",stdin)

int dp[109][4];
char str[2][109];

// 0 -> top avail
// 1 -> bottom avail
// 2 -> both avail
// 3 -> none avail

int solve(int i,int ch,int n){
	if(i==n){
		return 0;
	}
	if(dp[i][ch]!=-1) return dp[i][ch];
	
	if(str[0][i]=='X'&&str[1][i]=='X'){
		return dp[i][ch]=solve(i+1,3,n);
	}
	else if(str[0][i]=='X'||str[1][i]=='X'){
		int x=INT_MIN;
		// leave
		if(str[0][i]=='X'){
			x=max(x,solve(i+1,1,n));
		}
		if(str[1][i]=='X'){
			x=max(x,solve(i+1,0,n));
		}
		return dp[i][ch]=x;
	}
	
	
	// put nothing
	int x1=solve(i+1,2,n);
	
	// put in the current and next if avail
	int x2=INT_MIN;
	if(i<(n-1)){
		if(str[0][i+1]=='0'){
			if(str[1][i+1]=='0') x2=max(x2,solve(i+2,1,n)+1);
			else x2=max(x2,solve(i+2,3,n)+1);
		}
		if(str[1][i+1]=='0'){
			if(str[0][i+1]=='0') x2=max(x2,solve(i+2,0,n)+1);
			else x2=max(x2,solve(i+2,3,n)+1);
		}
	}
	
	// use prev
	int x3=INT_MIN;
	if(ch!=3){
		x3=max(x3,solve(i+1,3,n)+1);
	}
	return dp[i][ch]=max(x1,max(x2,x3));
}

int main(){
	int n,i;
	for(i=0;i<2;++i){
		scanf("%s",str[i]);
	}
	n=strlen(str[0]);
	memset(dp,-1,sizeof dp);
	int ans=solve(0,3,n);
	printf("%d",ans);
	return 0;
}