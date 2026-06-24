#include <bits/stdc++.h>

using namespace std;



#ifdef RAWAL 

    #include <E:\Collections\debug.h> 

#endif



#define int long long int

  

void solve() {

    string s; cin >> s;

    

    int sum = 0;

    for (auto c : s) {

        sum += c - 'a' + 1;

    }

    

    int alice = sum;

    

    if (s.length() % 2 == 1) {

        alice -= min(s[0], s.back()) - 'a' + 1;

    }

    

    int bob = sum - alice;

    

    if (alice > bob) {

        cout << "Alice " << alice - bob << "\n";

    } else {

        cout << "Bob " << bob - alice << "\n";

    }

}





signed main(){

    ios_base::sync_with_stdio(false); 

    cin.tie(nullptr);

    

    int t; cin >> t;

    while(t--) solve();

}