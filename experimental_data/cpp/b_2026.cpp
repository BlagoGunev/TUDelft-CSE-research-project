#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int long long
const int N = 3e5 + 10;
int a_list[N];
int t;

bool is_possible(int n, const vector<int> &a, int k) {
    int count = 0;
    int i = 0;
    while (i < n - 1) {
        if (a[i + 1] - a[i] <= k) {
            count++;
            i += 2;
        }
        else {
            i += 1;
        }
    }
    int required = n / 2;
    return count >= required;
}

signed main(){
    IOS;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        int left = (n % 2) ? 1 : 0;
        int right = (n > 1) ? a[n-1] - a[0] : 1;
        if(n ==1){
            right =1;
        }
        int answer = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(is_possible(n, a, mid)){
                answer = mid;
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }
        cout << answer << "\n";
    }
}