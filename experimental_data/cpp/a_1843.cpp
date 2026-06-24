//█████████████████████████████████████████████
//██╔═══════════════════════════════════════╗██
//██║╔═══╦═╗╔═╦═══╦════╦╗══╔╦═══╦═══╗╔╗╔═══╗║██
//██║║╔═╗║║╚╝║║╔═╗╠══╗═║╚╗╔╝║╔═╗║╔═╗╠╝║║╔═╗║║██
//██║║╚══╣╔╗╔╗║║║║║║╔╝╔╩╗╚╝╔╣║║║╠╝╔╝╠╗║║║║║║║██
//██║╚══╗║║║║║║╚═╝║╔╝╔╝║╚═╔╝║║║║╠═╝╔╝║║║║║║║║██
//██║║╚═╝║║║║║║╔═╗╠╝═╚═╗║║║║║╚═╝║║╚═╦╝╚╣╚═╝║║██
//██║╚═══╩╝╚╝╚╩╝═╚╩════╝═╚╝═╚═══╩═══╩══╩═══╝║██
//██╚═══════════════════════════════════════╝██
//█████████████████████████████████████████████

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ld long double
#define str string
#define ull unsigned long long
#define fo(i,k, n) for (ll i = k; i < n; i++)
#define ln '\n'
#define vi vector <int>
#define no cout << "NO" << ln;
#define ye cout <<  "YES" << ln;

void config_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(numeric_limits<double>::max_digits10);
    cout << fixed;
}

void solve() {
    ll k;
    cin >> k;
    vi arr(k);
    fo(i,0,k) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), greater<int>());

    ll sum = 0;
    fo(i,0,k/2) {
        sum+= arr[i];
        sum-= arr[k-i-1];
    }
    cout << sum << ln;
}


int main() {
    config_io();
    
    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

  return 0;
}