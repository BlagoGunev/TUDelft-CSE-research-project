#include <bits/stdc++.h>

using namespace std;



#ifdef RAWAL 

    #include <E:\Collections\debug.h> 

#endif



#define int long long int

  

void solve() {

    string s;

    cin >> s;

    

    int n = s.length();

    

    int k = set(s.begin(), s.end()).size();

    

    for (int i = 0; i < n; i++) {

        if (s[i] != s[i % k]) {

            cout << "NO\n";

            return;

        }

    }

    

    cout << "YES\n";

}



signed main(){

    ios_base::sync_with_stdio(false); 

    cin.tie(nullptr);

    

    int t; cin >> t;

    while(t--) solve();

}