/*------------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    int p[n+1];
    p[1] = 0;

    int a;
    for(int i=2; i<=n; i++) {
        cin >> a;
        p[i] = a;
    }

    int c[n+1];
    c[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> c[i];
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(c[p[i]] != c[i])
            ans++;
    }

    cout << ans;
    return 0;
}