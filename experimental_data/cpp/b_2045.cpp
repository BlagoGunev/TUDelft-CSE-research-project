#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, d, s;
signed main(){
    cin >> n >> d >> s;
    int ans = s;
    ans = max(ans, (d/s)*s);
    for(int i = 2; i <= 10000000; i++){
        int r = min((n/i) / s * s, (d/(i-1)/s) * s) * i;
        ans = max(ans, r);
    }
    ans = max(ans, s * min(n / s, d / s + 1));
    cout << ans << '\n';
    return 0;
}