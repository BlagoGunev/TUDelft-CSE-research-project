#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
 
#define ll long long
#define ld long double
 
using namespace std;
 
ll N=1e9+7 ,M=31;
ll i,j,l,r,n,m,t,k,f,ma=0,mi=1e9,x,y,z,kol,x3,y3,
b[1001000], a[1001000], p[1001000], d[1010000], dp[1010000];
ll ans;
string s, s2;
vector<ll> v[1000100], v2;
 
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int q;
    cin >> q;
    while(q--) {
        cin >> n >> k >> x;
        if (x != 1) {
            cout << "YES\n";
            cout << n << endl;
            for (int i = 0; i < n; ++i) {
                cout << 1 << ' ';
            }
            cout << endl;
            continue;
        }
        if (n == 1 || k == 1 || (k == 2 && n % 2 == 1)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES\n";
            cout << n / 2 << endl;
            if (n % 2 == 1) cout << 3 << ' ';
            else cout << 2 << ' ';
            for (int i = 1; i < n / 2; ++i) {
                cout << 2 << ' ';
            }
            cout << endl;
        }
    }
    
}