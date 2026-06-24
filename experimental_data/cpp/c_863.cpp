#include <bits/stdc++.h>

#define ll      long long int

#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
#define init(x, k) fill(all(x), k)
#define dot(x)     fixed<<setprecision(x) 
#define nfs        ios_base::sync_with_stdio(false)
#define no_step    cin.tie(NULL)

#define Max(a, b, c)   max(a, max(b, c))
#define Min(a, b, c)   min(a, min(b, c))
#define mxe(a)        *max_element(all(a))
#define mne(a)        *min_element(all(a))

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k

#define inf      INT_MAX
#define INF      LLONG_MAX

#define ff    first
#define ss    second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

II score(ll a, ll b){
	if (a==b)return {0, 0};
	if ((a==3 && b==2) || (a==2 && b==1) || (a==1 && b==3))return {1, 0};
	else return {0, 1};
}

void solve(){
	ll k, n, m;	
	cin>>k>>n>>m;
	ll A[4][4], B[4][4], visited[4][4]={0};
	map<II, pair<ll, II>> mp;
	for (ll i=1;i<=3;i++){
		for (ll j=1;j<=3;j++){
			cin>>A[i][j];
		}
	}
	for (ll i=1;i<=3;i++){
		for (ll j=1;j<=3;j++){
			cin>>B[i][j];
		}
	}
	II sc = score(n, m);
	ll sa=sc.ff, sb=sc.ss;
	ll counter = 1;
	mp[{n, m}] = {counter, {sa, sb}};
	counter++;
	visited[n][m]=1;
	//cout<<endl;
	//cout<<mp[{n, m}].ff<<" "<<mp[{n, m}].ss.ff<<" "<<mp[{n, m}].ss.ss<<endl;
	ll kk = k-1;
	ll to_process=0;
	II start;
	while(kk){
		II curr = {A[n][m], B[n][m]};
		if (visited[curr.ff][curr.ss]==0){
			visited[curr.ff][curr.ss]=1;
			sc = score(curr.ff, curr.ss);
			sa+=sc.ff, sb+=sc.ss;			
			mp[curr] = {counter, {sa, sb}};
			counter++;
			n = curr.ff, m=curr.ss;
			//cout<<mp[curr].ff<<" "<<mp[curr].ss.ff<<" "<<mp[curr].ss.ss<<endl;
		}
		else{
			auto prev = mp[curr];
			ll chain_len = counter - prev.ff;
			ll rem = k - counter;
			ll mul = rem / chain_len;
			to_process = rem % chain_len;
			II sco = prev.ss;
			sc = score(curr.ff, curr.ss);
			sa += sc.ff, sb += sc.ss;
			sa += mul*(sa-sco.ff), sb += mul*(sb-sco.ss);
			start = curr;
			kk--;
			kk-=mul*chain_len;
			break;
		}
		kk--;
	}
	while(to_process>0){
		II curr = {A[start.ff][start.ss], B[start.ff][start.ss]};
		sc = score(curr.ff, curr.ss);
		sa+=sc.ff, sb+=sc.ss;
		to_process--;
		start = curr;
	}
	cout<<sa<<" "<<sb<<endl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}