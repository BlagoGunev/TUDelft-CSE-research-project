#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ff first
#define ss second
typedef long long ll;
typedef long double ld;

void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i=0; i<n; i++){
        if (s[i]=='B')k--;
    }
    if (k==0) cout << 0;
    if (k>0){
        cout << 1 << "\n";
        for (int i=0; i<n; i++){
            if (s[i]!='B')k--;
            if (k==0){
                cout << i+1 << " B";
                return;
            }
        }
    } else if(k<0) {
        cout << 1 << "\n";
        for (int i=0; i<n; i++){
            if (s[i]=='B')k++;
            if (k==0){
                cout << i+1 << " A";
                return;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t=1; cin>>t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}