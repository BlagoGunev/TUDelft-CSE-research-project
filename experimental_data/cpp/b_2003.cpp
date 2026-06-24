/**
 * author: guestxd
 * time: 2024-08-25 22:38:50
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,a[200005]={};

void wk() {
    cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+n+1);
    cout << a[n/2+1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef TEST_TIME
    int st=clock();
    #endif

    int t;
    cin >> t;
    while(t--) wk();
    
    #ifdef TEST_TIME
    cout << "\ntime: " << clock()-st << "ms";
    #endif

    return 0;
}