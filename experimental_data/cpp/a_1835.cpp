#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ldb eps = 1e-14;
const ldb pi = acos(-1.0);
const int P = 998244353;
const int N = 1000005;

// int l10[10000005];
int p10[15];

void solve(){
    int A,B,C; ll k;
    cin >> A >> B >> C >> k;
    if(C < max(A,B) || C > max(A,B) + 1){
        cout << -1 << '\n';
        return;
    }
    for(int i = p10[A];i < p10[A + 1];i ++){
        int l,r;
        l = p10[C] - i;
        r = p10[C + 1] - 1 - i;
        l = max(l,p10[B]);
        r = min(r,p10[B + 1] - 1);
        if(l > r) continue;
        if(k <= (r - l + 1)){
            cout << i << " + " << l + k - 1 << " = " << i + l + k - 1 << '\n';
            return;
        }
        else k -= (r - l + 1);
    }
    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    int TC;
    p10[1] = 1; for(int i = 2;i <= 9;i ++) p10[i] = 10 * p10[i - 1];
    // l10[0] = 0; for(int i = 1;i <= 10000000;i ++) l10[i] = l10[i / 10] + 1;
    cin >> TC;
    while(TC --){
        solve();
    }
    return 0;
}