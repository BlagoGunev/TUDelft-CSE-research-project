#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sort(a) sort(a.begin(), a.end())
#define p_b(i) push_back(i)


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L'){
                a[i] = i;
            }
            else{
                a[i] = n - 1 - i;
            }
            sum += a[i];
        }
        sort(a);
        for(int i = 0; i < n; i++){
            if(n - 1 - 2 * a[i] > 0){
                sum += n - 1 - 2 * a[i];
            }
            cout << sum << " ";
        }
    }

    return 0;
}