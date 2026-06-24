#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define mk make_pair
#define pb push_back
#define f first
#define s second
using namespace std;
// using namespace __gnu_pbds;

void compile(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
const int N = 2e5 + 10;



void solve(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++) {
        cin >> arr[i];
    }
    int vis[n + 1] = {0};
    for(int i=0 ; i<n ; i++){
        if(vis[arr[i]]) continue;
        cout << arr[i] << " ";
        vis[arr[i]] = 1;
    }
    for(int i=1 ; i<=n ; i++) {
        if(!vis[i]) cout << i << " ";
    }
    cout << endl;


}

int main() {

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    

    return 0;
}