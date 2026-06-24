// LUOGU_RID: 154723901
#include <bits/stdc++.h>

using namespace std;

// #define int long long 

#define draw() return cout<<"Draw\n", void()
#define alice() return cout<<"Alice\n", void()
#define bob() return cout<<"Bob\n", void()

int n, m, xa, ya, xb, yb;

void solve() {
    cin>>n>>m>>xa>>ya>>xb>>yb;
    if (xa>=xb || abs(ya-yb)>abs(xa-xb)) draw();
    int s=abs(xa-xb), fir=(s+1)/2, sec=s-fir;
    int la=max(1,ya-fir), ra=min(m,ya+fir);
    int lb=max(1,yb-sec), rb=min(m,yb+sec);
    if (s&1) {
        if (la<=lb && rb<=ra) alice();
        draw();
    }
    else {
        if (lb<=la && ra<=rb) bob();
        draw();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin>>T;
    while (T--) solve();
    
}