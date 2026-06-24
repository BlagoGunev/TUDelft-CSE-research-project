#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
 
#define int long long
#define intt int 
#define endl "\n"
 
using namespace std;
 
const int INF = 1e9+5;
const int MOD = 1e9+7;

void solve_case() {
    int n;
    cin >> n;
    int a[n];
    int o=0,t=0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i]==1) o++;
        else t++;
    }
    if(o%2==0) {
        int rem=t%2;
        if(rem==0) cout << "YES" << endl;
        else if(rem==1 && o>=2) cout << "YES" << endl;
        else cout << "NO" << endl;
        }
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int testcases = 1;
    cin >> testcases;
    while(testcases--) {
        solve_case();
    }
}