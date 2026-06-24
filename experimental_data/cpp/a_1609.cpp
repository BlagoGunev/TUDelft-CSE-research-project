#include <bits/stdc++.h>

typedef long long ll;

#define vi     vector <int>

#define vll    vector <long long>

#define vs     vector <string>

#define vc     vector <char>

#define PII    pair<int,int>

#define MII    map<int,int>

#define UMII   unordered_map<int,int>

#define sz(v)  v.size()

#define all(v) v.begin(),v.end()

#define ff     first 

#define ss     second 

#define endl  "\n"

#define int    long long

using namespace std;

const int M  = 1e9+7;

const int N  = 1e5+7;

signed main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t; cin >> t;

    while(t--){

        int se{},so{};

        int n; cin >> n;

        vi v(n);

        for(int i{};i<n;i++){

            int x; cin >> x;

            if(x&1) so+=x;

            else se++;

            v[i] = x;

        }

        int pow{1};

        for(auto &i:v){

            while(i%2 == 0){

                pow*=2;

                i/=2;

            }

        }

        int sum{};

        for(auto &i:v) sum+=i;

        int ans{};int c{};

        for(int i{};i<n;i++){

            c = sum-v[i]+v[i]*pow;

            ans = max(ans,c);

        }

        cout << ans << "\n";

    }

    return 0;

}