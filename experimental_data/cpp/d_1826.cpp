#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &it : v) cin >> it;
        vector<int> vec1(n) , vec2(n);
        for(int i = 0 ; i < n; i++){
            vec1[i] = v[i] + i;
            vec2[i] = v[i] - i;
        }
        for(int i = 1; i < n ; i++){
            vec1[i] = max(vec1[i] , vec1[i-1]);
        }
        for(int i = n-2 ; i >=0 ; i--){
            vec2[i] = max(vec2[i] , vec2[i+1]);
        }
        int res = 0;
        for(int i = 1 ; i < n-1 ; i++){
            res = max(res , v[i] + vec1[i-1] + vec2[i+1]);
        }
        cout << res << endl;
    }
}