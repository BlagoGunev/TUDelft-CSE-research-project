#include <bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll=long long;

const ll mod=1000000007;

void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(long long x) {cerr << x;}

void __print(unsigned x) {cerr << x;}

void __print(unsigned long x) {cerr << x;}

void __print(unsigned long long x) {cerr << x;}

void __print(float x) {cerr << x;}

void __print(double x) {cerr << x;}

void __print(long double x) {cerr << x;}

void __print(char x) {cerr << '\'' << x << '\'';}

void __print(const char *x) {cerr << '\"' << x << '\"';}

void __print(const string &x) {cerr << '\"' << x << '\"';}

void __print(bool x) {cerr << (x ? "true" : "false");}



template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

#else

#define debug(x...)

#endif



int main(){fast

    int t; cin>>t;

    while(t--){

    	int n,m; cin>>n>>m; vector<string>a(n);

    	for(int i=0;i<n;i++){

    		cin>>a[i];

		}

		vector<vector<int>>c(n+m-1);

		for(int j=0;j<n;j++){

			for(int k=0;k<m;k++){

				if(a[j][k]=='1'){

					c[k+j].push_back(k-j);

				}

			}

		}

		debug(c);

		int ans=0;

		for(int i=0;i<2;i++){

			vector<int>dp(n*m,mod);

			for(int j=i;j<n+m-1;j+=2){

				sort(c[j].begin(),c[j].end(),greater<int>());

				debug(c[j]);

				for(int x:c[j]){

					*lower_bound(dp.begin(),dp.end(),x)=x;

				}

			}

			int cal=lower_bound(dp.begin(),dp.end(),mod)-dp.begin();

			ans+=cal;

		}

		cout<<ans<<"\n";

	}

}