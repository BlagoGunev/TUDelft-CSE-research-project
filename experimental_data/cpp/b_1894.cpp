#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ld long double  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define F first
#define S second
#define INF 1e18
#define endl "\n"
#define md 1000000007
typedef tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set; //find_by order()->iterator of indexed element,  order_of_key()-> number of elements
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}
int invmod(int a) {return a <= 1 ? a : md - (long long)(md/a) * invmod(md % a) % md;}
int log(int x,int y){int ans=0;while(x>1){x=x/y;ans++;}return ans;}
int pow1(int x,int y){int ans=1;for(int i=0;i<y;i++){ans=(ans*x)%md;}return ans%md;}

void solve(){
	// Main Code	
    map<int,int>m;
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }
    vector<pair<int,int>> v;
    for(auto p:m){
        v.pb({p.S,p.F});

    }
    if(v.size()<2){
        cout << -1 << endl;
        return;
    }
    sort(rall(v));
    if(v[1].F<2){
        cout << -1 << endl;
        return;
    }
    int c0=0,c1=0;
    for(int i=0;i<n;i++){
        if(a[i]==v[0].S){
            if(c0==0){
                cout << 1 << ' ';
                c0=1;
            }
            else cout << 2 << ' ';
        }
        else if(a[i]==v[1].S){
            if(c1==0){
                cout << 1 << ' ';
                c1=1;
            }
            else cout << 3 << ' ';
        }
        else cout << 1 << ' ';
    }
    cout << endl;
	
}

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	// cout << fixed << setprecision(10);
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}