#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<long,long>PLL;
//typedef pair<pair<int,int>,pair<int,int>>node;
const int N=2e5+10;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
//不要混用输出;
ll a[N],b[N];
int dp[N];
void solve()
{
	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,0,sizeof dp);
	for(int i=n;i>=1;i--){
		if(i+a[i]>n){
			dp[i]=dp[i+1]+1;
		}else{
			dp[i]=min(dp[i+1]+1,dp[i+a[i]+1]);
		}
	}
	cout<<dp[1]<<endl;
}
/*codefo
rcesco
deforc
escode
forces
codefo*/
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		int t;cin>>t;
	while(t--){
		 solve();
	}
    return 0;
}