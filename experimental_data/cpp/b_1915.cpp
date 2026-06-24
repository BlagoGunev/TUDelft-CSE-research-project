#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PIE 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define jada INT_MAX




  


void test_case() {
    map<char,int> mp;
    for(int i = 0 ; i < 9 ; i++){
        char x;
        cin>>x;
        mp[x]++;
    }
    for(auto it : mp){
        if(it.second == 2){
            cout<<it.first<<'\n';
            break;
        }
    }
}

int32_t main() {
     //fastio();
    cout << fixed << setprecision(10);

    //sieve();
    int t=1;
      cin >> t;
    for(int i = 1; i <= t; i++)   {         
      test_case();
    }

    return 0;
}