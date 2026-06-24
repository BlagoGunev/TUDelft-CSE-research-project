#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <cstdio>

#include <fstream>

#include <algorithm>

#include <cmath>

#include <deque>

#include <vector>

#include <queue>

#include <string>

#include <cstring>

#include <map>

#include <stack>

#include <set>

#include<bitset>

#define read(type) readInt<type>()

#define nl "\n"

#define pb push_back

#define mk make_pair

#define pii pair<int, int>

#define pll pair<ll, ll>

#define fi first

#define se second

#define vi vector<int>

#define vl vector<ll>

#define vii vector<pii>

#define vll vector<pll>

#define sl set <ll>

#define msl multiset <ll>

#define mll map <ll,ll>

#define all(x) (x).begin(),(x).end()

#define FOR(i,n) for(i=0;i<(n);i++)

#define FORFOR(i,j,n) FOR(i,n)  FOR(j,n)

#define FORtri(i,j,n) FOR(i,n)  for(j=0;j<(i+1);j++)

#define FOR1(i,n) for(i=1;i<=(n);i++)

#define FORrev(i,n) for(i=(n-1);i>=0;i--)

#define rep(i,a,b) for(i=(a);i<(b);i++)

#define rrep(i,a,b) for(i=(a);i>=(b);i--)

#define geta(a,n) for(ll i=0;i<n;i++)cin>>a[i];

#define i1(x) cin>>x

#define i2(x1,x2) cin>>x1>>x2

#define i3(x1,x2,x3) cin>>x1>>x2>>x3

#define i4(x1,x2,x3,x4) cin>>x1>>x2>>x3>>x4

#define o1(x) cout<<x<<nl

#define o2(x1,x2) cout<<x1<<" "<<x2<<nl

#define o3(x1,x2,x3) cout<<x1<<" "<<x2<<" "<<x3<<nl

#define o4(x1,x2,x3,x4) cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<nl

#define umap unordered_map

#define uset unordered_set

#define imax INT_MAX

#define imin INT_MIN

#define exp 1e9

#define sz(x) (int((x).size()))

#define pbds tree<ll, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

using namespace __gnu_pbds;

typedef long long ll;

const ll inf = 0x3f3f3f3f3f3f3f3f;

void solve() {

   int n,m;

   int sx,sy;

   int ex,ey;

   cin>>n>>m>>sx>>sy>>ex>>ey;

   int ans=0;

   int xx=1,yy=1;

   while(1){

   	 if(sx==ex||sy==ey){

   	 	cout<<ans<<endl;

   	 	return;

		}

		if(sx==n) xx=-1;

		if(sx==1) xx=1;

		if(sy==m) yy=-1;

		if(sy==1) yy=1;

		sx+=xx;

		sy+=yy;

		ans++;

   }

   

   

}

int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

    cout.tie(0);

	int t=1;

	cin>>t;

	while(t--) {

		solve();

	}

}