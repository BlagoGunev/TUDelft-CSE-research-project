#include <bits/stdc++.h>
#define int long long
#define f first
#define s second


using namespace std;

int solve()
{
    int n,k;
    cin >> n >> k;
    vector <int> a, b;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if(x > 0)
            a.push_back(x);
        if(x < 0)
            b.push_back(x);
    }
    if(a.size() == 0 && b.size() == 0)
        return 0;
    int ans = 0;
    if(a.size() > 0)sort(a.begin(), a.end());
    if(b.size() > 0)sort(b.begin(), b.end());
    if(a.size() > 0)reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i += k){
        ans = ans + 2*a[i];
    }
    for(int i = 0; i < b.size(); i += k){
        ans = ans - 2*b[i];
    }
    if(a.size() == 0)ans += b[0];
    else if(b.size() == 0)ans -= a[0];
    else
        ans = ans - max(-b[0], a[0]);
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}