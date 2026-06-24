#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ULL = unsigned long long;
const int N = 40004000;
const int MAXN = 2e5 + 50;
const ll MOD = 1e9 + 7;
const ll inf = 1e9 + 7;
mt19937_64 rnd(time(0));

void solve(){
	int n, k;
	cin >> n >> k;
	int ans = (n + k - 3) / (k - 1);
	cout << ans << endl;
} 
	
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << setprecision(15);
	int t = 1;
	cin >> t;
	while(t--) solve();
    return 0;
}