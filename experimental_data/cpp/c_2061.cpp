#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int A[500005];
int DP[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        for(i=1;i<=N;i++) cin >> A[i];
        for(i=1;i<=N;i++) DP[i] = 0;
        for(i=1;i<=N;i++) {
            A[i] = i-1 - A[i];
        }
        //for(i=1;i<=N;i++) cout <<A[i] << ' ';
        //cout <<'\n';
        A[0] = -1;
        DP[0] = 1;
        for(i=1;i<=N;i++) {
            if(i-2>=0 && A[i-2]+1 == A[i]) {
                DP[i] = (DP[i] + DP[i-2]) % p;
            }
            if(i-1 >= 0 && A[i-1]+1==A[i]) {
                DP[i] = (DP[i] + DP[i-1]) % p;
            }
        }
        int ans = (DP[N] + DP[N-1])%p;
        cout << ans << '\n';
    }
}