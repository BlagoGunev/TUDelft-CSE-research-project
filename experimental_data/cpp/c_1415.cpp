#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t, i, j, n, p, k, x, y, m;
    cin >> t;
    while(t--) {
        cin >> n >> p >> k;

        string s;

        cin >> s;

        cin >> x >> y;

        vector<long long>v(n+1, 0);

        for(i=p-1; i<n; i++) v[i+1] = s[i]=='1';

        long long ans = LONG_MAX;

        for(i=p; i<=n; i++) {

            j = (i-p)*y + (v[i]==0)*x;

            m = j;

            if(i-k>=p) m = v[i-k] + (v[i]==0)*x;

            v[i] = min(j, m);

            if(i+k>n) ans = min(ans, v[i]);

        }

        cout << ans << '\n';
    }
    return 0;
}