#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

struct timer{
	time_t start;
	timer(){start=clock();}
	~timer(){cerr<<1.*(clock()-start)/CLOCKS_PER_SEC<<" secs"<<endl;}
};

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int dp[111][4][4];
int ok[111][2];
int r,n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>r>>n;
	rep2(i,1,r+1){
		ok[i][0]=ok[i][1]=1;
	}
	rep(i,n){
		int R,C;
		cin>>R>>C;
		C--;
		ok[R][C]=0;
		ok[R-1][!C]=0;
		ok[R][!C]=0;
		ok[R+1][!C]=0;
	}
	
	rep2(mask1,1,4)rep2(mask2,1,4){
		dp[1][mask1][mask2]=(mask1&mask2 ? 1:0);
	}
	
	dp[2][1][1]=0;
	dp[2][1][2]=1;
	dp[2][1][3]=2;
	dp[2][2][1]=1;
	dp[2][2][2]=0;
	dp[2][2][3]=2;
	dp[2][3][1]=2;
	dp[2][3][2]=2;
	dp[2][3][3]=0;
	
	rep2(i,3,r+1)rep2(mask1,1,4)rep2(mask2,1,4){
		int g[222]={};
		// 0,0
		if(mask1>>0&1){
			g[dp[i-1][1][mask2]]=1;
		}
		// 0,1
		if(mask1>>1&1){
			g[dp[i-1][2][mask2]]=1;
		}
		// i-1,0
		if(mask2>>0&1){
			g[dp[i-1][mask1][1]]=1;
		}
		// i-1,1
		if(mask2>>1&1){
			g[dp[i-1][mask1][2]]=1;
		}
		
		if(i==3){
			// 1,0
			g[dp[1][mask1&~2][mask1&~2] ^ dp[1][mask2&~2][mask2&~2]]=1;
			// 1,1
			g[dp[1][mask1&~1][mask1&~1] ^ dp[1][mask2&~1][mask2&~1]]=1;
		}
		else{
			// 1,0
			g[dp[1][mask1&~2][mask1&~2] ^ dp[i-2][1][mask2]]=1;
			// 1,1
			g[dp[1][mask1&~1][mask1&~1] ^ dp[i-2][2][mask2]]=1;
			// i-1,0
			g[dp[i-2][mask1][1] ^ dp[1][mask2&~2][mask2&~2]]=1;
			// i-1,1
			g[dp[i-2][mask1][2] ^ dp[1][mask2&~1][mask2&~1]]=1;
			
			rep2(j,2,i-2){
				// j,0
				g[dp[j][mask1][1] ^ dp[i-1-j][1][mask2]]=1;
				// j,1
				g[dp[j][mask1][2] ^ dp[i-1-j][2][mask2]]=1;
			}
		}
		
		while(g[dp[i][mask1][mask2]])dp[i][mask1][mask2]++;
		
		/*if(i==3){
			cout<<mask1<<" "<<mask2<<" :\n";
			rep(j,7)cout<<g[j]<<" ";cout<<" -> "<<dp[i][mask1][mask2]<<endl;
		}*/
	}
	
	int Xor=0;
	vi v;
	rep(i,r+2){
		int mask=ok[i][0]<<0 | ok[i][1]<<1;
		if(mask==0){
			if(sz(v)){
				int mask1=v[0];
				int mask2=v[sz(v)-1];
				/*
				rep(j,sz(v))cout<<v[j]<<" ";cout<<":"<<endl;
				cout<<sz(v)<<" "<<mask1<<" "<<mask2<<endl;
				//*/
				Xor ^= dp[sz(v)][mask1][mask2];
				v.clear();
			}
		}else{
			v.pb(mask);
		}
	}
	cout<<(Xor?"WIN":"LOSE");
}