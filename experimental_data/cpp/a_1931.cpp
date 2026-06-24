#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,i,j,k;
    cin >> n;
    bool founded=false;
    for(i=1;i<=26;++i){
        for(j=1;j<=26;++j){
            for(k=1;k<=26;++k){
                if(i + j + k == n){
                    founded=true;
                    break;
                }
            }
            if(founded)break;
        }
        if(founded)break;
    }
    char x1=('a' + i - 1);
    char x2= ('a' + j - 1);
    char x3=('a' + k - 1);
    cout << x1 << x2 <<x3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        solve();        
    }
}