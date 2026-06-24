// ॐ वासुदेवाय नमः
#include <bits/stdc++.h>
#include <iostream>
#define pb emplace_back
#define int long long
#define vi vector<int>
#define vll vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define ull unsigned long long
#define ui unsigned int
#define vp(a, b) vector<pair<a, b>>
#define fo(n, i, start) for (int i = start; i <= n; i++)
#define full(n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
using namespace std;
const int M = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define en cout << endl;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int B;
    cin >> B;
    if(n == 1){
        cout << "YES" << "\n";
        return;
    }
    bool prev0 = true;
    bool prev1 = true;
    for (int i = 1; i < n; i++){
        bool curr0 = false, curr1 = false;
        if(prev0 && (a[i-1] <= a[i]))
            curr0 = true;
        if(prev1 && ((B - a[i-1]) <= a[i]))
            curr0 = true;
        if(prev0 && (a[i-1] <= (B - a[i])))
            curr1 = true;
        if(prev1 && ((B - a[i-1]) <= (B - a[i])))
            curr1 = true;
        prev0 = curr0;
        prev1 = curr1;
    }
    cout << ((prev0 || prev1) ? "YES" : "NO") << "\n";
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}