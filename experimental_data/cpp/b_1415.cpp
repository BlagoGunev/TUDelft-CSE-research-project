#include <bits/stdc++.h>

typedef long long ll;

#define vi     vector <int>

#define vll    vector <long long>

#define vs     vector <string>

#define vc     vector <char>

#define PII    pair<int,int>

#define MII    map<int,int>

#define UMII   unordered_map<int,int>

#define sz(v)  (int)v.size()

#define all(v) v.begin(),v.end()

#define ff     first 

#define ss     second 

#define endl  "\n"

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t; cin >> t;

    while(t--){

        int n,k; 

        cin >> n >> k;

        vi v(n);

        set <int> st;

        for(int i{};i<n;i++){

            int x; cin >> x;

            v[i] = x;

            st.insert(x);

        }

        int ans{INT_MAX};

        for(auto &j:st){

            int c{};

            for(int i{};i<n;i){

                while(i < n && v[i] == j) i++;

                for(int l{i};l<i+k && l<n;l++){

                    if(v[l]!=j){

                        c++;

                        break;

                    }

                }

                i+=k;

            }

            ans = min(c,ans);

        }

        cout << ans << "\n";

    }

    return 0;

}