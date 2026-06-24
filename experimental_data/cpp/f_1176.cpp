#include <string.h>
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stdlib.h>    
#include <time.h> 
#include <stack>
#include <queue>
#include <set>

#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define frr(i,a,b) for(int i = a; i > b; --i)
#define pb push_back
#define sf scanf

#define pf printf
#define mp make_pair

using namespace std;

const int INF = 1<<29;
const int N = 300000;

ll dp[N][20];

int main() {
	_clr(dp);
	int m;
	sf("%d",&m);
	for(int t = 0; t < m; ++t) {
		vector<ll> g[4];
		int n;
		sf("%d",&n);
		fr(i,0,n) {
			int c,d;
			sf("%d%d",&c,&d);
			g[c].pb(d);
		}
		for(int i = 1; i <=3; ++i) {
			sort(g[i].begin(), g[i].end(), greater<ll>());
		}
		map<int,vector<pair<ll,ll>>>ft;
		if(g[3].size()>0) {
			ft[1].pb(mp(g[3][0],g[3][0]));
		}

		for(int i = 0; i <=min(3,(int)g[1].size());++i) {
			for(int j = 0; j <=min(3,(int)g[2].size()); ++j) {
				if(i*1+j*2<=3) {
					ll max_c = 0;
					ll ret = 0;
					for(int k = 0; k<i;++k) {
						ret += g[1][k];
						max_c = max(max_c, g[1][k]);
					}
					for(int k = 0; k<j;++k) {
						ret += g[2][k];
						max_c = max(max_c, g[2][k]);
					}
					ft[i+j].pb(mp(ret,max_c));
				}
			}
		}
		if(t==0) {
			for(auto it : ft) {
				sort(it.second.begin(), it.second.end(), greater<pair<ll,ll>>());
				dp[t][it.first] = it.second.begin()->first;
			}
		}
		else {
			for(auto it : ft) {
				sort(it.second.begin(), it.second.end(), greater<pair<ll,ll>>());
				int car_num = it.first;
				ll max_v = it.second.begin()->first;
				ll max_c = it.second.begin()->second;
				for(int i = 0; i < 10; ++i) {
					if(dp[t-1][i]>=0) {
						if(i+car_num>=10) {
							dp[t][(i+car_num)%10] = max(dp[t][(i+car_num)%10], dp[t-1][i]+max_v+max_c);
						}
						else {
							dp[t][(i+car_num)%10] = max(dp[t][(i+car_num)%10], dp[t-1][i]+max_v);
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < 10; ++i) {
		if(dp[m-1][i]>=0) {
			ans = max(ans, dp[m-1][i]);
		}
	}
	cout<<ans<<endl;
}