#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

#define INF 1000000007ll
#define pb push_back
#define mp make_pair
#define err(x) cout<<#x<<"= "<<x<<endl;
#define rep(i,n) for(int i =0; i< n; i++)
#define ff first
#define ss second
#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define SIZE 1009
#define eps 1e-13

int n,m,s,t;
vi llist[SIZE],ds,dt,done;

int main(){
//	#ifdef ONLINE_JUDGE
//	freopen("little.in", "r" , stdin);
//	freopen("little.out", "w", stdout);
// cin.tie(false); cout.tie(false);	
//	#endif
	ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	s--;t--;
	rep(i,m){
		int a,b;
		cin>>a>>b;a--;b--;
		llist[a].pb(b);
		llist[b].pb(a);
	}
#define pb push
#define pop_front pop
	queue<int> Q;
	Q.pb(s);
	ds.assign(n,INF);
	done.assign(n,0);
//	done[s] = 1;
	ds[s] = 0;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop_front();
		if(done[v] ) continue;
		done[v] = 1;
		for(int i = 0;i < llist[v].size(); i++){
			int nxt = llist[v][i];
			Q.pb(nxt);
			ds[nxt] = min(ds[nxt], ds[v]+1);
		}
	}

	Q.pb(t);
	dt.assign(n,INF);
	done.assign(n,0);
//	done[t] = 1;
	dt[t] = 0;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop_front();
		if(done[v] ) continue;
		done[v] = 1;
		for(int i = 0;i < llist[v].size(); i++){
			int nxt = llist[v][i];
			Q.pb(nxt);
			dt[nxt] = min(dt[nxt], dt[v]+1);
		}
	}
//	cout<<
	int stor = dt[s];
//	cout<<dt[s]<<' '<<ds[t]<<endl;
	int ans = 0;
	rep(i, n){
		rep(j, n){
			if(i>=j) continue;
			if(stor<= min(dt[i] +ds[j] +1 , ds[i]+dt[j]+1)){
				ans++;
			//	cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans-m<<endl;
	return 0;
};