#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

ll n[100002], s[100002], l[100002], r[100002];
vector<ll> a[100002], c[100002];
vector<int> wh[100002];
ll pl[100002], mn[100002], ans[100002];

void solve() {
    int m; cin >> m;
    for(int i=1;i<=m;i++) {
        a[i].clear(); c[i].clear();
    }
    ll N = 0, L = 0, R = 0;
    for(int i=1;i<=m;i++) {
        cin >> n[i] >> l[i] >> r[i];
        s[i] = 0;
        N += n[i];
        L += l[i];
        R += r[i];
        a[i].resize(n[i]);
        c[i].resize(n[i]);
        for(int j=0;j<n[i];j++) {
            cin >> a[i][j];
        }
        for(int j=0;j<n[i];j++) {
            cin >> c[i][j];
            s[i] += c[i][j];
        }
    }
    
    if(R - L + 1 > N) {
        cout << "0\n";
        return;
    }
    
    N = R - L + 1;
    
    for(int i=0;i<N;i++) {
        wh[i].clear();
        mn[i] = R-L;
        pl[i] = 0;
    }
    
    for(int i=1;i<=m;i++) {
        for(int j=0;j<n[i];j++) {
            if(L <= a[i][j] && a[i][j] <= R) {
                ll tmp = a[i][j] - L;
                mn[tmp] -= r[i] - l[i];
                
                if(s[i] - r[i] >= c[i][j]) mn[tmp] += r[i] - l[i];
                else if(s[i] - l[i] < c[i][j]) pl[tmp] += l[i] + c[i][j] - s[i];
                else mn[tmp] += s[i] - c[i][j] - l[i];
            }
        }
    }
    
    ll ret = 1e18;
    for(int i=0;i<N;i++) {
        if(mn[i] >= i) ret = min(ret, pl[i]);
        else ret = min(ret, pl[i] + i - mn[i]);
    }
    cout << ret << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}