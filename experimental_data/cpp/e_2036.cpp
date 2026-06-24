// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vc vector<char>
#define vb vector<bool>
#define mii map<int,int>
#define f0r(i,n) for(int i=0;i<n;i++)
#define FOR(i,k,n) for(int i=k;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define in(a) int a; cin>>a
#define in2(a,b) int a,b; cin>>a>>b
#define in3(a,b,c) int a,b,c; cin>>a>>b>>c
#define in4(a,b,c,d) int a,b,c,d; cin>>a>>b>>c>>d
#define vin(v,n); vi v(n); f0r(i,n){cin>>v[i];}
#define out(a) cout<<a<<'\n'
#define out2(a,b) cout<<a<<' '<<b<<'\n'
#define out3(a,b,c) cout<<a<<' '<<b<<' '<<c<<'\n'
#define out4(a,b,c,d) cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n'
#define vout(v) for(auto u : v){cout<<u<<' ';} cout<<'\n'
#define dout(a) cout<<a<<' '<<#a<<'\n'
#define dout2(a,b) cout<<a<<' '<<#a<<' '<<b<<' '<<#b<<'\n'
#define yn(x); if(x){cout<<"YES"<<'\n';}else{cout<<"NO"<<'\n';}
const int leg = 1e9 + 7;
const int mod = 998244353;
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin(".in");
	//ofstream cout(".out");
	in3(n,k,q);
	int grid[n][k];
	f0r(i,n)f0r(j,k)cin>>grid[i][j];
	FOR(i, 1, n){
		f0r(j, k){
			grid[i][j] = (grid[i-1][j] | grid[i][j]);
		}
	}
	while(q--){
		int m;
		cin>>m;
		int l = 0;
		int r = n-1;
		while(m--){
			int a, b;
			bool x;
			char c;
			cin>>a>>c>>b;
			if(c == '>')x = 1;
			else x = 0;
			a--;
			if(x){
				int lo = 0;
				int hi = n;
				while(lo < hi){
					int mid = lo + (hi - lo)/2;
					if(grid[mid][a] > b){
						hi = mid;
					}
					else{
						lo = mid + 1;
					}
				}
				l = max(l, lo);
			}
			else{
				int lo = -1;
				int hi = n-1;
				while(lo < hi){
					int mid = lo + (hi - lo + 1)/2;
					if(grid[mid][a] < b){
						lo = mid;
					}
					else{
						hi = mid - 1;
					}
				}
				r = min(r, lo);
			}
			
			
		}
		if(l > r)out(-1);
		else out(l+1);
	}
}