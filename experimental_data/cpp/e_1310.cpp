#include<bits/stdc++.h>

#define ll long long

#define gmax(x,y) x=max(x,y)

#define gmin(x,y) x=min(x,y)

#define F first

#define S second

#define P pair

#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define rep(i,a,b) for(int i=a;i<b;i++)

#define V vector

#define RE return

#define ALL(a) a.begin(),a.end()

#define MP make_pair

#define PB emplace_back

#define PF push_front

#define FILL(a,b) memset(a,b,sizeof(a))

#define lwb lower_bound

#define upb upper_bound

#define lc (x<<1)

#define rc ((x<<1)|1)

#define sz(x) ((int)x.size())

using namespace std;

const int mod=998244353;

void add(int &x,int y){

	x+=y;

	if(x>=mod)x-=mod;

}

int dp[2050][2050],n,k,cnt=0;

int val[2050],len;

bool dfs(int x){

	if(len){

		V<int> now;

		FOR(i,1,len)now.PB(val[i]);

		bool f=1;reverse(ALL(now));

		rep(i,1,k-1){

			int tv=0;V<int> to;

			int s=0,tot=0;

			for(auto u:now)tot+=u;

			for(auto u:now){

				tv++;FOR(j,1,u)s+=(tot--)*tv;

			}

			tv=0;

			if(s>n){

				f=0;break;

			}

			if(i==k-2)break;

			for(auto u:now){

				++tv;

				FOR(j,1,u)to.PB(tv);

			}

			reverse(ALL(to));

			now=to;

		}

		if(f)cnt++;else RE 0;

	}

	FOR(i,x,n){

		val[++len]=i;

		bool now=dfs(i);

		--len;

		if(!now)break;

	}

	RE 1;

}

signed main(){

	ios::sync_with_stdio(0);

	cin.tie(0);

	cin>>n>>k;

	if(k==1){

		dp[0][0]=1;

		int sum=0;

		FOR(i,1,n)FOR(j,i,n){

			dp[i][j]=dp[i-1][j-1];

			add(dp[i][j],dp[i][j-i]);

			add(sum,dp[i][j]);

		}

		cout<<sum<<'\n';

	}else if(k==2){

		dp[0][0]=1;

		int ans=0;

		FOR(i,1,n)FOR(j,0,n)if(dp[i-1][j]){

			int mul=i*(i+1)/2;

			FOR(k,0,n){

				if(j+k*mul>n)break;

				add(dp[i][j+k*mul],dp[i-1][j]);

				if(k)add(ans,dp[i-1][j]);

			}

		}

		cout<<ans<<'\n';

	}else{

		dfs(1);

		cout<<cnt;

	}

	RE 0;

}