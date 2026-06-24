// Problem: C. Vlad and a Sum of Sum of Digits
// Contest: Codeforces - Codeforces Round 928 (Div. 4)
// URL: https://codeforces.com/contest/1926/problem/C
// Memory Limit: 256 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define all(x) (x).begin() , (x).end()
#define inf 1000000000
#define mod 1000000007

void dbg(){
	cerr << endl;
}
template<typename Head , typename... Tail>
void dbg(Head h , Tail... t){
	cerr << h << " ";
	dbg(t...);
}

#ifdef EMBI_DEBUG
#define debug(...) cerr << "(" << #__VA_ARGS__  << "): ", dbg(__VA_ARGS__)
#else 
#define debug(...)
#endif

const int max_n = 2e5 + 1;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}

int ans[max_n];

int fun(int x) {
	int sum = 0;
	while (x) {
		sum += x%10;
		x /= 10;
	}
	return sum;
}

void solve(){
	int n;
	cin >> n;
	
	cout << ans[n] << "\n";
}
signed main(){
    for (int i = 1 ; i < max_n ; i++) {
    	ans[i] = ans[i-1] + fun(i);
    }
    int t = 1;
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        solve();
    }
}