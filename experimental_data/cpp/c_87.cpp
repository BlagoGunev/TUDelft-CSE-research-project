#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef	long long          ll;
typedef	unsigned long long ull;
typedef	vector<bool>       vb;
typedef	vector<int>        vi;
typedef	vector<vb>         vvb;
typedef	vector<vi>         vvi;
typedef	pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int dp[100001];

int solve(int n){
	if(~dp[n]) return dp[n];

	vi grundy;
	for(int k=2;2*n-k*(k+1)>=0;k++){
		if((2*n-k*(k+1))%(2*k)==0){
			int a=(2*n-k*(k+1))/(2*k);
			int tmp=0;
// printf("n=%d, a=%d, k=%d\n",n,a,k);
			rep(i,k) tmp^=solve(a+i+1);
			grundy.pb(tmp);
		}
	}

	if(grundy.size()==0) return dp[n]=0;

	sort(all(grundy));
	grundy.erase(unique(all(grundy)),grundy.end());

	rep(i,grundy.size()) if(grundy[i]!=i) return dp[n]=i;
	return dp[n]=grundy.size();
}

int solve2(int n){
	for(int k=2;2*n-k*(k+1)>=0;k++){
		if((2*n-k*(k+1))%(2*k)==0){
			int a=(2*n-k*(k+1))/(2*k);
			int tmp=0;
			rep(i,k) tmp^=solve(a+i+1);
			if(tmp==0) return k;
		}
	}
	return -1;
}

int main(){
	memset(dp,-1,sizeof dp);

	int n; scanf("%d",&n);
	int ans=solve(n);
	if(ans==0) puts("-1");
	else       printf("%d\n",solve2(n));

	return 0;
}