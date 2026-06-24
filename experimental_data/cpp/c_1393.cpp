// IN GOD WE TRUST ♥
#include <bits/stdc++.h>


#define ll long long
#define all(a) a.begin(), a.end()
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

void Adham() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 3e5 + 1;
const ll MOD = 1e9 + 7;
const ll inf = INFINITY;
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

using namespace std;

ll mul(const ll &a, const ll &b) {
    return (a % MOD) * (b % MOD) % MOD;
}

ll add(const ll &a, const ll &b) {
    return (a + b + MOD) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n), freq, c(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        c[arr[i]]++;
    }
    ll mx = 0, cnt = 0;
    for (auto x: c) {
        if(x == 0){
            continue;
        }
        freq.push_back(x);
        if(x > mx){
            mx = x;
            cnt = 0;
        }
        else if(mx == x){
            cnt++;
        }
    }
    sort(all(freq));
    ll beg = cnt, en = n-1, res=2;
    while(beg <= en){
        ll mid = (beg+en)/2;
        vector<bool> temp(n, false);
        ll start = 0;
        bool t = true;
        for(int i = freq.size()-1; i >= 0; i--){
            if(freq[i] < freq[freq.size()-1]){
                break;
            }
            for (int j = start, k = 0; k < freq[i]; j += mid+1, k++) {
                while(j < n && temp[j]){
                    j++;
                }
                if(j >= n){
                    t = false;
                    break;
                }
                temp[j] = true;
            }
            start++;
        }
        if(t){
            res = mid;
            beg = mid+1;
        }
        else{
            en = mid-1;
        }
    }
    cout << res << endl;
}

int main() {
    Adham();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}