#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;

int C(int a, int b){
    if (a < 0 or b < 0 or a < b) return 0;
    return (a & b) == b;
}

const int maxn = 5005;
int f[maxn][maxn];

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    f[0][0] = 1;
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j <= i; j++){
            f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % 2;
        }
    }

    int T;
    cin >> T;
    while(T--){
        int k, m;
        cin >> k >> m;
        string s;
        cin >> s;
        int cnt1 = count(s.begin(), s.end(), '1');
        int ans = 0;
        for(int median = 0; median < m; median++){
            int cnt = 0;
            for(int i = 1; i <= median + 1 and i <= cnt1; i++){
                cnt ^= f[cnt1][i] * C(median, i - 1);
            }
            if (cnt) ans ^= median;
        }
        cout << ans << '\n';
    }

}