#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int solve(int x){
    int low = 0;
    int high = 3e9;
    while(low + 1 < high){
        int mid = (low+high)/2;
        if(mid*mid <= x){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return low;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int low = 0;
        int high = (int)2e18;
        while(low + 1 < high){
            int mid = (low+high)/2;
            int v = mid-solve(mid);
            if(v>=k){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        cout << high << '\n';
    }
    return 0;
}