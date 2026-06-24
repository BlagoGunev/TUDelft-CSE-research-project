#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

using namespace std;

const int inf=0x3f3f3f3f;

const int N=2e3+100;

const int Num=10;

const string str[]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};

int val[N][Num],dp[N][N];

void handle(int id){

	string s;cin>>s;

	for(int i=0;i<=9;i++){

		bool flag=1;int cnt=0;

		for(int j=0;j<7;j++){

			if(str[i][j]=='0'&&s[j]=='1'){flag=0;break;}

			if(str[i][j]=='1'&&s[j]=='0')cnt++;}

		if(!flag)val[id][i]=-1;

		else 	val[id][i]=cnt;

	}

}

void solve(){

	int n,k;cin>>n>>k;

	for(int i=1;i<=n;i++)handle(i);

	dp[n+1][0]=1;

	for(int i=n;i>=1;i--)

		for(int j=0;j<=9;j++){

			if(val[i][j]==-1)continue;

			for(int t=val[i][j];t<=k;t++)

				dp[i][t]|=dp[i+1][t-val[i][j]];

	}

	if(!dp[1][k]){puts("-1");return;}

	string ans;

	for(int i=1;i<=n;i++)

		for(int j=9;j>=0;j--)

			if(val[i][j]!=-1&&k-val[i][j]>=0&&dp[i+1][k-val[i][j]]){

				k-=val[i][j],ans+=to_string(j);

				break;

	}

	cout<<ans<<'\n';

}

signed main(){IOS;

	int T=1;//scanf("%d",&T);

	while(T--)solve();

	return 0;

}