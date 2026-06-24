#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define sz(x) int((x).size())
#define DBG(x) cout << #x << " " << x << endl
#define forout(v) for(auto x : v) cout << x << " "
#define forin(v) for(auto &i : v) cin >> i;
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define answer(x) cout << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxll(a,b) max<long long>(a,b)
#define minll(a,b) min<long long>(a,b)
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<long long, long long>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
   	fastIO;
   	int t, n, k;
   	cin >> t;
   	string me, other;
   	while(t--){
   		cin >> n >> k;
   		cin >> me;
   		map<string,int> m;
   		for(int i = 1; i < n; i++){
   			cin >> other;
   			m[other]++;
   		}
   		cout << m[me] + 1 << endl;
   	}
    return 0;
}