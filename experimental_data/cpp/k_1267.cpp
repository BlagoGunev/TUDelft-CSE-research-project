#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define pii pair<int,int>
void miss() {
    int n;
    cin >> n;
    vector<int>mp(22);
    vector<int>ai(22,1);
    for(int i = 1; i <= 20; i++) {
        ai[i] = i * ai[i - 1];
    }
    int x = n;
    int len = 1;
    for(int i = 1; i <= 20; i++) {
        mp[x % i]++;
        x = x / i;
        len = i;
        if(!x) break;
    }
    int ans = 1;
    int sum = 0;
    int qqq = 1;
    for(int i = 0; i < len; i++) {
        qqq *= ai[mp[i]];
        sum += mp[i];
        ans = ans * sum;
        sum--;
    }
    ans = ans / qqq;
    if(mp[0]) {
        mp[0]--;
        len--;
        int qwq = 1;
        sum = 0;
        int ans1 = 1;
        for(int i = 0; i < len; i++) {
            qwq *= ai[mp[i]];
            sum += mp[i];
            ans1 *= sum;
            sum--;
        }
        ans = ans - ans1 / qwq;
    }
    cout << ans - 1 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int T = 1;
    cin >> T;
    while(T--) miss();
}