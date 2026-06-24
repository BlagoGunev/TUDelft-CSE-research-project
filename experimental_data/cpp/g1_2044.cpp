#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define ll long long
#define ld long double
#define loop(g,t) for(int g {} ; g<t ; g++)
#define loop1(g,t) for(int g {1} ; g<=t ; g++)
#define cyes cout << "YES\n"
#define cno  cout << "NO\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back

ll count_bits(ll a)
{ll count = 0; 
while (a > 0) {count++; a = (a >> 1);}
return count;
}


ll gcd(ll a, ll b){
if (b == 0 )
return a;
else
return gcd(b , a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Code starts below

    ll t{1};
    cin >> t;
    ll n;
    // string s;
    while (t--) {
        cin >> n;

        ll r[n];

        vector <ll> v1,v2;
        map <ll,ll> m;

        loop(i,n) {
            cin >> r[i];
            m[i+1] += 0;
            m[r[i]]++;
        }
        for (auto x:m){
            if (x.S == 0) v1.pb(x.F);
        }

        ll i = 2;

        while (!v1.empty()) {
            for (auto x:v1) {
                // cout << x << " " << r[x-1] << " " << i << "\n";
                m[r[x-1]]--;
                if (m[r[x-1]] == 0) v2.pb(r[x-1]);
            }
            v1 = v2;
            v2.clear();
            i++;
        }

        cout << i << "\n";
    }
}