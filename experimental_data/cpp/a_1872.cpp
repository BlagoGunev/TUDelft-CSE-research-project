#include <bits/stdc++.h>

using namespace std;

#define sz size()
#define yes cout << "YES"
#define no cout << "NO"
#define str string
#define ll long long
#define ull unsigned ll
#define uint unsigned int
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define vc vector
#define vci vector<int>
#define vcll vector<ll>
#define vcc vector<char>
#define vcstr vector<str>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define CINA(a, n) for (int i = 0; i < n; i++) cin >> a[i]
#define BEA(a) a.begin(), a.end()

void solve() {
    
    int a, b, c; cin >> a >> b >> c;
    
    double ans = (double)(abs(a - b))/(c * 2);
    
    if (a == b) cout << 0;
    
    else cout << ceil(ans);
    
    cout << endl;
    
}

int main() {

int t; cin >> t;

while (t--) solve();

return 0;

}